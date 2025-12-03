#pragma once

#include <Eigen/Dense>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream> 

#include <rclcpp/rclcpp.hpp>
#include <ament_index_cpp/get_package_share_directory.hpp>

//this is scuffed...
#include "../../amp_sim/include/amp_sim/dynamic_object.hpp"
#include "../../amp_sim/include/amp_sim/omni_agent.hpp"
#include "collision_checker.hpp"

#include "amp_msgs/msg/ideal_path.hpp"
#include "amp_msgs/msg/agent_control.hpp"

#define NUM_PROPAGATIONS 5
#define NUM_SUB_PROPAGATIONS 25
#define SAMPLING_INTERVAL 0.01
#define COLLISION_CHECK_INTERVAL 0.1
#define SEARCHING_RANGE 0.4
#define NEIGHBORHOOD_RANGE 0.15
#define MAX_STOPPED_VELOCITY 0.1
#define SUB_TIMEOUT 10

#define COVERAGE_MAP_SCALE 20

#define SAVE_SUBSTATES true
#define LOAD_SUBSTATES false

typedef Eigen::Matrix<double, 12, 1> V12d;
typedef Eigen::Matrix<double, 13, 1> V13d;

class SstNode{

    public:
        SstNode(V13d State, double Cost, SstNode* Parent){
            //use this to intiialize child nodes

            state = State;
            cost_from_source = Cost;
            parent = Parent;

            node_index = 0;
        }

        SstNode(V13d initialState){
            //use this to initialize the root node
            state = initialState;
            parent = nullptr;
            cost_from_source = 0;
            
            node_index = 0;
        }

        V13d state;

        std::vector<std::pair<double, V13d>> sub_states;

        SstNode* parent = nullptr;

        double cost_from_source;  
        
        V12d control_vector;
        double duration;

        int node_index = 0;
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

        SstNode* sst_node = nullptr;

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
        SstTree(DynamicObject* Agent, BallCatchEnvironment* environment, std::string file_name,  rclcpp::Node* ptr);

        bool parse_line(std::string data);
        std::vector<int> parseIntVectorFromLine(const std::string& line);

        template<typename Derived>
        void parseEigenVector(const std::string &csv, Eigen::DenseBase<Derived> &vec);

        DynamicObject* agent = nullptr;

        std::list<SstNode*> tree;
        std::list<SstNode> node_pile;
        std::list<SstNeighborhood> neighborhoods;

        SstNode generateNewNode();
        SstNode subStoppedNode(SstNode* parent, V13d sub_state);
        bool processNewNode();
        
        V13d generate_random_sample();
        V12d generate_random_controls();
        double generate_random_duration();

        V12d distance_weights;
        V12d sample_minimums;
        V12d sample_d_maximums;

        BallCatchEnvironment* env = nullptr;

        int samples_before_collision_check;

        double evaluate_distance_full(V13d p1, V13d p2, V12d weights);
        double evalutate_distance_euclidean(V13d p1, V13d p2);
        double evalutate_distance_euclidean(v3d p1, V13d p2);
        double evalutate_distance_euclidean_and_velocity(V13d p1, V13d p2, double velocity_weight);

        SstNode* getLowestCostNodeWithinRange(V13d reference, double range);


        bool propagate_agent(V12d controls, double duration, std::vector<std::pair<double, V13d>>* substates);  

        Eigen::Quaterniond getYawQuat(double yaw);
        
        rclcpp::Node* node_ptr = nullptr;

        void runTreeStats();
        double get_average_distance_deviation();
        double get_converage_percentage();
        double get_tree_end_velocity();
        std::vector<double> tree_distance_deviations;
        std::vector<double> tree_coverage_percentages;
        std::vector<double> tree_end_velocities;
        std::vector<double> tree_times;
        std::vector<int> node_counts;

        void save_tree_to_file(std::string filename);
        void save_tree_stats_to_file(std::string filename);

        double prop_begin_time = 0;
};

class SstPath{

    public:

        SstPath(SstNode leaf);
        SstPath(SstNode leaf, DynamicObject* agent, bool invert);

        void create_forward_path(SstNode leaf);

        std::vector<std::pair<double, V13d>> states;
        std::vector<V12d> controls;
        std::vector<double> durations;

        amp_msgs::msg::IdealPath path_msg;
        void generate_msg();
};