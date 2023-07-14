#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct HitInfo {
    Vec3 contact;
    Vec3 normal;
    double t;
};

class Hittable {
    public:
        virtual ~Hittable() {};

        virtual bool hit(const Ray& r, double t_min, double t_max, HitInfo& info) const = 0;
};

#endif