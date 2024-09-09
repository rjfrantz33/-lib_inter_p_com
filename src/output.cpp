#include <iostream>
#include "image.h"
#include "shared_memory.h"

void testImage()
{
    // Test default constructor
    auto image1 = Image<int>(3, 2, 3);
    assert(image1.width() == 3);
    assert(image1.height() == 2);
    assert(image1.num_channels() == 3);
    assert(image1.size() == 6);

    // Test constructor with custom data
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    auto image2 = Image<int>(data, 3, 2, 3);
    assert(image2.width() == 3);
    assert(image2.height() == 2);
    assert(image2.num_channels() == 3);
    assert(image2.size() == 6);
    assert(image2.readData() == data);

    // Test pixelValue functions
    image1.pixelValue(0, 0, 0) = 10;
    image1.pixelValue(1, 0, 0) = 20;
    image1.pixelValue(2, 0, 0) = 30;
    image1.pixelValue(0, 1, 1) = 40;
    image1.pixelValue(1, 1, 1) = 50;
    image1.pixelValue(2, 1, 1) = 60;

    assert(image1.pixelValue(0, 0, 0) == 10);
    assert(image1.pixelValue(1, 0, 0) == 20);
    assert(image1.pixelValue(2, 0, 0) == 30);
    assert(image1.pixelValue(0, 1, 1) == 40);
    assert(image1.pixelValue(1, 1, 1) == 50);
    assert(image1.pixelValue(2, 1, 1) == 60);

    // Test modifying pixel values using pixelValue
    auto &pixelValue = image1.pixelValue(0, 0, 0);
    assert(pixelValue == 10);
    pixelValue = 100;
    assert(image1.pixelValue(0, 0, 0) == 100);

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    testImage();
    return 0;
}