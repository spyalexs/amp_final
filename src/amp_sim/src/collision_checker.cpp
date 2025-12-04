#include "amp_sim/collision_checker.hpp"

Plane::Plane(std::vector<v3d> Points){

    if(Points.size() != 4){
        printf("Plane failed to init. Size: %ld \n", Points.size());
    }

    points = Points;

    //determine the plane eq

    v3d plane_vec_1 = points.at(1) - points.at(0);
    v3d plane_vec_2 = points.at(2) - points.at(0);
    v3d ortho_vec = plane_vec_2.cross(plane_vec_1);

    plane_eq[0] = ortho_vec.dot(points.at(0));
    plane_eq[1] = ortho_vec[0];
    plane_eq[2] = ortho_vec[1];
    plane_eq[3] = ortho_vec[2];

    ortho_vector_mat << plane_vec_1, plane_vec_2, ortho_vec;
}

bool Plane::check_segment_collision(v3d p1, v3d p2){
    
    //i dont have anything to write on lol
    //direction unit = (p2 - p1).normalize()
    // need to find x where (x * direction_unit + p1) *  plane_eq[1-3] = plane_eq[0]
    //alternatively (plane_eq[0] - plane_eq[1-3] * p1) / (direction_unit * plane_eq[1-3]) = x

    v3d direction_unit = (p2 - p1).normalized();

    if((direction_unit.dot(plane_eq.block<3,1>(1,0))) == 0){
        return false;
    }

    double x = (plane_eq[0] - plane_eq.block<3,1>(1,0).dot(p1)) / (direction_unit.dot(plane_eq.block<3,1>(1,0)));

    v3d intersection_location = p1 + direction_unit * x;

    //printf("Intersection at %f %f %f \n", intersection_location[0], intersection_location[1], intersection_location[2]);

    if(x > (p2 - p1).norm() || x < 0){
        //segment doesn't reach the plane

        return false;
    }

    //determine if the intersection location is within the plane bounds
    v3d d_point_zero = intersection_location - points.at(0);

    v3d ortho_components = ortho_vector_mat.inverse() * d_point_zero;
    if(ortho_components[0] > 1 || ortho_components[0] < 0 || ortho_components[1] > 1 || ortho_components[1] < 0){
        //itersection outside of the plane
        return false;
    }

    return true;
}

RectPrism::RectPrism(v3d dim, v3d Center, double yaw, double pitch){
    //points will be in the order
    //[ppp ,ppn, pnp, pnn, npp, npn, nnp, nnn]

    center = Center;

    m3d rot_yaw;
    rot_yaw << cos(yaw), -sin(yaw), 0,
                    sin(yaw), cos(yaw), 0,
                    0,0,1;

    m3d rot_pit; 
    rot_pit << cos(pitch), 0, sin(pitch),
                    0, 1, 0,
                    -sin(pitch), 0, cos(pitch);

    //fomulate the points that bound the prism
    points.push_back(rot_pit * rot_yaw * v3d(1,1,1).cwiseProduct(dim / 2) + center);
    points.push_back(rot_pit * rot_yaw * v3d(1,1,-1).cwiseProduct(dim / 2) + center);
    points.push_back(rot_pit * rot_yaw * v3d(1,-1,1).cwiseProduct(dim / 2) + center);
    points.push_back(rot_pit * rot_yaw * v3d(1,-1,-1).cwiseProduct(dim / 2) + center);
    points.push_back(rot_pit * rot_yaw * v3d(-1,1,1).cwiseProduct(dim / 2) + center);
    points.push_back(rot_pit * rot_yaw * v3d(-1,1,-1).cwiseProduct(dim / 2) + center);
    points.push_back(rot_pit * rot_yaw * v3d(-1,-1,1).cwiseProduct(dim / 2) + center);
    points.push_back(rot_pit * rot_yaw * v3d(-1,-1,-1).cwiseProduct(dim / 2) + center);

    insta_radius = dim.norm() / 2;
}

