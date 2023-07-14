#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"

class Camera {
    Vec3 origin;
    Vec3 bottom_left_corner;
    Vec3 viewport_horizontal;
    Vec3 viewport_vertical;
    
    public:
        Camera(double aspect_ratio, double vp_height, double f_length) {
            auto viewport_height = vp_height;
            auto viewport_width = aspect_ratio * viewport_height;
            auto focal_length = f_length;

            origin = Vec3(0, 0, 0);
            viewport_horizontal = Vec3(viewport_width, 0, 0);
            viewport_vertical = Vec3(0, viewport_height, 0);
            bottom_left_corner = origin + Vec3(0, 0, focal_length) - viewport_horizontal / 2 - viewport_vertical / 2; 
        }

        Ray get_ray(double u, double v) const {
            // u and v are the fractional horizontal and vertical components of a given point in the viewport
            return Ray(origin, bottom_left_corner + u * viewport_horizontal + v * viewport_vertical);
        }  
};

#endif