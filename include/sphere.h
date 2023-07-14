#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "hittable.h"
#include "vec3.h"

class Sphere : public Hittable {
    Vec3 center;
    double radius;

    public:
        Sphere() {}
        Sphere(const Vec3& c, double r) : center(c), radius(r) {}

        virtual bool hit(const Ray& r, double t_min, double t_max, HitInfo& info) const override;
};

bool Sphere::hit(const Ray& r, double t_min, double t_max, HitInfo& info) const {
    Vec3 ray_to_sphere = r.source() - center;
    double a = r.direction().length_squared();
    double half_b = dot(r.direction(), ray_to_sphere);
    double c = ray_to_sphere.length_squared() - radius * radius;
    double discriminant = half_b * half_b - a * c;

    if (discriminant < 0) {
        return false;
    }

    // Find the roots
    double sqrt_discriminant = std::sqrt(discriminant);
    double root = (-half_b - sqrt_discriminant) / a;
    if (root < t_min || root > t_max) {
        root = (-half_b + sqrt_discriminant) / a;
        if (root < t_min || root > t_max) {
            return false;
        }
    }

    info.t = root;
    info.contact = r.at(root);
    info.normal = (center - info.contact) / radius; // Normalize the normal vector

    return true;
}

#endif