std::vector<Plane> RectPrism::getPlanes(){

    //get the planes that form the prisim
    std::vector<Plane> planes;
    std::vector<v3d> plane_points;

    //front plane
    plane_points.push_back(points[0]);
    plane_points.push_back(points[1]);
    plane_points.push_back(points[3]);
    plane_points.push_back(points[2]);
    planes.push_back(Plane(plane_points));

    //back plane
    plane_points.clear();
    plane_points.push_back(points[4]);
    plane_points.push_back(points[5]);
    plane_points.push_back(points[7]);
    plane_points.push_back(points[6]);
    planes.push_back(Plane(plane_points));
    
    //bottom
    plane_points.clear();
    plane_points.push_back(points[1]);
    plane_points.push_back(points[3]);
    plane_points.push_back(points[7]);
    plane_points.push_back(points[5]);
    planes.push_back(Plane(plane_points));

    //top
    plane_points.clear();
    plane_points.push_back(points[0]);
    plane_points.push_back(points[2]);
    plane_points.push_back(points[6]);
    plane_points.push_back(points[4]);
    planes.push_back(Plane(plane_points));

    //yp
    plane_points.clear();
    plane_points.push_back(points[0]);
    plane_points.push_back(points[1]);
    plane_points.push_back(points[5]);
    plane_points.push_back(points[4]);
    planes.push_back(Plane(plane_points));

    //yn
    plane_points.clear();
    plane_points.push_back(points[2]);
    plane_points.push_back(points[3]);
    plane_points.push_back(points[7]);
    plane_points.push_back(points[6]);
    planes.push_back(Plane(plane_points));

    return planes;
}

std::vector<std::pair<v3d, v3d>> RectPrism::get_segments(){
    std::vector<std::pair<v3d, v3d>> segments;

    //front plane
    segments.push_back({points.at(0), points.at(1)});
    segments.push_back({points.at(1), points.at(2)});
    segments.push_back({points.at(2), points.at(3)});
    segments.push_back({points.at(3), points.at(0)});

    //back plane
    segments.push_back({points.at(4), points.at(5)});
    segments.push_back({points.at(5), points.at(6)});
    segments.push_back({points.at(6), points.at(7)});
    segments.push_back({points.at(7), points.at(4)});

    //segments connecting front and back planes
    segments.push_back({points.at(0), points.at(4)});
    segments.push_back({points.at(1), points.at(5)});
    segments.push_back({points.at(2), points.at(6)});
    segments.push_back({points.at(3), points.at(7)});

    return segments;
}

bool RectPrism::checkPrismCollision(RectPrism prism){

    //quickly check to see if a collision is even a question...
    // if((prism.center - center).norm() > insta_radius + prism.insta_radius){
    //     return false;
    // }

    //check this prism's planes with the other prism's segments

    std::vector<Plane> planes = getPlanes();
    //printf("Here1\n");
    std::vector<std::pair<v3d, v3d>> segments = prism.get_segments();

    //iterate through planes
    for(int i = 0; i < planes.size(); i++){

        //iterate through segments
        for(int j = 0; j < segments.size(); j++){

            //printf("Here %d %d \n", i, j);

            if(planes.at(i).check_segment_collision(segments.at(j).first, segments.at(j).second)){
                return true;
            }
        }
    }

    planes = prism.getPlanes();
    segments = get_segments();

    for(int i = 0; i < planes.size(); i++){

        //iterate through segments
        for(int j = 0; j < segments.size(); j++){

            //printf("Here %d %d \n", i, j);

            if(planes.at(i).check_segment_collision(segments.at(j).first, segments.at(j).second)){
                return true;
            }
        }
    }

    //no collisions4
    return false;
}

bool RectPrism::checkPrismsCollision(std::vector<RectPrism> prisms){

    //check the prisim againist an array of other prisms

    for(int i = 0; i < prisms.size(); i++){
        if(checkPrismCollision(prisms.at(i))){
            return true;
        }
    }

    return false;
}








