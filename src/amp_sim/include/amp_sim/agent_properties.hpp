#pragma once

//contain hard coded agent properties - there are much cleaner ways to do this but, this will do
//properties do need to be initialized the same for the modelled agent and the simulated agent, otherwise, that opens pandora's box

#define OMNI_AGENT_PROPERTIES Eigen::Matrix<double, 6, 1>(2.0, 2.0, 2.0, 2.0, 2.0, 2.0) , 1, "omni_agent", {2,3,4}

//defining the agent as a rectangle
#define AGENT_DIMENSIONS Eigen::Matrix<double, 3, 1>(0.6, 0.6, 0.3)