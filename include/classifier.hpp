#ifndef CLASSIFIER_HPP
#define CLASSIFIER_HPP
#pragma once
#include "../include/image.hpp"
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/core/types.hpp>
#include <opencv4/opencv2/objdetect.hpp>
#include <string>
class Classifier {
public:
  Classifier(std::string const &fname);
  auto detect_multi_scale(Image image, std::vector<cv::Rect> &objects,
                          double scale_factor = 1.1, int min_neighbors = 3,
                          int flags = 0, cv::Size min_size = cv::Size(),
                          cv::Size max_size = cv::Size()) -> void;

private:
  std::string file_name_;
  cv::CascadeClassifier face_detector_;
};

#endif // CLASSIFIER_HPP
