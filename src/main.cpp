#include <iostream>

#include <vec3.h>
#include <colour.h>

int main() {
    // Image, using PPM format
    const int image_width = 256;
    const int image_height = 256;

    // Rendering
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rLines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Colour pixel_colour(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.1);
            std::cout << pixel_colour;;
        }
    }
    std::cerr << "\nDone.\n";
}
