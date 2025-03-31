#include "../include/image.hpp"

auto main() -> int
{
    Image im("../image/lena.jpg");
    im.convert_to_greyscale();
    im.write_image("../image/grayscaled.jpg");
    im.shrink_image(180);
    im.write_image("../image/shrinked.jpg");
    im.histogram_equalization();
    im.write_image("../image/equalized.jpg");
}
