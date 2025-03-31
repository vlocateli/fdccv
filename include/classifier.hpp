#ifndef CLASSIFIER_HPP
#define CLASSIFIER_HPP
#pragma once
#include <string>
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/objdetect.hpp>
class Classifier
{
    Classifier(std::string const& fname);
    private:
        std::string file_name_;
        cv::CascadeClassifier face_detector_;
};
#endif // CLASSIFIER_HPP

