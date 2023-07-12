#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    Vec3 src;
    Vec3 dir;

    public:
        Ray() {}
        Ray(const Vec3& source, const Vec3& direction) : src(source), dir(direction)
        {}

        Vec3 source() const  { return src; }
        Vec3 direction() const { return dir; }

        Vec3 at(double t) const {
            return src + t*dir;
        }
};

#endif