
/// @file
/// @copyright (c) Jean Frantz René
/// Implementation file for the shared memory class.

// =====================================================================
//
// =====================================================================

#include "shared_memory.h"
#include "image.h"
#include <thread> // ????????????????????????????????????

// Constructor for the SharedMemory class
template <typename T>
SharedMemory<T>::SharedMemory(const std::string &name, const Image<T> &image)
    : name_(name), shm_(boost::interprocess::open_or_create, name_.c_str(), boost::interprocess::read_write)
{
    // create shared meory
    // shm(boost::interprocess::open_or_create, name_.c_str(), boost::interprocess::read_write);

    // Calculate the size of the shared data
    std::size_t data_size = image.size() * image.num_channels();
    // Set the size of the shared memory object
    shm_.truncate(sizeof(SharedData) + data_size * sizeof(T));

    // Map the shared memory into this process
    region_ = boost::interprocess::mapped_region(shm_, boost::interprocess::read_write);

    // Get the address of the mapped region
    void *addr = region_.get_address();

    // Construct the SharedData object in the shared memory
    sharedData_ = new (addr) SharedData(data_size);
}

template <typename T>
SharedMemory<T>::~SharedMemory()
{
    // Remove the shared memory object
    boost::interprocess::shared_memory_object::remove(name_.c_str());
}

template <typename T>
void SharedMemory<T>::write(const Image<T> &image)
{
    // Lock the mutex before writing to the shared memory
    boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(sharedData_->mutex);

    // Write the image data to the shared memory
    sharedData_->data = image.readData();

    // Set the new_data flag to true
    sharedData_->new_data = true;

    // Notify the condition variable
    sharedData_->cond_var.notify_one();
}

template <typename T>
Image<T> SharedMemory<T>::read(std::size_t width, std::size_t height, std::size_t num_channels) const
{
    // Lock the mutex before reading from the shared memory
    boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(sharedData_->mutex);

    // Wait for new_data to be true
    while (!sharedData_->new_data)
    {
        // Wait on the condition variable
        sharedData_->cond_var.wait(lock);
    }

    sharedData_->new_data = false;

    return Image<T>(sharedData_->data, width, height, num_channels);
}

// Maybe not to use
// template <typename T>
// void SharedMemory<T>::setCallback(const std::function<void(const Image<T> &)> &callback)
// {
//     this->callback = callback;

//     // Start a new thread to wait for new data and call the callback function
//     std::thread([this]()
//                 {
//         while (true) {
//             Image<T> image = this->read();
//             this->callback(image);
//         } })
//         .detach();
// }
