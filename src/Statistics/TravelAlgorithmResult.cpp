//
//  TravelAlgorithmResult.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include "TravelAlgorithmResult.hpp"

/*
Constructors & Destructor
*/

TravelAlgorithmResult::TravelAlgorithmResult(unsigned int size){
    numberOfNodes = size;
    for (unsigned int node = 0; node < numberOfNodes; node++) {
        foundAgainWhenInserted.push_back(0);
        foundRightNodeWhenInsertedOn.push_back(0);
        usedNodeToTravel.push_back(0);
    }
    
}


/*
Public Methods
*/



void TravelAlgorithmResult::generateResultsWithNeighborAlgorithmV1(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes){
    if(!isTheSameSize(rngraph, distancesBetweenNodes)){
        throw "NotTheSameSizeError";
    }
    
    for (unsigned int row = 0; row < rngraph.getNumberOfRows(); row++) {
        for (unsigned int column = 0; column < rngraph.getNumberOfColumns(); column++) {
            neighborAlgorithmV1(row, column, rngraph, distancesBetweenNodes);
        }
    }
    
    
    //Not finished
    
    
}

void TravelAlgorithmResult::generateResultsWithNeighborAlgorithmV2(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes){
    if(!isTheSameSize(rngraph, distancesBetweenNodes)){
        throw "NotTheSameSizeError";
    }
    
    //Not finished
}



/*
Private Methods
*/

bool TravelAlgorithmResult::isTheSameSize(MatrixOfFloat &matrixA, MatrixOfBoolean &matrixB){
    if(matrixA.getNumberOfRows() == matrixB.getNumberOfRows() && matrixA.getNumberOfColumns() == matrixB.getNumberOfColumns()){
        return true;
    }
    else{
        return false;
    }
}

bool TravelAlgorithmResult::isTheSameSize(MatrixOfBoolean &matrixA, MatrixOfFloat &matrixB){
    if(matrixA.getNumberOfRows() == matrixB.getNumberOfRows() && matrixA.getNumberOfColumns() == matrixB.getNumberOfColumns()){
        return true;
    }
    else{
        return false;
    }
}

/*
 Travel algorithm from one node to another
 */
void TravelAlgorithmResult::neighborAlgorithmV1(unsigned int nodeToReach, unsigned int nodeStart, RNGraph &rngraph, DistancesBetweenNodes &distancesBetweenNodes){
    //Initialisation
    unsigned int lastNode = rngraph.getNumberOfColumns()+1;
    unsigned int currentNode = nodeStart; //impossible value at initialization
    
    //Déroulement
    while(lastNode != currentNode && currentNode != nodeToReach){
        
        lastNode = currentNode;
        
        std::list<unsigned int> neighbors = findAllNeighborsOfNode(rngraph, lastNode);
        
        for (unsigned int neighbor : neighbors) {
            if(distancesBetweenNodes.getDistance(currentNode, nodeToReach) > distancesBetweenNodes.getDistance(neighbor, nodeToReach)){
                currentNode = neighbor;
            }
        }
        
        usedNodeToTravel[currentNode] +=1;
        
    }
    
    if(currentNode == nodeToReach){
        foundAgainWhenInserted[nodeToReach] += 1;
        foundRightNodeWhenInsertedOn[nodeStart] +=1;
    }
    
    
    
    
}




std::list<unsigned int> TravelAlgorithmResult::findAllNeighborsOfNode(RNGraph & rngraph, unsigned int node){
    std::list<unsigned int> neighbors;
    neighbors.push_back(node);
    for (unsigned int row = 0; row < node; row++) {
        if (rngraph.getElement(row, node) == true) {
            neighbors.push_back(row);
        }
    }
    
    for (unsigned int column = node; column < rngraph.getNumberOfColumns(); column++) {
        if (rngraph.getElement(node, column) == true) {
            neighbors.push_back(column);
        }
    }
    
    return neighbors;
}
