//
//  TravelAlgorithmResult.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef TravelAlgorithmResult_hpp
#define TravelAlgorithmResult_hpp

#include <stdio.h>
#include <list>
#include "MatrixOfFloat.hpp"
#include "RNGraph.hpp"
#include "DistancesBetweenNodes.hpp"


class TravelAlgorithmResult {
    //Atributes
private:
    std::vector<unsigned int> foundAgainWhenInserted;
    std::vector<unsigned int> foundRightNodeWhenInsertedOn;
    std::vector<unsigned int> usedNodeToTravel;
    
    unsigned int numberOfNodes;
    
    //Constructors & Destructor
public:
    TravelAlgorithmResult(unsigned int size);
    
    //Methods
public:
    unsigned int getNumberOfNodes();
    
    void generateResultsWithNeighborAlgorithmV1(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes);
    void generateResultsWithNeighborAlgorithmV2(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes);
    
private:
    bool isTheSameSize(MatrixOfFloat & matrixA, MatrixOfBoolean & matrixB);
    bool isTheSameSize(MatrixOfBoolean & matrixA, MatrixOfFloat & matrixB);
    
    void neighborAlgorithmV1(unsigned int nodeToReach, unsigned int nodeStart, RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes);
    void neighborAlgorithmV2(unsigned int nodeToReach, unsigned int nodeStart, RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes);
    
    std::list<unsigned int> findAllNeighborsOfNode(RNGraph & rngraph, unsigned int node);
};




#endif /* TravelAlgorithmResult_hpp */
