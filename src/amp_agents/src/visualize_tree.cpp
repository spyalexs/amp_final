#include "amp_agents/visualize_tree.hpp"

TreeVisualizer::TreeVisualizer() : tree_image(TREE_IMAGE_SIZE, TREE_IMAGE_SIZE, CV_8UC3, cv::Scalar(0,0,0)){
    
}


void TreeVisualizer::displayTree(std::list<SstNode*> tree){
    
    for(auto it = tree.begin(); it != tree.end(); ++it){
        drawNode((*it));
    }

    cv::imshow("Circle on Mat", tree_image);
}

void TreeVisualizer::drawNode(SstNode* node){

    //draw a point
    std::pair<int, int> center_pos = getPixelFromState(node);

    cv::circle(tree_image, cv::Point(center_pos.first, center_pos.second), CIRCLE_RADIUS, cv::Scalar(255, 0, 0), -1);

}

std::pair<int, int> TreeVisualizer::getPixelFromState(SstNode* node){
    //returns a rounded value for the pixel location of a node
    return{std::round(node->state[0] / TREE_IMAGE_SIZE * TREE_IMAGE_SIZE), std::round(node->state[1] / TREE_IMAGE_SIZE * TREE_IMAGE_SIZE)};
}