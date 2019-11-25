//
//  DistanceBetweenNodes.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef DistancesBetweenNodes_hpp
#define DistancesBetweenNodes_hpp

#include <stdio.h>
#include "MatrixOfFloat.hpp"
#include "GraphData.hpp"
#include "math.h"
 
class DistancesBetweenNodes : public MatrixOfFloat {
    //Atributes
private:

    //Constructors & Destructor
public:
    DistancesBetweenNodes(GraphData & graphData);
    
    //Methods
public:
    float getDistance(unsigned int node_A, unsigned int node_B);
    
private:
    float getDistanceBetweenTwoNodes(GraphData & graphData, unsigned int node_A, unsigned int node_B);
    float getDifferenceOnSetAttributeBetweenTwoNodes(GraphData & graphData, unsigned int attribute, unsigned int node_A, unsigned int node_B);
};


#endif /* DistancesBetweenNodes_hpp */
