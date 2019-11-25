//
//  RNGraph.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include "RNGraph.hpp"

/*
Constructors & Destructor
*/
RNGraph::RNGraph(DistancesBetweenNodes & distancesBetweenNodes):MatrixOfBoolean(distancesBetweenNodes.getNumberOfRows(), distancesBetweenNodes.getNumberOfRows()){
   
    #pragma omp parallel for
    for (unsigned int row = 0; row < getNumberOfRows(); row++) {
        for (unsigned int column = 0; column < getNumberOfColumns(); column++) {
            setElement(row, column, false);
            if (row < column && isThereAnEdgeBetweenTwoNodes(distancesBetweenNodes, row, column)) {
                setElement(row, column, true);
            }
        }
    }
    
    
}

/*
Public methods
*/

/*
Private methods
*/

bool RNGraph::isThereAnEdgeBetweenTwoNodes(DistancesBetweenNodes & distancesBetweenNodes, unsigned int node_A, unsigned int node_B){
    float distanceBetweenAandB = distancesBetweenNodes.getDistance(node_A, node_B);
    if(isThereANodeCloserThan(distancesBetweenNodes, distanceBetweenAandB, node_A) && isThereANodeCloserThan(distancesBetweenNodes, distanceBetweenAandB, node_B)){
        return true;
    }
    return false;
}

bool RNGraph::isThereANodeCloserThan(DistancesBetweenNodes & distancesBetweenNodes, float distance, unsigned int node){
    if(isDistanceTheMinInList(distancesBetweenNodes.getRowBeforeLimit(node, node), distance)){
        return true;
    }
    if(isDistanceTheMinInList(distancesBetweenNodes.getColumnAfterLimit(node, node), distance)){
        return true;
    }
    return false;
}


bool RNGraph::isDistanceTheMinInList(std::vector<float> list, unsigned int valueToTest){
    for (unsigned int iterator = 0; iterator < list.size(); iterator++) {
        if (list[iterator] < valueToTest) {
            return true;
        }
    }
    return false;
}

