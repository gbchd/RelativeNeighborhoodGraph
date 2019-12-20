//
//  TravelAlgorithmResult.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "TravelAlgorithmResult.hpp"

/*
Constructors & Destructor
*/

TravelAlgorithmResult::TravelAlgorithmResult(unsigned int size){
    numberOfNodes = size;
    meanDistancesBetweenNodes = 0;
    for (unsigned int node = 0; node < numberOfNodes; node++) {
        foundAgainWhenInserted.push_back(0);
        foundRightNodeWhenInsertedOn.push_back(0);
        usedNodeToTravel.push_back(0);
        
        meanTravelDistance.push_back(0);
        minTravelDistance.push_back(std::numeric_limits<float>::max());
        maxTravelDistance.push_back(0);
        
        meanDistanceToVertex.push_back(0);
    }
    neighbors.resize(numberOfNodes);
    
}


/*
Public Methods
*/

void TravelAlgorithmResult::print(){
    std::cout << "Nodes | Number of nodes found again when inserted anywhere | Number of nodes that were used as insertion and found back the original node | Number of times the node was used to travel" << std::endl;
    for (unsigned int number = 0; number < foundAgainWhenInserted.size(); number++) {
        std::cout << number << " | " << foundAgainWhenInserted[number] << " | " << foundRightNodeWhenInsertedOn[number] << " | " << usedNodeToTravel[number] << " | " << meanDistanceToVertex[number] << " | " << meanTravelDistance[number] << " | " << minTravelDistance[number] << " | " << maxTravelDistance[number] << " | " << meanDistancesBetweenNodes << std::endl;
    }
    std::cout << std::endl;
}


void TravelAlgorithmResult::generateResultsWithNeighborAlgorithm(DistancesBetweenNodes &distancesBetweenNodes, unsigned int version, int k){
    if (neighbors.size() != distancesBetweenNodes.getNumberOfRows() || numberOfNodes != distancesBetweenNodes.getNumberOfRows()) {
        throw "NotTheSameSizeError";
    }
    if (version != 1 && version != 2) {
        throw "UnknownAlgorithmVersion";
    }
    
    reset();
    
    meanDistancesBetweenNodes = distancesBetweenNodes.calculateMeanDistance();
    
    
    if (k <= 0) {
        generateResultsWithNeighborAlgorithmOnAllNodes(distancesBetweenNodes);
    }
    else {
        generateResultsWithNeighborAlgorithmOnRandomVector(distancesBetweenNodes, k);
    }
        
}



void TravelAlgorithmResult::reset(){
    for (unsigned int node = 0; node < numberOfNodes; node++) {
        foundRightNodeWhenInsertedOn[node] = 0;
        foundAgainWhenInserted[node] = 0;
        usedNodeToTravel[node] = 0;
        meanDistanceToVertex[node] = 0;
        meanTravelDistance[node] = 0;
        minTravelDistance[node] = std::numeric_limits<float>::max();
        maxTravelDistance[node] = 0;
        meanDistancesBetweenNodes = 0;
    }
}


void TravelAlgorithmResult::generateNeighbors(RNGraph &rngraph, unsigned int version){
    unsigned int numberOfNodes = rngraph.getNumberOfRows();
    
    if (version == 1) {
        for (unsigned int node = 0; node < numberOfNodes; node++) {
            std::list<unsigned int> neighborsToSet = findAllNeighborsOfNode(rngraph, node);
            for (unsigned int elem : neighborsToSet) {
                neighbors[node].push_back(elem);
            }
        }
    }
    if (version == 2) {
        for (unsigned int node = 0; node < numberOfNodes; node++) {
            std::list<unsigned int> neighborsToSet = findAllNeighborsOfNeighborsOfNode(rngraph, node);
            for (unsigned int elem : neighborsToSet) {
                neighbors[node].push_back(elem);
            }
        }
    }
}



/*
Private Methods
*/


/*
 Travel algorithm from one node to another
 */
