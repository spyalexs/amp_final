#pragma once

#include <Eigen/Dense>
#include <vector>
#include "dynamic_object.hpp"


class DynamicBall : public DynamicObject{

    public:
        DynamicBall(V6d Damping, double Mass, std::string name, std::vector<int> lockedStates, bool gravity=true);

        M12d getAMatrix(V12d current_state) override;
        M12d getBMatrix(V12d current_state) override;

        V6d damping;
    
};