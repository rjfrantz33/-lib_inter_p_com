#include <gtest/gtest.h>

#include "shared_memory.h"
#include "image.h"
#include "shared_memory.cpp"
#include <thread>

class SharedMemoryTest : public ::testing::Test
{
protected:
    SharedMemoryTest()
        : width_(10), height_(10), num_channels_(3),
          data_(width_ * height_ * num_channels_, 255),
          image_(data_, width_, height_, num_channels_),
          sharedMemory_("SharedMemoryTest", image_)
    {
    }

    std::size_t width_;
    std::size_t height_;
    std::size_t num_channels_;
    std::vector<int> data_;
    Image<int> image_;
    SharedMemory<int> sharedMemory_;
};

// Test constructor
TEST_F(SharedMemoryTest, ConstructorTest)
{
    // Verify that the shared memory object is created correctly
    EXPECT_NO_THROW({
        SharedMemory<int> sharedMemory("SharedMemoryTestConstructor", image_);
    });
}

// Test destructor
TEST_F(SharedMemoryTest, DestructorTest)
{
    // Verify that the shared memory object is removed correctly
    {
        SharedMemory<int> sharedMemory("SharedMemoryTestDestructor", image_);
    }
    EXPECT_FALSE(boost::interprocess::shared_memory_object::remove("SharedMemoryTestDestructor"));
}

// Write to shared memory
TEST_F(SharedMemoryTest, WriteToSharedMemoryTest)
{
    // Write the image to shared memory
    sharedMemory_.write(image_);

    // Verify that the data is written correctly
    EXPECT_EQ(sharedMemory_.read(width_, height_, num_channels_).readData(), image_.readData());
}

// Read from shared memory
TEST_F(SharedMemoryTest, ReadFromSharedMemoryTest)
{
    // Write the image to shared memory
    sharedMemory_.write(image_);

    // Read the image from shared memory
    Image<int> readImage = sharedMemory_.read(width_, height_, num_channels_);

    // Verify the dimensions and data of the read image
    EXPECT_EQ(readImage.width(), width_);
    EXPECT_EQ(readImage.height(), height_);
    EXPECT_EQ(readImage.num_channels(), num_channels_);
    EXPECT_EQ(readImage.readData(), image_.readData());
}

// Test For synchronization between write and read operations
TEST_F(SharedMemoryTest, SynchronizationTest)
{
    std::thread writer([this]()
                       {
        // Write the image to shared memory
        sharedMemory_.write(image_); });

    std::thread reader([this]()
                       {
        // Read the image from shared memory
        Image<int> readImage = sharedMemory_.read(width_, height_, num_channels_);

        // Verify the dimensions and data of the read image
        EXPECT_EQ(readImage.width(), width_);
        EXPECT_EQ(readImage.height(), height_);
        EXPECT_EQ(readImage.num_channels(), num_channels_);
        EXPECT_EQ(readImage.readData(), image_.readData()); });

    writer.join();
    reader.join();
}
