#include "dynamic_ball.hpp"

DynamicBall::DynamicBall(V6d Damping, double Mass, std::string name, std::vector<int> lockedStates, bool gravity) : DynamicObject(Mass, lockedStates, name, gravity){
    damping = Damping;
}


M12d DynamicBall::getAMatrix(V12d current_state) {

    //can be override for systems with complex dynamics
    M12d a_mat;
    a_mat.setZero();

    a_mat(0,6) = 1;
    a_mat(1,7) = 1;
    a_mat(2,8) = 1;
    a_mat(3,9) = 1;
    a_mat(4,10) = 1;
    a_mat(5,11) = 1;

    a_mat(6,6) = -damping[0] / mass;
    a_mat(7,7) = -damping[1] / mass;
    a_mat(8,8) = -damping[2] / mass;
    a_mat(9,9) = -damping[3] / mass;
    a_mat(10,10) = -damping[4] / mass;
    a_mat(11,11) = -damping[5] / mass;

    return a_mat;
}

M12d DynamicBall::getBMatrix(V12d current_state) {

    //can be override for systems with complex dynamics
    M12d b_mat;
    b_mat.setZero();

    return b_mat;
}