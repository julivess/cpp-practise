#pragma once

#include "vector.h"

struct Light {
    Vector position;
    Vector intensity;
    Light(const Vector& posit, const Vector& intens) : position(posit), intensity(intens) {
    }
    Light() {
        position = {};
        intensity = {};
    }
};
