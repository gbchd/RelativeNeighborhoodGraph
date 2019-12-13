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
#include "MatrixOfFloat.hpp"
#include "RNGraph.hpp"
#include "DistancesBetweenNodes.hpp"
#include "ProgressBar.hpp"


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
    
    std::vector<std::vector<unsigned int>> neighbors;
    
    unsigned int numberOfNodes;
    
    //Constructors & Destructor
public:
    TravelAlgorithmResult(unsigned int size);
    
    //Methods
public:
    unsigned int getNumberOfNodes(){return numberOfNodes;}
    unsigned int getElementFromFoundAgainWhenInserted(unsigned int index) { return foundAgainWhenInserted[index]; }
    unsigned int getElementFromFoundRightNodeWhenInsertedOn(unsigned int index) { return foundRightNodeWhenInsertedOn[index]; }
    unsigned int getElementFromUsedNodeToTravel(unsigned int index) { return usedNodeToTravel[index]; }
    float getElementFromMeanDistanceToVertex(unsigned int index) { return meanDistanceToVertex[index]; }
    float getElementFromMeanTravelDistance(unsigned int index) { return meanTravelDistance[index]; }
    float getElementFromMinTravelDistance(unsigned int index) { return minTravelDistance[index]; }
    float getElementFromMaxTravelDistance(unsigned int index) { return maxTravelDistance[index]; }

    void print();
    
    void generateResultsWithNeighborAlgorithmV1(DistancesBetweenNodes & distancesBetweenNodes);
    void generateResultsWithNeighborAlgorithmV2(DistancesBetweenNodes & distancesBetweenNodes);
    void generateResultsWithNeighborAlgorithmV3(DistancesBetweenNodes & distancesBetweenNodes, unsigned int k, unsigned int version);
    
    void reset();
    
    void generateNeighbors(RNGraph & rngraph, unsigned int version);
    
private:
    void neighborAlgorithm(unsigned int nodeToReach, unsigned int nodeStart, DistancesBetweenNodes & distancesBetweenNodes);
    
    void setDistanceForTheTravelDistance(unsigned int node, float distance);
    
    std::list<unsigned int> findAllNeighborsOfNode(RNGraph & rngraph, unsigned int node);
    std::list<unsigned int> findAllNeighborsOfNeighborsOfNode(RNGraph & rngraph, unsigned int node);
    

};




#endif /* TravelAlgorithmResult_hpp */
