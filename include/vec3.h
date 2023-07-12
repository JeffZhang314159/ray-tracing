#ifndef Vec3_H
#define Vec3_H

#include <cmath>
#include <iostream>

class Vec3 {
    // Class for 3D vectors
    double v[3];

    public:
        Vec3() : v{0, 0, 0} {}
        Vec3(double x, double y, double z) : v{x, y, z} {}

        double x() const { return v[0]; }
        double y() const { return v[1]; }
        double z() const { return v[2]; }

        Vec3 operator-() const { return Vec3(-v[0], -v[1], -v[2]); }
        double operator[](size_t index) const {
            if (index > 2) {
                throw std::out_of_range("Vec3 access must be between 0 and 2");
            }
            return v[index];
        }

        double& operator[](size_t index) {
            if (index > 2) {
                throw std::out_of_range("Vec3 access must be between 0 and 2");
            }
            return v[index];
        }

        Vec3& operator+=(const Vec3 &u) {
            v[0] += u[0];
            v[1] += u[1];
            v[2] += u[2];
            return *this;
        }

        Vec3& operator-=(const Vec3 &u) {
            return *this += (-u);
        }    

        Vec3& operator*=(const double c) {
            v[0] *= c;
            v[1] *= c;
            v[2] *= c;
            return *this;
        }

        Vec3& operator/=(const double c) {
            return *this *= 1 / c;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
        }
};

// Utility functions
inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return Vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return Vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]);
}

inline Vec3 operator*(double t, const Vec3 &v) {
    return Vec3(t*v[0], t*v[1], t*v[2]);
}

inline Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}

inline Vec3 operator/(Vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const Vec3 &u, const Vec3 &v) {
    return u[0] * v[0]
         + u[1] * v[1]
         + u[2] * v[2];
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u[1] * v[2] - u[2] * v[1],
                u[2] * v[0] - u[0] * v[2],
                u[0] * v[1] - u[1] * v[0]);
}

inline Vec3 normalize(Vec3 v) {
    return v / v.length();
}

#endif