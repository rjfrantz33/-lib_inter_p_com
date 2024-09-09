
/// @file
/// @copyright (c) Jean Frantz René
/// The SharedMemory class provides an interface for reading and writing (image) data
/// to a shared memory object.

#ifndef LIB_INTER_P_COM_SRC_SHARED_MEMORY_H
#define LIB_INTER_P_COM_SRC_SHARED_MEMORY_H

#include <vector>
#include "boost/interprocess/sync/interprocess_mutex.hpp"
#include "boost/interprocess/sync/interprocess_condition.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "boost/interprocess/shared_memory_object.hpp"
#include "boost/interprocess/sync/scoped_lock.hpp"
#include "image.h"

#include <functional>

/// @brief The SharedMemory class template is designed to facilitate the sharing of image
/// data between processes using shared memory.
/// It leverages the Boost.Interprocess library to manage synchronization and shared memory operations.
///
/// @tparam T template to allow different data types for the image pixels.
/// @param name Name of the shared memory object.
/// @param shm Shared memory object.
/// @param region Mapped region of the shared memory.
/// @param sharedData Pointer to the shared data in the shared memory.
///
template <typename T>
class SharedMemory final
{
public:
    // Constructor
    SharedMemory(const std::string &name, const Image<T> &image);

    // Destructor
    ~SharedMemory();

    // Function to write an image to the shared memory
    void write(const Image<T> &image);

    // Function to read an image from the shared memory
    Image<T> read(std::size_t width, std::size_t height, std::size_t num_channels) const;

    // Function to set a callback function to be called when new data is available
    // void setCallback(const std::function<void(const Image<T> &)> &callback);

private:
    struct SharedData
    {
        SharedData(std::size_t data_size) : data(data_size), new_data(false) {}

        boost::interprocess::interprocess_mutex mutex;        // Mutex for synchronizing access to the shared memory
        boost::interprocess::interprocess_condition cond_var; // Condition variable for signaling new data
        std::vector<T> data;                                  // Vector to hold the image data
        bool new_data;                                        // Flag to indicate new data
    };

    std::string name_;
    boost::interprocess::shared_memory_object shm_;
    boost::interprocess::mapped_region region_;
    SharedData *sharedData_;
    // std::function<void(const Image<T> &)> callback; // Callback function to be called when new data is available
};

#endif // LIB_INTER_P_COM_SRC_SHARED_MEMORY_H
