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

    void print();
    
    void generateResultsWithNeighborAlgorithmV1(DistancesBetweenNodes & distancesBetweenNodes);
    void generateResultsWithNeighborAlgorithmV2(DistancesBetweenNodes & distancesBetweenNodes);
    
    void reset();
    
    void generateNeighbors(RNGraph & rngraph, unsigned int version);
    
private:
    void neighborAlgorithmV1(unsigned int nodeToReach, unsigned int nodeStart, DistancesBetweenNodes & distancesBetweenNodes);
    void neighborAlgorithmV2(unsigned int nodeToReach, unsigned int nodeStart, DistancesBetweenNodes & distancesBetweenNodes);
    
    std::list<unsigned int> findAllNeighborsOfNode(RNGraph & rngraph, unsigned int node);
    std::list<unsigned int> findAllNeighborsOfNeighborsOfNode(RNGraph & rngraph, unsigned int node);
    

};




#endif /* TravelAlgorithmResult_hpp */
