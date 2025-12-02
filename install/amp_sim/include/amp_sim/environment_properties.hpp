#pragma once

//hardcoded environmental properties - only midly scuffed

//init state for the agent
#define AGENT_INITIAL_STATE Eigen::Matrix<double, 13, 1>(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0)

//enviroment bounds
#define ENVIRONMENT_LOWER_BOUND Eigen::Matrix<double, 12, 1>(-5.0, -5.0, -5.0, 0.0, 0.0, 0.0, -5.0, -5.0, -5.0, -5.0, -5.0, -5.0)
#define ENVIRONMENT_UPPER_BOUND Eigen::Matrix<double, 12, 1>(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0)