void TravelAlgorithmResult::neighborAlgorithm(unsigned int nodeToReach, unsigned int nodeStart, DistancesBetweenNodes &distancesBetweenNodes){
    //Initialisation
    unsigned int lastNode = distancesBetweenNodes.getNumberOfColumns()+1;
    unsigned int currentNode = nodeStart; //impossible value at initialization
    
    float distance = 0;
    
    //Déroulement
    while(lastNode != currentNode && currentNode != nodeToReach){
        
        lastNode = currentNode;
        
        for (unsigned int neighbor : neighbors[lastNode]) {
            if(distancesBetweenNodes.getDistance(currentNode, nodeToReach) > distancesBetweenNodes.getDistance(neighbor, nodeToReach)){
                currentNode = neighbor;
            }
        }
        
        
        distance += distancesBetweenNodes.getDistance(lastNode, currentNode);
        usedNodeToTravel[currentNode] +=1;
        
    }
    
    //We exclude the case where the node that we try to reach is the same as the node selected start the travel algorithm.
    //That changes the minTravelDistance so that it's not always 0. It doesn't change the mean and the max since the distance = 0 in this case.
    if (nodeStart != nodeToReach) {
        setDistanceForTheTravelDistance(nodeToReach, distance);
    }
    
    if(currentNode == nodeToReach){
        foundAgainWhenInserted[nodeToReach] += 1;
        foundRightNodeWhenInsertedOn[nodeStart] +=1;
    }
    else{
        meanDistanceToVertex[nodeToReach] += distancesBetweenNodes.getDistance(nodeToReach, currentNode);
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

std::list<unsigned int> TravelAlgorithmResult::findAllNeighborsOfNeighborsOfNode(RNGraph &rngraph, unsigned int node){
    std::list<unsigned int> neighbors = findAllNeighborsOfNode(rngraph, node);
    std::list<unsigned int> neighborsOfNeighbors;
    for (unsigned int neighbor : neighbors) {
        std::list<unsigned int> neighborsOfNeighbor = findAllNeighborsOfNode(rngraph, neighbor);
        neighborsOfNeighbors.insert(neighborsOfNeighbors.end(), neighborsOfNeighbor.begin(), neighborsOfNeighbor.end());
    }
    return neighborsOfNeighbors;
}


void TravelAlgorithmResult::setDistanceForTheTravelDistance(unsigned int node, float distance){
    // We test if the distance is the max
    if(distance > maxTravelDistance[node]){
        maxTravelDistance[node] = distance;
    }
    
    //We add to the sum of all travel distances
    meanTravelDistance[node] += distance;
    
    //We test if the distance is the min
    if(distance < minTravelDistance[node]){
        minTravelDistance[node] = distance;
    }
}



void TravelAlgorithmResult::generateResultsWithNeighborAlgorithmOnAllNodes(DistancesBetweenNodes & distancesBetweenNodes){
    
    //We check if the two matrix are of the same size
    if(neighbors.size() != distancesBetweenNodes.getNumberOfRows()){
        throw "NotTheSameSizeError";
    }
    
    ProgressBar progressBar;
    progressBar.initialize(distancesBetweenNodes.getNumberOfRows());
    
    #pragma omp parallel for
    for (int row = 0; row < distancesBetweenNodes.getNumberOfRows(); row++) {
        progressBar.update();
        for (unsigned int column = 0; column < distancesBetweenNodes.getNumberOfColumns(); column++) {
            neighborAlgorithm(row, column, distancesBetweenNodes);
        }
        
        //We get the mean of the travel distances.
        meanTravelDistance[row] = meanTravelDistance[row]/numberOfNodes;
        
        //We get the mean of the distances when failed by dividing the sum stocked in meanDistanceToVertex by the number of time the insertion failed.
        meanDistanceToVertex[row] = (meanDistanceToVertex[row])/(numberOfNodes-foundAgainWhenInserted[row]);
        
    }
}

/*
 It is possible to use a k greater than the number of nodes of the graph. And the list might have the same node multiple times
*/
void TravelAlgorithmResult::generateResultsWithNeighborAlgorithmOnRandomVector(DistancesBetweenNodes & distancesBetweenNodes, unsigned int sizeOfVector) {
    if (neighbors.size() != distancesBetweenNodes.getNumberOfRows()) {
        throw "NotTheSameSizeError";
    }

    ProgressBar progressBar;
    progressBar.initialize(distancesBetweenNodes.getNumberOfRows());

    #pragma omp parallel for
    for (int node = 0; node < distancesBetweenNodes.getNumberOfRows(); node++) {

        progressBar.update();
        
        std::vector<unsigned int> nodesToInsertOn = generateRandomVectorOfNodes(sizeOfVector, node);
        
        //Then we apply the algorithm only on the selected vertices :
        for (unsigned int nodeToInsertOn : nodesToInsertOn){
            neighborAlgorithm(node, nodeToInsertOn, distancesBetweenNodes);
        }
        
        //We get the mean of the travel distances.
        meanTravelDistance[node] = meanTravelDistance[node]/sizeOfVector;
        //We get the mean of the distances when failed by dividing the sum stocked in meanDistanceToVertex by the number of time the insertion failed.
        unsigned int numberOfTimeTheInsertionFailed = sizeOfVector-foundAgainWhenInserted[node];
        if(numberOfTimeTheInsertionFailed == 0){
            meanDistanceToVertex[node] = 0;
        }
        else{
            meanDistanceToVertex[node] = meanDistanceToVertex[node]/numberOfTimeTheInsertionFailed;
        }
    }
}

//Can generate the same number multiple times
std::vector<unsigned int> TravelAlgorithmResult::generateRandomVectorOfNodes(unsigned int size, unsigned int bannedValue){
    srand((unsigned int)time(NULL));
    std::vector<unsigned int> nodes;
    while (nodes.size() < size) {
        int node = rand() % numberOfNodes; //Returns a random integer between 0 and numberOfNodes-1
        if (node != bannedValue) {
            nodes.push_back(node);
        }
    }
    return nodes;
}
