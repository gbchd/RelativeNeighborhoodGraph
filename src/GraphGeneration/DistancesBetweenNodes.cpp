//
//  DistancesBetweenNodes.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "DistancesBetweenNodes.hpp"

/*
Constructors & Destructor
*/

/**
 @brief DistancesBetweenNodes' constructor that takes a GraphData as input and calculates every distances between every nodes.
 Since the distance is the same for AB and BA, the matrix is upper triangular.
 */
DistancesBetweenNodes::DistancesBetweenNodes(GraphData & graphData):MatrixOfFloat(graphData.getNumberOfRows(), graphData.getNumberOfRows()){
    //#pragma omp parallel for
    for (unsigned int row = 0; row < getNumberOfRows(); row++) {
        for (unsigned int column = 0; column < getNumberOfColumns(); column++) {
            if (row >= column) {
                setElement(row, column, 0);
            }
            else {
                setElement(row, column, getDistanceBetweenTwoNodes(graphData, row, column));
            }
        }
    }
}

/*
Public methods
*/

/**
 @brief accessor that return the distance between two nodes.
 */
float DistancesBetweenNodes::getDistance(unsigned int node_A, unsigned int node_B){
    if (node_A < node_B) {
        return getElement(node_A, node_B);
    }
    else {
        return getElement(node_B, node_A);
    }
}

/**
 @brief return the mean distance between every nodes as if the graph was complete.
 */
float DistancesBetweenNodes::calculateMeanDistance(){
    float meanDistance = 0;
    
    for (unsigned int row = 0; row < getNumberOfRows(); row++) {
        for (unsigned int column = row+1; column < getNumberOfColumns(); column++) {
            meanDistance += getDistance(row, column);
        }
    }
    
    unsigned int numberOfNodes = (getNumberOfColumns()*(getNumberOfColumns()-1))/2.0;
    meanDistance = meanDistance/numberOfNodes;
    
    return meanDistance;
}

/*
Private methods
*/
/**
 @brief calculate the distance between two nodes from the data of a GraphData object.
 */
float DistancesBetweenNodes::getDistanceBetweenTwoNodes(GraphData & graphData, unsigned int node_A, unsigned int node_B){
    float distanceBetweenNodeAandB = 0;
    for(unsigned int attribute = 0; attribute < graphData.getNumberOfColumns(); attribute++){
        float value = getDifferenceOnSetAttributeBetweenTwoNodes(graphData, attribute, node_A, node_B);
        distanceBetweenNodeAandB += (value * value);
    }
    return sqrtf(distanceBetweenNodeAandB);
}

/**
 @brief return the difference between the value of a given attribute of two different nodes.
 */
float DistancesBetweenNodes::getDifferenceOnSetAttributeBetweenTwoNodes(GraphData & graphData, unsigned int attribute, unsigned int node_A, unsigned int node_B){
    return graphData.getElement(node_A, attribute) - graphData.getElement(node_B, attribute);
}
