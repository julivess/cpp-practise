#pragma once

#include "options/camera_options.h"
#include "options/render_options.h"
#include "image.h"
#include "vector.h"
#include "ray.h"
#include "material.h"
#include "scene.h"
#include "geometry.h"

#include <vector.h>
#include <algorithm>
#include <filesystem>
#include <math.h>
#include <iostream>

Ray CameraToWorld(const std::vector<Vector>& matr, Vector to) {
    Vector origin = Vector{matr[3][0], matr[3][1], matr[3][2]};
    to.Normalize();
    Vector direction{};
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            direction[i] += to[j] * matr[j][i];
        }
    }
    return Ray{origin, direction};
}

std::vector<Vector> CtoWmatrix(const Vector& from, const Vector& to) {
    Vector tmp{0, 1, 0};
    Vector forward = from - to;
    forward.Normalize();
    Vector right = CrossProduct(tmp, forward);
    if (Length(right) > std::numeric_limits<double>::epsilon()) {
        right.Normalize();
    } else {
        right = {1., 0., 0.};
    }
    Vector up = CrossProduct(forward, right);
    up.Normalize();
    std::vector<Vector> c_to_w(4);

    c_to_w[0][0] = right[0];
    c_to_w[0][1] = right[1];
    c_to_w[0][2] = right[2];
    c_to_w[1][0] = up[0];
    c_to_w[1][1] = up[1];
    c_to_w[1][2] = up[2];
    c_to_w[2][0] = forward[0];
    c_to_w[2][1] = forward[1];
    c_to_w[2][2] = forward[2];

    c_to_w[3][0] = from[0];
    c_to_w[3][1] = from[1];
    c_to_w[3][2] = from[2];

    return c_to_w;
}

RGB NormalPixel(const Ray& tracer, const Scene& scene) {
    std::optional<Intersection> inter;
    double min = __DBL_MAX__;
    double dist;
    Vector res_norm;
    RGB res;
    for (auto obj : scene.GetObjects()) {
        inter = GetIntersection(tracer, obj.GetObject());
        if (!inter) {
            continue;
        }
        dist = inter.value().GetDistance();
        if (min > dist) {
            min = dist;
            Vector bar = GetBarycentricCoords(obj.GetObject(), inter.value().GetPosition());
            res_norm = {0., 0., 0.};
            if (Length(*obj.GetNormal(0)) > 0.) {
                res_norm = res_norm + *obj.GetNormal(0) * bar[0];
            } else {
                res_norm = res_norm + inter.value().GetNormal() * bar[0];
            }
            if (Length(*obj.GetNormal(1)) > 0.) {
                res_norm = res_norm + *obj.GetNormal(1) * bar[1];
            } else {
                res_norm = res_norm + inter.value().GetNormal() * bar[1];
            }
            if (Length(*obj.GetNormal(2)) > 0.) {
                res_norm = res_norm + *obj.GetNormal(2) * bar[2];
            } else {
                res_norm = res_norm + inter.value().GetNormal() * bar[2];
            }
        }
    }
    for (auto obj : scene.GetSphereObjects()) {
        inter = GetIntersection(tracer, obj.GetObject());
        if (!inter) {
            continue;
        }
        dist = inter.value().GetDistance();
        if (min > dist) {
            min = dist;
            res_norm = inter.value().GetNormal();
        }
    }
    if (min < __DBL_MAX__) {
        res_norm = res_norm * 0.5;
        res = RGB{static_cast<int>((res_norm[0] + 0.5) * 255),
                  static_cast<int>((res_norm[1] + 0.5) * 255),
                  static_cast<int>((res_norm[2] + 0.5) * 255)};
    } else {
        res = RGB{0, 0, 0};
    }
    return res;
}

double DepthDistanse(const Ray& tracer, const Scene& scene) {
    std::optional<Intersection> inter;
    double min_dist = __DBL_MAX__;
    double dist = 0;
    for (auto obj : scene.GetObjects()) {
        inter = GetIntersection(tracer, obj.GetObject());
        if (!inter) {
            continue;
        }
        dist = inter.value().GetDistance();
        if (min_dist > dist && dist > 0.) {
            min_dist = dist;
        }
    }
    for (auto obj : scene.GetSphereObjects()) {
        inter = GetIntersection(tracer, obj.GetObject());
        if (!inter) {
            continue;
        }
        dist = inter.value().GetDistance();
        if (min_dist > dist && dist > 0.) {
            min_dist = dist;
        }
    }
    if (min_dist < __DBL_MAX__) {
        return min_dist;
    } else {
        return 0.;
    }
}

