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


/*
Public Methods
*/

void TravelAlgorithmResult::generateResultsWithNeighborAlgorithmV1(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes){
    if(!isTheSameSize(rngraph, distancesBetweenNodes)){
        throw "NotTheSameSizeError";
    }
    resizeMatrix(rngraph.getNumberOfRows(), rngraph.getNumberOfColumns());
    
    //Not finished
}

void TravelAlgorithmResult::generateResultsWithNeighborAlgorithmV2(RNGraph & rngraph, DistancesBetweenNodes & distancesBetweenNodes){
    if(!isTheSameSize(rngraph, distancesBetweenNodes)){
        throw "NotTheSameSizeError";
    }
    resizeMatrix(rngraph.getNumberOfRows(), rngraph.getNumberOfColumns());
    
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
