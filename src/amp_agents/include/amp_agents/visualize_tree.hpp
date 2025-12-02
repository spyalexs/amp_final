#pragma once

#include <Eigen/Dense>
#include <cmath>
#include <opencv2/opencv.hpp>

#include "propagate_sst.hpp"

#define TREE_IMAGE_SIZE 2000
#define TREE_IMAGE_BOUND 10
#define CIRCLE_RADIUS 10
#define SUBCIRCLE_RADIUS 2
#define DISPLAY_SUBSTATES true
#define DISPLAY_NEIGHBORHOOD true

class TreeVisualizer{
    public:
        TreeVisualizer();

        cv::Mat tree_image;

        void displayTree(std::list<SstNode*> tree);
        void displayTree(std::list<SstNode*> tree, std::list<SstNeighborhood> neighborhoods);
        void drawNode(SstNode* node);

        std::pair<int, int> getPixelFromState(V13d* node);
};