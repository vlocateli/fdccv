#include "../include/classifier.hpp"
#include "../include/image.hpp"
#include "../include/utils.hpp"
#ifdef TARGET_OS_UNIX
auto main() -> int {
  Image lena("../image/lena.jpg");
  lena.convert_to_greyscale();
  lena.shrink_image(320);
  lena.histogram_equalization();
  Classifier facial_classifier(
      "../classifiers/haarcascade_frontalface_default.xml");
  int flags = cv::CASCADE_FIND_BIGGEST_OBJECT;
  cv::Size min_feature_size(20, 20);
  float search_scale_factor = 1.3f;
  int min_neighbors = 4;
  std::vector<cv::Rect> face;
  facial_classifier.detect_multi_scale(lena, face, search_scale_factor,
                                       min_neighbors, flags, min_feature_size);
  if (face.size() == 1) {
    std::cout << "Rosto encontrado\n";
  }
  Image out;
  lena.clone_from_rect(face.at(0), "../image/face_found.jpg", out);
}
#ifdef TARGET_OS_WINDOWS
auto main() -> int {

  Image lena("..\\image\\lena.jpg");
  lena.convert_to_greyscale();
  lena.shrink_image(320);
  lena.histogram_equalization();
  Classifier facial_classifier(
      "..\\classifiers\\haarcascade_frontalface_default.xml");
  int flags = cv::CASCADE_FIND_BIGGEST_OBJECT;
  cv::Size min_feature_size(20, 20);
  float search_scale_factor = 1.3f;
  int min_neighbors = 4;
  std::vector<cv::Rect> face;
  facial_classifier.detect_multi_scale(lena, face, search_scale_factor,
                                       min_neighbors, flags, min_feature_size);
  if (face.size() == 1) {
    std::cout << "Rosto encontrado\n";
  }
  Image out;
  lena.clone_from_rect(face.at(0), "..\\image\\face_found.jpg", out);
}
#endif // TARGET_OS_UNIX
#endif // TARGET_OS_WINDOWS
