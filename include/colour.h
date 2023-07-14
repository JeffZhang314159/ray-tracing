#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>

#include "utility.h"

class Colour {
    // Class for RGB Colours
    double red, green, blue;

    public:
        Colour() : red(0), green(0), blue(0) {};
        Colour(double r, double g, double b) {
            if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1) {
                throw std::out_of_range("Colour RGB values must be between 0 and 1");
            } else {
                this->red = r;
                this->green = g;
                this->blue = b;
            }
        }

        double r() const { return red; }
        double g() const { return green; }
        double b() const { return blue; }

        Colour operator+=(const Colour& c) {
            red += c.r();
            green += c.g();
            blue += c.b();
            return *this;
        }

        Colour operator/=(double a) {
            red /= a;
            green /= a;
            blue /= a;
            return *this;
        }
};

// Utility functions
inline std::ostream& operator<<(std::ostream &out, const Colour &c) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(c.r(), 0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(c.g(), 0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(c.b(), 0, 0.999)) << '\n';
    return out;
}

inline Colour operator+(const Colour &c1, const Colour &c2) {
    return Colour(c1.r() + c2.r(), c1.g() + c2.g(), c1.b() + c2.b());
}

inline Colour operator*(const double t, const Colour &c) {
    return Colour(t * c.r(), t * c.g(), t * c.b());
}

#endif