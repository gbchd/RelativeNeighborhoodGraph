//
//  RNGraph.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "RNGraph.hpp"

/*
Constructors & Destructor
*/
RNGraph::RNGraph(DistancesBetweenNodes & distancesBetweenNodes):MatrixOfBoolean(distancesBetweenNodes.getNumberOfRows(), distancesBetweenNodes.getNumberOfRows()){
    
    
    #pragma omp parallel for
    for (int row = 0; row < getNumberOfRows(); row++) {
        for (unsigned int column = 0; column < getNumberOfColumns(); column++) {
            //For each element of our matrix, we set it at false by default..
            setElement(row, column, false);
            
            //If it's in the matrix' upper right corner and if there is no node closer to the two nodes (row, column) then we set it at true
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
    //true if there is no : dist(nodeA nodeX) < dist(nodeA nodeB) AND dist(nodeB nodeX) < dist(nodeA nodeB)
    for (unsigned int node = 0; node < getNumberOfRows(); node++) {
        if(distancesBetweenNodes.getDistance(node, node_A) < distanceBetweenAandB && distancesBetweenNodes.getDistance(node, node_B) < distanceBetweenAandB){
            return false;
        }
    }
    return true;
    
}

