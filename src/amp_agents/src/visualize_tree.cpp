#include "amp_agents/visualize_tree.hpp"

TreeVisualizer::TreeVisualizer() : tree_image(TREE_IMAGE_SIZE, TREE_IMAGE_SIZE, CV_8UC3, cv::Scalar(0,0,0)){
    
}


void TreeVisualizer::displayTree(std::list<SstNode*> tree){
    
    for(auto it = tree.begin(); it != tree.end(); ++it){
        drawNode((*it));


    }

    //draw the root node
    V13d root_state;
    std::pair<int, int> center_pos = getPixelFromState(&root_state);

    cv::circle(tree_image, cv::Point(center_pos.first, center_pos.second), CIRCLE_RADIUS, cv::Scalar(255, 255, 0), -1);


    cv::namedWindow("Circle on Mat", cv::WINDOW_AUTOSIZE);
    cv::imshow("Circle on Mat", tree_image);
    cv::waitKey(0);
    
}

void TreeVisualizer::displayTree(std::list<SstNode*> tree, std::list<SstNeighborhood> neighborhoods){
    if(DISPLAY_NEIGHBORHOOD){
        for(auto it = neighborhoods.begin(); it != neighborhoods.end(); it++){
            V13d psuedo_state(it->center[0], it->center[1], 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
            std::pair<int, int> center_pos = getPixelFromState(&psuedo_state);
            cv::circle(tree_image, cv::Point(center_pos.first, center_pos.second), it->radius / TREE_IMAGE_BOUND * TREE_IMAGE_SIZE, cv::Scalar(0, 0, 255), SUBCIRCLE_RADIUS);
        } 
    }

    displayTree(tree);
}


void TreeVisualizer::drawNode(SstNode* node){

    //draw a point
    std::pair<int, int> center_pos = getPixelFromState(&(node->state));

    cv::circle(tree_image, cv::Point(center_pos.first, center_pos.second), CIRCLE_RADIUS, cv::Scalar(255, 0, 0), -1);

    if(DISPLAY_SUBSTATES){
        for(int i = 0; i < node->sub_states.size(); i++){
            std::pair<int, int> sub_center_pos1 = getPixelFromState(&(node->parent->state));

            if(i != 0){
                sub_center_pos1 = getPixelFromState(&(node->sub_states.at(i-1).second));
            }
            std::pair<int, int> sub_center_pos2 = getPixelFromState(&(node->sub_states.at(i).second));
            
            cv::line(tree_image, cv::Point(sub_center_pos1.first, sub_center_pos1.second), cv::Point(sub_center_pos2.first, sub_center_pos2.second), cv::Scalar(0, 255, 0), SUBCIRCLE_RADIUS);

        }
    }
}

std::pair<int, int> TreeVisualizer::getPixelFromState(V13d* state){
    //returns a rounded value for the pixel location of a node
    return{std::round((*state)[0] / TREE_IMAGE_BOUND * TREE_IMAGE_SIZE) + TREE_IMAGE_SIZE / 2, std::round((*state)[1] / TREE_IMAGE_BOUND * TREE_IMAGE_SIZE) + TREE_IMAGE_SIZE / 2};
}
