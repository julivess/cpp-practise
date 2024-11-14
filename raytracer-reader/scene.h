#pragma once

#include "material.h"
#include "vector.h"
#include "object.h"
#include "light.h"

#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>

class Scene {
public:
    Scene() {
    }
    void Add(const std::unordered_map<std::string, Material>& material) {
        materials_ = material;
    }
    void Add(const std::vector<Object>& objects, const std::vector<SphereObject>& sphere,
             const std::vector<Light>& light) {
        objects_ = objects;
        spheres_ = sphere;
        light_ = light;
    }
    const std::vector<Object>& GetObjects() const {
        return objects_;
    }
    const std::vector<SphereObject>& GetSphereObjects() const {
        return spheres_;
    }
    const std::vector<Light>& GetLights() const {
        return light_;
    }
    const std::unordered_map<std::string, Material>& GetMaterials() const {
        return materials_;
    }

private:
    std::vector<Object> objects_;
    std::vector<SphereObject> spheres_;
    std::vector<Light> light_;
    std::unordered_map<std::string, Material> materials_;
};

std::unordered_map<std::string, Material> ReadMaterials(const std::filesystem::path& path) {
    std::ifstream file(path);
    std::unordered_map<std::string, Material> result;
    Material mat_tmp;
    std::string line;
    bool flag = false;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string ident;

        iss >> ident;
        if (ident == "newmtl") {
            if (flag) {
                result.insert({mat_tmp.name, mat_tmp});
            }
            flag = true;
            mat_tmp = Material{};
            iss >> mat_tmp.name;
            continue;
        }
        if (ident == "Ns") {
            iss >> mat_tmp.specular_exponent;
            continue;
        }
        if (ident == "Ni") {
            iss >> mat_tmp.refraction_index;
            continue;
        }
        if (ident == "al") {
            double vec_a, vec_b, vec_c;
            iss >> vec_a >> vec_b >> vec_c;
            mat_tmp.albedo = {vec_a, vec_b, vec_c};
            continue;
        }
        if (ident == "Ka") {
            double vec_a, vec_b, vec_c;
            iss >> vec_a >> vec_b >> vec_c;
            mat_tmp.ambient_color = {vec_a, vec_b, vec_c};
            continue;
        }
        if (ident == "Ke") {
            double vec_a, vec_b, vec_c;
            iss >> vec_a >> vec_b >> vec_c;
            mat_tmp.intensity = {vec_a, vec_b, vec_c};
            continue;
        }
        if (ident == "Ks") {
            double vec_a, vec_b, vec_c;
            iss >> vec_a >> vec_b >> vec_c;
            mat_tmp.specular_color = {vec_a, vec_b, vec_c};
            continue;
        }
        if (ident == "Kd") {
            double vec_a, vec_b, vec_c;
            iss >> vec_a >> vec_b >> vec_c;
            mat_tmp.diffuse_color = {vec_a, vec_b, vec_c};
            continue;
        }
    }
    result.insert({mat_tmp.name, mat_tmp});
    return result;
}
Scene ReadScene(const std::filesystem::path& path) {
    std::ifstream file(path);
    std::vector<SphereObject> spheres_v;
    std::vector<Object> objects_v;
    std::vector<Light> ligths;
    std::string material;
    std::vector<Vector> vertex;
    std::vector<Vector> normal;
    std::string line;
    Scene result;

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string ident;

        iss >> ident;

        if (ident == "mtllib") {
            std::string pathmtl = line.substr(line.find(' ') + 1);
            result.Add(ReadMaterials(path.parent_path() / pathmtl));
            continue;
        }
        if (ident == "usemtl") {
            std::string tmp;
            iss >> tmp;
            material = tmp;
            continue;
        }
        if (ident == "S") {
            double x, y, z, r;
            iss >> x >> y >> z >> r;
            Vector vec{x, y, z};
            Sphere spher{vec, r};
            spheres_v.push_back(SphereObject{spher, &result.GetMaterials().at(material)});
            continue;
        }
        if (ident == "P") {
            double x, y, z;
            double r, j, b;
            iss >> x >> y >> z >> r >> j >> b;
            Vector position{x, y, z};
            Vector intensity{r, j, b};
            ligths.push_back({position, intensity});
            continue;
        }
        if (ident == "v") {
            double x, y, z;
            iss >> x >> y >> z;
            vertex.push_back(Vector{x, y, z});
            continue;
        }
        if (ident == "vn") {
            double x, y, z;
            iss >> x >> y >> z;
            normal.push_back(Vector{x, y, z});
            continue;
        }
        if (ident == "f") {
            std::string data;
            size_t first, second;
            size_t index = 0;
            Vector vert_f;
            Vector norm_f;
            Vector vert_p;
            Vector norm_p;
            while (iss >> data) {
                bool flag = false;
                for (size_t i = 0; i < data.size(); ++i) {
                    if (data[i] == '/' && !flag) {
                        flag = true;
                        first = i;
                        continue;
                    }
                    if (data[i] == '/' && flag) {
                        second = i;
                        break;
                    }
                }
                if (!flag) {
                    int ind_vertex = std::stoi(data);
                    size_t ind_v = ind_vertex > 0 ? --ind_vertex : vertex.size() + ind_vertex;
                    if (index == 0) {
                        vert_f = vertex[ind_v];
                        ++index;
                        continue;
                    }
                    if (index == 1) {
                        vert_p = vertex[ind_v];
                        ++index;
                        continue;
                    }
                    Triangle norml;
                    Triangle obj{vert_f, vert_p, vertex[ind_v]};
                    objects_v.push_back(Object{obj, norml, &result.GetMaterials().at(material)});
                    vert_p = vertex[ind_v];
                    ++index;
                    continue;
                }
                int ind_vertex = std::stoi(data.substr(0, first));
                int ind_normal = std::stoi(data.substr(second + 1));
                size_t ind_v = ind_vertex > 0 ? --ind_vertex : vertex.size() + ind_vertex;
                size_t ind_n = ind_normal > 0 ? --ind_normal : normal.size() + ind_normal;
                if (index == 0) {
                    vert_f = vertex[ind_v];
                    norm_f = normal[ind_n];
                    ++index;
                    continue;
                }
                if (index == 1) {
                    vert_p = vertex[ind_v];
                    norm_p = normal[ind_n];
                    ++index;
                    continue;
                }
                Triangle obj{vert_f, vert_p, vertex[ind_v]};
                Triangle norml{norm_f, norm_p, normal[ind_n]};
                objects_v.push_back(Object{obj, norml, &result.GetMaterials().at(material)});
                vert_p = vertex[ind_v];
                norm_p = normal[ind_n];
                ++index;
            }
        }
    }
    result.Add(objects_v, spheres_v, ligths);
    return result;
}
