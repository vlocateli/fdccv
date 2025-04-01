#ifndef IMAGE_HPP
#define IMAGE_HPP
#pragma once
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/fast_math.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <string>
#include <vector>
class Image {
public:
  Image();
  explicit Image(std::string const &file_name, int flags = cv::IMREAD_COLOR);
  auto write_image(std::string const &out_file,
                   std::vector<int> const &params = std::vector<int>()) -> bool;
  auto convert_to_greyscale(Image &out) -> void;
  auto convert_to_greyscale() -> void;
  auto shrink_image(Image &out, const int detection_width) -> void;
  auto shrink_image(const int detection_width) -> void;
  auto histogram_equalization(Image &out) -> void;
  auto histogram_equalization() -> void;
  auto image() -> cv::Mat;
  auto clone_from_rect(cv::Rect const &rect, std::string const &out_fname,
                       Image &out_image) -> void;

private:
  std::string fname_;
  cv::Mat image_;
};
#endif // IMAGE_HPP
