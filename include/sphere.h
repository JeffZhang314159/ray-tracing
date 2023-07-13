#ifndef SPHERE_H
#define SPHERE_H

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
    double a = dot(r.direction(), r.direction());
    double b = 2 * dot(r.direction(), ray_to_sphere);
    double c = dot(ray_to_sphere, ray_to_sphere) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    } else {
        return true;
    }
}

#endif