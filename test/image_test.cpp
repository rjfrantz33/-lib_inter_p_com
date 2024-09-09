#include <gtest/gtest.h>

#include "shared_memory.h"
#include "image.h"
#include "shared_memory.cpp"
#include <thread>

class ImageTest : public ::testing::Test
{
protected:
    ImageTest() : image_(3, 2, 3) {}

    Image<int> image_;
};

// Test default constructor
TEST_F(ImageTest, DefaultConstructorTest)
{
    EXPECT_EQ(image_.width(), 3);
    EXPECT_EQ(image_.height(), 2);
    EXPECT_EQ(image_.num_channels(), 3);
    EXPECT_EQ(image_.size(), 6);
}

// Test constructor with custom data
TEST_F(ImageTest, CustomDataConstructorTest)
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    Image<int> image(data, 3, 2, 3);
    EXPECT_EQ(image.width(), 3);
    EXPECT_EQ(image.height(), 2);
    EXPECT_EQ(image.num_channels(), 3);
    EXPECT_EQ(image.size(), 6);
    EXPECT_EQ(image.readData(), data);
}

// Test readData
TEST_F(ImageTest, ReadDataTest)
{
    auto data = image_.readData();
    EXPECT_EQ(data.size(), 18);
}

// Test pixelValue
TEST_F(ImageTest, GetPixelValueTest)
{
    image_.pixelValue(0, 0, 0) = 255;
    EXPECT_EQ(image_.pixelValue(0, 0, 0), 255);
}

// Test setPixelValue method
TEST_F(ImageTest, SetPixelValueTest)
{
    image_.pixelValue(0, 0, 0) = 255;
    EXPECT_EQ(image_.pixelValue(0, 0, 0), 255);
}

// Test modifying pixel values using pixelValue
TEST_F(ImageTest, ModifyPixelValueTest)
{
    auto &pixelValue = image_.pixelValue(0, 0, 0);
    EXPECT_EQ(pixelValue, 0);
    pixelValue = 100;
    EXPECT_EQ(image_.pixelValue(0, 0, 0), 100);
}

// Test edge cases
TEST(ImageEdgeCaseTest, ZeroChannelsTest)
{
    EXPECT_DEATH({ Image<int> image(10, 10, 0); }, "Number of channels must be greater than 0");
}

TEST(ImageEdgeCaseTest, GetPixelValueOutOfBoundsTest)
{
    Image<int> image(10, 10, 3);
    EXPECT_DEATH({ image.pixelValue(10, 10, 3); }, "Index out of bounds");
}

TEST(ImageEdgeCaseTest, SetPixelValueOutOfBoundsTest)
{
    Image<int> image(10, 10, 3);
    EXPECT_DEATH({ image.pixelValue(10, 10, 3) = 255; }, "Index out of bounds");
}
