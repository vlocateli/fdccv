#ifndef IMAGE_HPP
#define IMAGE_HPP
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/core/fast_math.hpp>
class Image
{
    public:
        explicit Image(std::string const& file_name, int flags = cv::IMREAD_COLOR);
        auto write_image(std::string const& out_file, std::vector<int> const& params= std::vector<int>()) -> bool;
        auto convert_to_greyscale(Image &out) -> void;
        auto convert_to_greyscale() -> void;
        auto shrink_image(Image& out, const int detection_width) -> void;
        auto shrink_image(const int detection_width) -> void;
        auto histogram_equalization(Image& out) -> void;
        auto histogram_equalization() -> void;
    private:
        std::string fname_;
        cv::Mat image_;
};
#endif // IMAGE_HPP
