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
#include "MatrixOfFloat.hpp"
#include "RNGraph.hpp"
#include "DistancesBetweenNodes.hpp"


class TravelAlgorithmResult : public MatrixOfFloat {
    //Atributes
private:
    
    unsigned int numbersOfSuccesses;
    
    //Constructors & Destructor
public:
    
    
    //Methods
public:
    void generateResultsWithNeighborAlgorithmV1(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes);
    void generateResultsWithNeighborAlgorithmV2(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes);
    
private:
    bool isTheSameSize(MatrixOfFloat & matrixA, MatrixOfBoolean & matrixB);
    bool isTheSameSize(MatrixOfBoolean & matrixA, MatrixOfFloat & matrixB);
    
};




#endif /* TravelAlgorithmResult_hpp */
