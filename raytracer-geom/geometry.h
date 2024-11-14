#pragma once

#include "vector.h"
#include "sphere.h"
#include "intersection.h"
#include "triangle.h"
#include "ray.h"
#include <math.h>

#include <optional>

std::optional<Intersection> GetIntersection(const Ray& ray, const Sphere& sphere) {
    Vector vec_to_centr = sphere.GetCenter() - ray.GetOrigin();
    double projection_length = DotProduct(vec_to_centr, ray.GetDirection());
    double perpendic_dist =
        DotProduct(vec_to_centr, vec_to_centr) - projection_length * projection_length;
    double radius = sphere.GetRadius();
    if (perpendic_dist > radius * radius) {
        return std::nullopt;
    }
    double length = std::sqrt(radius * radius - perpendic_dist);
    double first_dist = projection_length - length;
    double second_dist = projection_length + length;
    if (first_dist > second_dist) {
        double tmp = first_dist;
        first_dist = second_dist;
        second_dist = tmp;
    }
    if (first_dist < 0.) {
        first_dist = second_dist;
        if (first_dist < 0.) {
            return std::nullopt;
        }
    }
    double intersect_dist = first_dist;
    Vector inter_p = ray.GetOrigin() + ray.GetDirection() * intersect_dist;
    Vector normal = inter_p - sphere.GetCenter();
    normal.Normalize();
    if (DotProduct(normal, ray.GetDirection()) > 0.) {
        normal = normal * (-1.);
    }
    return Intersection{inter_p, normal, intersect_dist};
}

std::optional<Intersection> GetIntersection(const Ray& ray, const Triangle& triangle) {
    constexpr float kEpsilon = std::numeric_limits<float>::epsilon();

    Vector edge1 = triangle[1] - triangle[0];
    Vector edge2 = triangle[2] - triangle[0];
    Vector ray_cross_e2 = CrossProduct(ray.GetDirection(), edge2);
    double det = DotProduct(edge1, ray_cross_e2);

    if (det > -kEpsilon && det < kEpsilon) {
        return std::nullopt;
    }

    double inv_det = 1. / det;
    Vector s = ray.GetOrigin() - triangle[0];
    double u = inv_det * DotProduct(s, ray_cross_e2);

    if (u < 0. || u > 1.) {
        return std::nullopt;
    }
    Vector s_cross_e1 = CrossProduct(s, edge1);
    double v = DotProduct(ray.GetDirection(), s_cross_e1) * inv_det;

    if (v < 0. || u + v > 1.) {
        return std::nullopt;
    }
    double t = DotProduct(edge2, s_cross_e1) * inv_det;
    Vector normal = CrossProduct(edge1, edge2);
    normal.Normalize();
    if (DotProduct(normal, ray.GetDirection()) > 0.) {
        normal = normal * (-1.);
    }
    if (t > kEpsilon) {
        Vector inter_point = ray.GetOrigin() + ray.GetDirection() * t;
        return Intersection{inter_point, normal, t};
    }
    return std::nullopt;
}
Vector Reflect(const Vector& ray, const Vector& normal) {
    double cos_a1 = -DotProduct(ray, normal);
    Vector vec_reflect = ray + normal * (2 * cos_a1);
    vec_reflect.Normalize();
    return vec_reflect;
}
std::optional<Vector> Refract(const Vector& ray, const Vector& normal, double eta) {
    double cos_a1 = -DotProduct(ray, normal);
    double sin_a2 = eta * std::sqrt(1 - (cos_a1 * cos_a1));
    if (sin_a2 < -1 || sin_a2 > 1) {
        return std::nullopt;
    }
    double cos_a2 = std::sqrt(1 - sin_a2 * sin_a2);
    Vector vec_refract = ray * eta + normal * (eta * cos_a1 - cos_a2);
    vec_refract.Normalize();
    return vec_refract;
}
Vector GetBarycentricCoords(const Triangle& triangle, const Vector& point) {
    Triangle p_bc{triangle[1], triangle[2], point};
    Triangle p_ac{triangle[0], triangle[2], point};
    Triangle p_ab{triangle[0], triangle[1], point};
    double tr_area = triangle.Area();
    Vector result{p_bc.Area() / tr_area, p_ac.Area() / tr_area, p_ab.Area() / tr_area};
    return result;
}
