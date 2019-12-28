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
 
/**
 @name DistancesBetweenNodes
 @brief A upper triangle matrix that stocks the distances between every nodes of a graph.
 These distances are generated from the data of a GraphData object.
 */
class DistancesBetweenNodes : public MatrixOfFloat {
    //Constructors & Destructor
public:
    /**
    @brief DistancesBetweenNodes' constructor that takes a GraphData as input and calculates every distances between every nodes.
    Since the distance is the same for AB and BA, the matrix is upper triangular.
    */
    explicit DistancesBetweenNodes(GraphData & graphData);
    
    //Methods
public:
    /**
    @brief accessor that return the distance between two nodes.
    */
    float getDistance(unsigned int node_A, unsigned int node_B);
    /**
    @brief return the mean distance between every nodes as if the graph was complete.
    */
    float calculateMeanDistance();
    
private:
    /**
    @brief calculate the distance between two nodes from the data of a GraphData object.
    */
    float getDistanceBetweenTwoNodes(GraphData & graphData, unsigned int node_A, unsigned int node_B);
    /**
    @brief return the difference between the value of a given attribute of two different nodes.
    */
    float getDifferenceOnSetAttributeBetweenTwoNodes(GraphData & graphData, unsigned int attribute, unsigned int node_A, unsigned int node_B);
};


#endif /* DistancesBetweenNodes_hpp */
