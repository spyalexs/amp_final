#pragma once

#include <Eigen/Dense>
#include <cmath>
#include <opencv2/opencv.hpp>

#include "propagate_sst.hpp"

#define TREE_IMAGE_SIZE 2000
#define TREE_IMAGE_BOUND 5
#define CIRCLE_RADIUS 10

class TreeVisualizer{
    TreeVisualizer();

    cv::Mat tree_image;

    void displayTree(std::list<SstNode*> tree);
    void drawNode(SstNode* node);

    std::pair<int, int> getPixelFromState(SstNode* node);
};