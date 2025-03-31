#include "../include/classifier.hpp"
#include <opencv4/opencv2/core.hpp>

Classifier::Classifier(std::string const& fname)
    :
        file_name_(fname)
{
    try{
        face_detector_.load(file_name_);
    } catch (cv::Exception &e) {
        std::cerr << "ERROR: Falhou ao carregar o arquivo " << 
        file_name_ << '\n';
        exit(1);
    }
}
