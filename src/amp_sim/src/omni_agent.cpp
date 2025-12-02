#include "amp_sim/omni_agent.hpp"

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
    b_mat(6,0) = (.7071 / mass) * cos(current_state[5]) - (-.7071 / mass) * sin(current_state[5]);
    b_mat(7,0) = (-.7071 / mass)  * cos(current_state[5]) + (.7071 / mass) * sin(current_state[5]);
    b_mat(11,0) = OMNI_AGENT_WHEEL_RADIUS / (mass * ROTATIONAL_INTERIA_SCALE);

    //ypos xnegative corner
    b_mat(6,1) = (.7071 / mass) * cos(current_state[5]) - (.7071 / mass) * sin(current_state[5]);
    b_mat(7,1) = (.7071 / mass) * cos(current_state[5]) + (.7071 / mass) * sin(current_state[5]);
    b_mat(11,1) = OMNI_AGENT_WHEEL_RADIUS/ (mass * ROTATIONAL_INTERIA_SCALE);

    //negative negative corner
    b_mat(6,2) = (-.7071 / mass) * cos(current_state[5]) - (.7071 / mass) * sin(current_state[5]);
    b_mat(7,2) = (.7071 / mass) * cos(current_state[5]) + (-.7071 / mass) * sin(current_state[5]);
    b_mat(11,2) = OMNI_AGENT_WHEEL_RADIUS / (mass * ROTATIONAL_INTERIA_SCALE);

    //xpositive y negative corner
    b_mat(6,3) = (-.7071 / mass) * cos(current_state[5]) - (-.7071 / mass) * sin(current_state[5]);
    b_mat(7,3) = (-.7071 / mass) * cos(current_state[5]) + (-.7071 / mass) * sin(current_state[5]);
    b_mat(11,3) = OMNI_AGENT_WHEEL_RADIUS / (mass * ROTATIONAL_INTERIA_SCALE);

    return b_mat;
}

V12d OmniAgent::invert_control(V12d control){   

    return -control;
};