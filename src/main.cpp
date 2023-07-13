#include <iostream>
#include <cmath>

#include "colour.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"

Colour ray_colour(const Ray& r) {
    Sphere ball(Vec3(0,0,1), 0.5);
    HitInfo hitInfo;
    if (ball.hit(r, 0, 2, hitInfo)) {
        return Colour(1, 0, 0);
    }
    Vec3 unit_direction = normalize(r.direction());
    double t = 0.5 * (unit_direction.y() + 1);
    return t * Colour(0.4, 0.7, 1.0) + (1 - t) * Colour(1.0, 1.0, 1.0);
}

int main() {
    // Image, using PPM format
    const double aspect_ratio = 16.0 / 9.0;
    const int image_height = 400;
    const int image_width = static_cast<int>(aspect_ratio * image_height);

    // Camera
    // Using convention z-axis positive going "in" to the screen
    const double viewport_height = 2.0;
    const double viewport_width = aspect_ratio * viewport_height;
    const double focal_length = 1.0;

    const Vec3 origin(0, 0, 0);
    const Vec3 viewport_horizontal(viewport_width, 0, 0);
    const Vec3 viewport_vertical(0, viewport_height, 0);
    const Vec3 bottom_left_corner = origin + Vec3(0, 0, focal_length) - viewport_horizontal / 2 - viewport_vertical / 2; 

    // Rendering
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rLines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);
            Ray r(origin, bottom_left_corner + u * viewport_horizontal + v * viewport_vertical);
            Colour pixel_colour = ray_colour(r);
            std::cout << pixel_colour;;
        }
    }
    std::cerr << "\nDone.\n";
}
