#include "../include/image.hpp"
#include <opencv4/opencv2/imgproc.hpp>

Image::Image(std::string const& file_name, int flags)
    :
        fname_{file_name}
{
    image_ = cv::imread(fname_);
    if (!image_.data) {
        std::cerr << "ERROR::Image() " <<
        "Não foi possivel abrir: " << fname_
        << '\n';
    }
}

auto Image::write_image(std::string const& out_file, std::vector<int> const& params) -> bool
{
    if (!cv::imwrite(out_file, image_, params)) 
    {
        std::cerr << "ERROR: Falha ao escrever no arquivo: " << out_file << '\n';
        return false;
    }

    return true;
}

auto Image::convert_to_greyscale(Image &out) -> void
{
    if (image_.channels() == 3) {
        cv::cvtColor(image_, out.image_, cv::COLOR_BGR2GRAY);
    } 
    else if (image_.channels() == 4) {
        cv::cvtColor(image_, out.image_, cv::COLOR_BGRA2GRAY);
    }
    else {
        out.image_ = image_;
    }
}
auto Image::convert_to_greyscale() -> void
{
    
    if (image_.channels() == 3) {
        cv::cvtColor(image_, image_, cv::COLOR_BGR2GRAY);
    } 
    else if (image_.channels() == 4) {
        cv::cvtColor(image_, image_, cv::COLOR_BGRA2GRAY);
    }
}
auto Image::shrink_image(Image& out, const int detection_width) -> void
{
   auto scale = image_.cols / static_cast<float>(detection_width);
   if (image_.cols > detection_width) {
       int scaled_height = cvRound(image_.rows / scale);
       cv::resize(image_, out.image_, cv::Size(detection_width, scaled_height));
   } else {
       out.image_ = image_;
   }
}
auto Image::shrink_image(const int detection_width) -> void
{
   auto scale = image_.cols / static_cast<float>(detection_width);
   if (image_.cols > detection_width) {
       int scaled_height = cvRound(image_.rows / scale);
       cv::resize(image_, image_, cv::Size(detection_width, scaled_height));
   }    
}
auto Image::histogram_equalization(Image& out) -> void
{
    equalizeHist(image_, out.image_);
}
auto Image::histogram_equalization() -> void
{
    cv::equalizeHist(image_, image_);
}
