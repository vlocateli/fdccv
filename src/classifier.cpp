#include "../include/classifier.hpp"
#include <opencv4/opencv2/core.hpp>

Classifier::Classifier(std::string const &fname) : file_name_(fname) {
  try {
    face_detector_.load(file_name_);
  } catch (cv::Exception &e) {
    std::cerr << "ERROR: Falhou ao carregar o arquivo " << file_name_ << '\n';
    std::cerr << e.what() << '\n';
    exit(1);
  }
}

auto Classifier::detect_multi_scale(Image image, std::vector<cv::Rect> &objects,
                                    double scale_factor, int min_neighbors,
                                    int flags, cv::Size min_size,
                                    cv::Size max_size) -> void {
  face_detector_.detectMultiScale(image.image(), objects, scale_factor,
                                  min_neighbors, flags, min_size, max_size);
}
