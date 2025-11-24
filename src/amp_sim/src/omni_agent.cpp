#include "omni_agent.hpp"

OmniAgent::OmniAgent(V6d Damping, double Mass, std::string name, std::vector<int> lockedStates, bool gravity) : DynamicObject(Mass, lockedStates, name, gravity){
    damping = Damping;
}


M12d OmniAgent::getAMatrix(V12d current_state) {

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

M12d OmniAgent::getBMatrix(V12d current_state) {

    //can be override for systems with complex dynamics
    M12d b_mat;
    b_mat.setZero();

    //first four control inputs represent the force applied by for corner wheels
    //positive positive corner
    b_mat(0,0) = .7071 / mass;
    b_mat(1,0) = -.7071 / mass;
    b_mat(5,0) = OMNI_AGENT_WHEEL_RADIUS / (mass * ROTATIONAL_INTERIA_SCALE);

    //ypos xnegative corner
    b_mat(0,1) = .7071 / mass;
    b_mat(1,1) = .7071 / mass;
    b_mat(5,1) = OMNI_AGENT_WHEEL_RADIUS/ (mass * ROTATIONAL_INTERIA_SCALE);

    //negative negative corner
    b_mat(0,2) = -.7071 / mass;
    b_mat(1,2) = .7071 / mass;
    b_mat(5,2) = OMNI_AGENT_WHEEL_RADIUS / (mass * ROTATIONAL_INTERIA_SCALE);

    //xpositive y negative corner
    b_mat(0,3) = -.7071 / mass;
    b_mat(1,3) = -.7071 / mass;
    b_mat(5,3) = OMNI_AGENT_WHEEL_RADIUS / (mass * ROTATIONAL_INTERIA_SCALE);

    return b_mat;
}