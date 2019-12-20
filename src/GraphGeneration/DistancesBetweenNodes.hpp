//
//  DistancesBetweenNodes.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
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
    float calculateMeanDistance();
    
private:
    float getDistanceBetweenTwoNodes(GraphData & graphData, unsigned int node_A, unsigned int node_B);
    float getDifferenceOnSetAttributeBetweenTwoNodes(GraphData & graphData, unsigned int attribute, unsigned int node_A, unsigned int node_B);
};


#endif /* DistancesBetweenNodes_hpp */
