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

/**
@brief A TravelAlgorithmResult's constructor that takes the number of nodes as parameters.
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

/**
@brief Simple method that print this class using a specific format.
*/
void TravelAlgorithmResult::print(){
    std::cout << "Nodes | Number of nodes found again when inserted anywhere | Number of nodes that were used as insertion and found back the original node | Number of times the node was used to travel" << std::endl;
    for (unsigned int number = 0; number < foundAgainWhenInserted.size(); number++) {
        std::cout << number << " | " << foundAgainWhenInserted[number] << " | " << foundRightNodeWhenInsertedOn[number] << " | " << usedNodeToTravel[number] << " | " << meanDistanceToVertex[number] << " | " << meanTravelDistance[number] << " | " << minTravelDistance[number] << " | " << maxTravelDistance[number] << " | " << meanDistancesBetweenNodes << std::endl;
    }
    std::cout << std::endl;
}

/**
@brief Reset all the attributes of the class which results from the travel algorithm results..
The number of nodes doesn't change for example.
*/
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

/**
@brief Generate a list of neighbors (and neighbors of neighbors depends on the version) for all nodes of a given graph.
@param version 1 = list of neighbors, 2 = list of neighbors and neighbors of neighbors.
*/
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

/**
@brief Determine which travel algorithm we will use and apply it.
@param version 1 = list of neighbors, 2 = list of neighbors and neighbors of neighbors.
@param k size of the number of nodes that we will use to insert on. If it's k<=0 we will do one insertion on every nodes if it's k>0 then we generate a list of k random nodes.
*/
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



/*
Private Methods
*/


/**
@brief One iteration of the travel algorithm, we have a node to reach and a starting node.
We jump from node to node (within the list of neighbors) by finding the one closest to the node to reach, until we find no other nodes closer to the node to reach.
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

/**
@brief Setter for meanTravelDistance, maxTravelDistance and minTravelDistance.
*/
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

/**
@brief Find all neighbors of a given node within a certain graph and return them within a list.
*/
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

/**
@brief Find all neighbors and neighbors of neighbors of a given node within a certain graph and return them within a list.
*/
std::list<unsigned int> TravelAlgorithmResult::findAllNeighborsOfNeighborsOfNode(RNGraph &rngraph, unsigned int node){
    std::list<unsigned int> neighbors = findAllNeighborsOfNode(rngraph, node);
    std::list<unsigned int> neighborsOfNeighbors;
    for (unsigned int neighbor : neighbors) {
        std::list<unsigned int> neighborsOfNeighbor = findAllNeighborsOfNode(rngraph, neighbor);
        neighborsOfNeighbors.insert(neighborsOfNeighbors.end(), neighborsOfNeighbor.begin(), neighborsOfNeighbor.end());
    }
    return neighborsOfNeighbors;
}


/**
@brief Apply the travel algorithm using all nodes to insert on.
*/
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


/**
@brief Apply the travel algorithm using for each node a randomized list of k-nodes.
It is possible to use a k greater than the number of nodes of the graph. And the list might have the same node multiple times.
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

/**
@brief Generate a list of random nodes.
@param size is the given size of the list (the number of nodes to generate).
@param bannedValue is a value that is banned from thee generation (we can't generate the node to reach within the list of starting nodes with this.)
This method can generate the same number multiple times.
See https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution for the random generation method.
*/
std::vector<unsigned int> TravelAlgorithmResult::generateRandomVectorOfNodes(unsigned int size, unsigned int bannedValue){
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, numberOfNodes-1);
    
    std::vector<unsigned int> nodes;
    while (nodes.size() < size) {
        int node = dis(gen); //Returns a random integer between 0 and numberOfNodes-1
        if (node != bannedValue) {
            nodes.push_back(node);
        }
    }
    return nodes;
}
