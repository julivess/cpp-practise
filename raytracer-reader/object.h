#pragma once

#include "triangle.h"
#include "material.h"
#include "sphere.h"
#include "vector.h"

struct Object {
    const Material* material = nullptr;
    Triangle polygon;
    Triangle normal;
    Object(const Triangle& polyg, const Triangle& norm, const Material* mater)
        : material(mater), polygon(polyg), normal(norm) {
    }
    const Vector* GetNormal(size_t index) const {
        return &normal[index];
    }
    const Triangle& GetObject() const {
        return polygon;
    }
};

struct SphereObject {
    const Material* material = nullptr;
    Sphere sphere;
    SphereObject(const Sphere& spher, const Material* mater) : material(mater), sphere(spher) {
    }
    const Sphere& GetObject() const {
        return sphere;
    }
};
