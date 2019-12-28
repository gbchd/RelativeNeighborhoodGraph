//
//  TravelAlgorithmResult.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef TravelAlgorithmResult_hpp
#define TravelAlgorithmResult_hpp

#include <stdio.h>
#include <list>
#include <random>
#include "MatrixOfFloat.hpp"
#include "RNGraph.hpp"
#include "DistancesBetweenNodes.hpp"
#include "ProgressBar.hpp"

/**
 @name TravelAlgorithmResult
 @brief A class that contains all the stats that results from the travel algorithm.
 */
class TravelAlgorithmResult {
    //Atributes
private:
    std::vector<unsigned int> foundAgainWhenInserted;
    std::vector<unsigned int> foundRightNodeWhenInsertedOn;
    std::vector<unsigned int> usedNodeToTravel;
    
    std::vector<float> meanDistanceToVertex; //mean distance to vertex when failed to insert on
    
    std::vector<float> meanTravelDistance;
    std::vector<float> minTravelDistance;
    std::vector<float> maxTravelDistance;
    
    float meanDistancesBetweenNodes;
    
    std::vector<std::vector<unsigned int>> neighbors;
    
    unsigned int numberOfNodes;
    
    //Constructors & Destructor
public:
    /**
     @brief A TravelAlgorithmResult's constructor that takes the number of nodes as parameters.
     */
    explicit TravelAlgorithmResult(unsigned int size);
    
    //Methods
public:
    //Getters
    unsigned int getNumberOfNodes(){return numberOfNodes;}
    unsigned int getElementFromFoundAgainWhenInserted(unsigned int index) { return foundAgainWhenInserted[index]; }
    unsigned int getElementFromFoundRightNodeWhenInsertedOn(unsigned int index) { return foundRightNodeWhenInsertedOn[index]; }
    unsigned int getElementFromUsedNodeToTravel(unsigned int index) { return usedNodeToTravel[index]; }
    float getElementFromMeanDistanceToVertex(unsigned int index) { return meanDistanceToVertex[index]; }
    float getElementFromMeanTravelDistance(unsigned int index) { return meanTravelDistance[index]; }
    float getElementFromMinTravelDistance(unsigned int index) { return minTravelDistance[index]; }
    float getElementFromMaxTravelDistance(unsigned int index) { return maxTravelDistance[index]; }
    float getMeanDistancesBetweenNodes(){ return meanDistancesBetweenNodes; }

    /**
     @brief Simple method that print this class using a specific format.
     */
    void print();
    
    /**
     @brief Reset all the attributes of the class which results from the travel algorithm results..
     The number of nodes doesn't change for example.
     */
    void reset();
    
    /**
     @brief Generate a list of neighbors (and neighbors of neighbors depends on the version) for all nodes of a given graph.
     @param version 1 = list of neighbors, 2 = list of neighbors and neighbors of neighbors.
     */
    void generateNeighbors(RNGraph & rngraph, unsigned int version);
    
    /**
     @brief Determine which travel algorithm we will use and apply it.
     @param version 1 = list of neighbors, 2 = list of neighbors and neighbors of neighbors.
     @param k size of the number of nodes that we will use to insert on. If it's k<=0 we will do one insertion on every nodes if it's k>0 then we generate a list of k random nodes.
     */
    void generateResultsWithNeighborAlgorithm(DistancesBetweenNodes & distancesBetweenNodes, unsigned int version, int k);
    
    
private:
    /**
     @brief One iteration of the travel algorithm, we have a node to reach and a starting node.
     We jump from node to node (within the list of neighbors) by finding the one closest to the node to reach, until we find no other nodes closer to the node to reach.
     */
    void neighborAlgorithm(unsigned int nodeToReach, unsigned int nodeStart, DistancesBetweenNodes & distancesBetweenNodes);
    
    /**
     @brief Setter for meanTravelDistance, maxTravelDistance and minTravelDistance.
     */
    void setDistanceForTheTravelDistance(unsigned int node, float distance);
    
    /**
     @brief Find all neighbors of a given node within a certain graph and return them within a list.
     */
    std::list<unsigned int> findAllNeighborsOfNode(RNGraph & rngraph, unsigned int node);
    /**
    @brief Find all neighbors and neighbors of neighbors of a given node within a certain graph and return them within a list.
    */
    std::list<unsigned int> findAllNeighborsOfNeighborsOfNode(RNGraph & rngraph, unsigned int node);
    
    /**
     @brief Apply the travel algorithm using all nodes to insert on.
     */
    void generateResultsWithNeighborAlgorithmOnAllNodes(DistancesBetweenNodes & distancesBetweenNodes);
    
    /**
     @brief Apply the travel algorithm using for each node a randomized list of k-nodes.
     It is possible to use a k greater than the number of nodes of the graph. And the list might have the same node multiple times
     */
    void generateResultsWithNeighborAlgorithmOnRandomVector(DistancesBetweenNodes & distancesBetweenNodes,  unsigned int sizeOfVector);
    
    /**
     @brief Generate a list of random nodes.
     @param size is the given size of the list (the number of nodes to generate).
     @param bannedValue is a value that is banned from thee generation (we can't generate the node to reach within the list of starting nodes with this.)
     */
    std::vector<unsigned int> generateRandomVectorOfNodes(unsigned int size, unsigned int bannedValue);
};




#endif /* TravelAlgorithmResult_hpp */
