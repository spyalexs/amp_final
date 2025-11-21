#pragma once

#include <Eigen/Dense>
#include <vector>
#include <string>

typedef Eigen::Matrix<double, 13, 1> V13d;
typedef Eigen::Matrix<double, 12, 1> V12d;
typedef Eigen::Matrix<double, 6, 1> V6d;
typedef Eigen::Matrix<double, 3, 1> V3d;
typedef Eigen::Matrix<double, 12, 12> M12d;

#define GRAVITATIONAL_CONSTANT -9.81

class DynamicObject{

    public:
        DynamicObject(double Mass, std::vector<int> lockedStates, std::string name, bool Gravity=false);

        void tic(V12d control, double current_time);

        M12d virtual getAMatrix(V12d current_state);
        M12d virtual getBMatrix(V12d current_state);

        bool gravity = false;

        //[lx ly, lz, ow, ox, oy, oz, vx, vy, vz, vox, voy, voz]
        V13d state;
        double previous_tic = -1;

        double mass;

        std::vector<bool> locked_states;

        std::string object_name;
    
};