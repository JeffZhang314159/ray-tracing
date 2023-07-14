#include <cmath>
#include <iostream>

#include "camera.h"
#include "colour.h"
#include "hittable_list.h"
#include "ray.h"
#include "sphere.h"
#include "utility.h"
#include "vec3.h"

Colour ray_colour(const HittableList& world, const Ray& r) {
    HitInfo hitInfo;
    if (world.hit(r, 0, kInfinity, hitInfo)) {
        double r = 0.5 * hitInfo.normal.x() + 0.5;
        double g = - 0.5 * hitInfo.normal.y() + 0.5;
        double b = 0.5 * hitInfo.normal.z() + 0.5;
        return Colour(r, g, b);
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
    const int samples_per_pixel = 100;

    // Creating our world
    HittableList world;
    world.add(std::make_shared<Sphere>(Vec3(0,0,1), 0.5));
    world.add(std::make_shared<Sphere>(Vec3(0,-100.5,0), 100));

    // Camera
    // Using convention z-axis positive going "in" to the screen
    const double viewport_height = 2.0;
    const double focal_length = 1.0;
    Camera camera(aspect_ratio, viewport_height, focal_length);

    // Rendering
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rLines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            Colour pixel_colour(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / (image_width - 1);
                double v = (j + random_double()) / (image_height - 1);
                Ray r = camera.get_ray(u, v);
                pixel_colour += ray_colour(world, r);
            }
            pixel_colour /= samples_per_pixel;
            std::cout << pixel_colour;;
        }
    }
    std::cerr << "\nDone.\n";
}
