//
//  DistanceBetweenNodes.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef MatrixOfDistanceBetweenNodes_hpp
#define MatrixOfDistanceBetweenNodes_hpp

#include <stdio.h>
#include "MatrixOfFloat.hpp"
#include "GraphData.hpp"
#include "math.h"
 
class MatrixOfDistanceBetweenNodes : public MatrixOfFloat {
    //Atributes
private:

    //Constructors & Destructor
public:
    MatrixOfDistanceBetweenNodes(GraphData & graphData);
    
    //Methods
public:
    float getDistance(unsigned int node_A, unsigned int node_B);
    
private:
    float getDistanceBetweenTwoNodes(GraphData & graphData, unsigned int node_A, unsigned int node_B);
    float getDifferenceOnSetAttributeBetweenTwoNodes(GraphData & graphData, unsigned int attribute, unsigned int node_A, unsigned int node_B);
};


#endif /* MatrixOfDistanceBetweenNodes_hpp */
