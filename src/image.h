
/// @file
/// @copyright (c) Jean Frantz René

#ifndef LIB_INTER_P_COM__SRC_IMAGE_H
#define LIB_INTER_P_COM__SRC_IMAGE_H

#include <vector>
#include <cstdint>
#include <cassert>

/// @brief The Image class template in image.h is designed to represent an image with customizable data types.
/// It provides constructors for creating an image with default and custom data,
/// and various member functions to access image properties and data.
///
/// @tparam T template to allow different data types for the image pixels.
/// @param width Width of the image.
/// @param height Height of the image.
/// @param num_channels Number of channels in the image (e.g., RGB has 3 channels).
/// @param data Vector to hold the image data in a contiguous block.
///
/// @pre num_channels > 0.
/// @pre idx < data_.size().
///
template <typename T>
class Image final
{
public:
    /// Construct an image object with default data.
    Image(std::size_t width, std::size_t height, std::size_t num_channels = 1)
        : width_(width), height_(height), num_channels_(num_channels), data_(width_ * height_ * num_channels_)
    {
        /// To ensure that the image object is always constructed with a valid number of channels.
        assert(num_channels > 0 && "Number of channels must be greater than 0");
    }

    /// Constructs which allows the initialization of image object with custom data.
    Image(std::vector<T> const &data, std::size_t width, std::size_t height, std::size_t num_channels = 1)
        : width_(width), height_(height), num_channels_(num_channels), data_(data)
    {
    }

    /// Get the size of the image.
    std::size_t size() const { return width_ * height_; }

    /// Get width of the image.
    std::size_t width() const { return width_; }

    /// Get height of the image.
    std::size_t height() const { return height_; }

    /// Get number of channels in the image.
    std::size_t num_channels() const { return num_channels_; }

    /// Function to read the image data.
    ///
    /// The function return a const std::vector<T>& instead of std::vector<T>.
    /// This will provide a reference to the data, ensuring no unnecessary copies are made,
    /// making the function more efficient.
    ///
    /// The const qualifier ensures that the returned reference cannot be used to modify the data,
    /// maintaining the integrity of the image data.
    ///
    const std::vector<T> &readData() const & { return data_; }

    /// Setter and getter pixel value at a given position in the image.
    /// Converts a 3D pixel into 1D index.
    /// @param pixel_position_along_width The horizontal position of the pixel.
    /// @param pixel_position_along_heighthorizontal The vertical position of the pixel.
    /// @param channel channel of the pixel (e.g., 0 for red, 1 for green, 2 for blue in an RGB image).
    /// The Channel data is to be set by the user.
    ///
    /// @return The pixel value at the given position.
    ///
    T &pixelValue(std::size_t const pixel_position_along_width, std::size_t const pixel_position_along_height, std::size_t const channel)
    {
        auto const idx = channel * (height_ * width_) + (pixel_position_along_height * width_ + pixel_position_along_width);
        assert(idx < data_.size() && "Index out of bounds");
        return data_[idx];
    }

    const T &pixelValue(std::size_t const pixel_position_along_width, std::size_t const pixel_position_along_height, std::size_t const channel) const
    {
        auto const idx = channel * (height_ * width_) + (pixel_position_along_height * width_ + pixel_position_along_width);
        assert(idx < data_.size() && "Index out of bounds");
        return data_[idx];
    }

private:
    std::size_t width_;
    std::size_t height_;
    std::size_t num_channels_;
    std::vector<T> data_;
};
#endif // LIB_INTER_P_COM__SRC_IMAGE_H
