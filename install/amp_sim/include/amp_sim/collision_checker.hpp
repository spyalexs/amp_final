#pragma once

#include "Eigen/Dense"
#include <vector>

typedef Eigen::Matrix<double, 6, 1> v6d;
typedef Eigen::Matrix<double, 3, 1> v3d;
typedef Eigen::Matrix<double, 4, 1> v4d;
typedef Eigen::Matrix<double, 3, 3> m3d;
typedef Eigen::Matrix<double, 6, 6> m6d;
typedef Eigen::Matrix<double, 6, 3> m6d3;


class Plane{
    public:
        Plane(std::vector<v3d> Points);

        bool check_segment_collision(v3d p1, v3d p2);

        std::vector<v3d> points;
        v4d plane_eq; // [0] = [1] * x + [2] * y + [3] * z;  
        m3d ortho_vector_mat;


};

class RectPrism{
    public:
        RectPrism(v3d dim, v3d Center, double yaw, double pitch);

        std::vector<Plane> getPlanes();
        std::vector<std::pair<v3d, v3d>> get_segments();

        bool checkPrismCollision(RectPrism prism);
        bool checkPrismsCollision(std::vector<RectPrism> prism);

        std::vector<v3d> points;
        v3d center;

        double insta_radius = 0;
};