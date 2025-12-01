#pragma once

#include <Eigen/Dense>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>

#include <rclcpp/rclcpp.hpp>

//this is scuffed...
#include "../../amp_sim/include/amp_sim/dynamic_object.hpp"
#include "../../amp_sim/include/amp_sim/omni_agent.hpp"
#include "collision_checker.hpp"

#define NUM_PROPAGATIONS 5
#define SAMPLING_INTERVAL 0.01
#define COLLISION_CHECK_INTERVAL 0.1
#define SEARCHING_RANGE 0.4
#define NEIGHBORHOOD_RANGE 0.15

#define SAVE_SUBSTATES true

typedef Eigen::Matrix<double, 12, 1> V12d;
typedef Eigen::Matrix<double, 13, 1> V13d;

class SstNode{

    public:
        SstNode(V13d State, double Cost, SstNode* Parent){
            //use this to intiialize child nodes

            state = State;
            cost_from_source = Cost;
            parent = Parent;
        }

        SstNode(V13d initialState){
            //use this to initialize the root node
            state = initialState;
            parent = nullptr;
            cost_from_source = 0;
        }

        V13d state;

        std::vector<std::pair<double, V13d>> sub_states;

        SstNode* parent;

        double cost_from_source;  
        
        V12d control_vector;
        double duration;
};

class BallCatchEnvironment{

    public:
        std::vector<RectPrism> obstalces;

        V12d state_minimums;
        V12d state_maximums;
        V12d enforce_states_mask;

        V13d root_state;

        v3d agent_dim;
        std::vector<std::pair<double, double>> control_limits;
        std::pair<double, double> duration_limits;
};

class SstNeighborhood{
    public:
        SstNeighborhood(SstNode* sstNode){
            sst_node = sstNode;
            center = sst_node->state.block<3,1>(0,0);
            radius = NEIGHBORHOOD_RANGE;
        }

        SstNode* sst_node;

        v3d center;
        double radius;

        bool subplant_node(SstNode* node){
            if(node->cost_from_source < sst_node->cost_from_source){
                sst_node = node;
                return true;
            }

            return false;
        }
};

class SstTree{

    public:
        SstTree(DynamicObject* Agent, BallCatchEnvironment* environment);

        DynamicObject* agent;

        std::list<SstNode*> tree;
        std::list<SstNode> node_pile;
        std::list<SstNeighborhood> neighborhoods;

        SstNode generateNewNode();
        bool processNewNode();
        
        V13d generate_random_sample();
        V12d generate_random_controls();
        double generate_random_duration();

        V12d distance_weights;
        V12d sample_minimums;
        V12d sample_d_maximums;

        BallCatchEnvironment* env;

        int samples_before_collision_check;

        double evaluate_distance_full(V13d p1, V13d p2, V12d weights);
        double evalutate_distance_euclidean(V13d p1, V13d p2);
        double evalutate_distance_euclidean(v3d p1, V13d p2);
        double evalutate_distance_euclidean_and_velocity(V13d p1, V13d p2, double velocity_weight);

        SstNode* getLowestCostNodeWithinRange(V13d reference);

        bool propagate_agent(V12d controls, double duration, std::vector<std::pair<double, V13d>>* substates);  

        Eigen::Quaterniond getYawQuat(double yaw);
        
        rclcpp::Node* node_ptr;
};

class SstPath{

    SstPath(SstNode leaf);
    SstPath(SstNode leaf, DynamicObject* agent, bool invert);

    void create_forward_path(SstNode leaf);

    std::vector<std::pair<double, V13d>> states;
    std::vector<V12d> controls;
    std::vector<double> durations;
};