Vector GetLight (const Ray& tracer, const Scene& scene, const Intersection& inter, 
                 const Material& mtr) {
    Vector res;
    Vector orig = inter.GetPosition();
    for (auto& light : scene.GetLights()) {
        Vector v_l = light.position - orig;
        double dist = Length(v_l);
        v_l.Normalize();
        Ray trigger = {orig, v_l};
        std::optional<Intersection> trigger_inter;
        bool flag = false;
        for (auto& obj : scene.GetObjects()) {
            trigger_inter = GetIntersection(trigger, obj.GetObject());
            if (trigger_inter && dist > trigger_inter.value().GetDistance()) {
                flag = true;
            }
        }
        for (auto& obj : scene.GetObjects()) {
            trigger_inter = GetIntersection(trigger, obj.GetObject());
            if (trigger_inter && dist > trigger_inter.value().GetDistance()) {
                flag = true;
            }
        }
        if (flag) {
            continue;
        }
        double dot_d = DotProduct(inter.GetNormal(), v_l);
        double max_d = std::max(0., dot_d);
        Vector l_d = {mtr.diffuse_color[0] * light.intensity[0] * max_d, 
                      mtr.diffuse_color[1] * light.intensity[1] * max_d,
                      mtr.diffuse_color[2] * light.intensity[2] * max_d};
        Vector v_r = inter.GetNormal() * 2 * dot_d - v_l;
        double dot_s = DotProduct(v_r, tracer.GetDirection() * (-1.));
        double max_s = std::pow(std::max(0., dot_s), mtr.specular_exponent);
        Vector l_s = {mtr.specular_color[0] * light.intensity[0] * max_s,
                      mtr.specular_color[1] * light.intensity[1] * max_s,
                      mtr.specular_color[2] * light.intensity[2] * max_s};
        res = res + l_d + l_s;
    }
    return res;
}

enum class TypeObject {kTriangle, kSphere};

RGB FullPixel(const Ray& tracer, const Scene& scene) {
    std::optional<Intersection> inter;
    std::optional<Intersection> res_inter = std::nullopt;
    double min_dist = __DBL_MAX__;
    double dist = 0;
    TypeObject type_obj;
    SphereObject spher;
    Object triangl;
    Vector norm;

    for (auto& obj : scene.GetObjects()) {
        inter = GetIntersection(tracer, obj.GetObject());
        if (!inter) {
            continue;
        }
        dist = inter.value().GetDistance();
        if (min_dist > dist && dist > 0.) {
            min_dist = dist;
            type_obj = TypeObject::kTriangle;
            triangl = obj;
            //norm = {0., 0., 0.};
            Vector bar = GetBarycentricCoords(obj.GetObject(), inter.value().GetPosition());
            if (Length(*obj.GetNormal(0)) > 0.) {
                norm = norm + *obj.GetNormal(0) * bar[0];
            } else {
                norm = norm + inter.value().GetNormal() * bar[0];
            }
            if (Length(*obj.GetNormal(1)) > 0.) {
                norm = norm + *obj.GetNormal(1) * bar[1];
            } else {
                norm = norm + inter.value().GetNormal() * bar[1];
            }
            if (Length(*obj.GetNormal(2)) > 0.) {
                norm = norm + *obj.GetNormal(2) * bar[2];
            } else {
                norm = norm + inter.value().GetNormal() * bar[2];
            }
            res_inter = Intersection{inter.value().GetPosition(), norm, inter.value().GetDistance()};
        }
    }
    for (auto& obj : scene.GetSphereObjects()) {
        inter = GetIntersection(tracer, obj.GetObject());
        if (!inter) {
            continue;
        }
        dist = inter.value().GetDistance();
        if (min_dist > dist && dist > 0.) {
            min_dist = dist;
            type_obj = TypeObject::kSphere;
            spher = obj;
            res_inter = Intersection{inter.value().GetPosition() + inter.value().GetNormal() * 1e-6,
                                     inter.value().GetNormal(), inter.value().GetDistance()};
        }
    }
    if (res_inter) {
        return RGB {0, 0, 0};
    } else {
        
    }

}

Image Render(const std::filesystem::path& path, const CameraOptions& camera_options,
             const RenderOptions& render_options) {

    int width = camera_options.screen_width;
    int height = camera_options.screen_height;
    double height_fov = 2 * std::tan(camera_options.fov / 2);
    double width_fov = height_fov * width / height;
    RenderMode mode = render_options.mode;
    double x, y;

    Scene scene = ReadScene(path);
    Vector from{camera_options.look_from};
    Vector to{camera_options.look_to};
    Image result{width, height};

    std::vector<Vector> c_to_w = CtoWmatrix(from, to);
    std::vector<std::vector<double>> distant_depth(width, std::vector<double>(height));
    double max_dist = 0;
    for (int w = 0; w < width; ++w) {
        for (int h = 0; h < height; ++h) {
            x = (2 * (w + 0.5) / width - 1) * width_fov / 2;
            y = (1 - 2 * (h + 0.5) / height) * height_fov / 2;
            Ray tracer = CameraToWorld(c_to_w, Vector{x, y, -1.});
            if (mode == RenderMode::kDepth) {
                distant_depth[w][h] = DepthDistanse(tracer, scene);
            }
            if (mode == RenderMode::kNormal) {
                RGB pixel = NormalPixel(tracer, scene);
                result.SetPixel(pixel, h, w);
            }
            if (mode == RenderMode::kFull) {
                
            }
        }
    }
    if (mode == RenderMode::kDepth) {
        for (int w = 0; w < width; ++w) {
            for (int h = 0; h < height; ++h) {
                if (max_dist < distant_depth[w][h]) {
                    max_dist = distant_depth[w][h];
                }
            }
        }
        for (int w = 0; w < width; ++w) {
            for (int h = 0; h < height; ++h) {
                distant_depth[w][h] /= max_dist;
                if (distant_depth[w][h] != 0.) {
                    int pix = static_cast<int>(distant_depth[w][h] * 255);
                    result.SetPixel(RGB{pix, pix, pix}, h, w);
                } else {
                    result.SetPixel(RGB{255, 255, 255}, h, w);
                }
            }
        }
    }
    return result;
}