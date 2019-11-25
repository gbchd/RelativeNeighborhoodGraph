//
//  RNGraph.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef RNGraph_hpp
#define RNGraph_hpp

#include <stdio.h>
#include "MatrixOfFloat.hpp"
#include "MatrixOfBoolean.hpp"
#include "DistancesBetweenNodes.hpp"

class RNGraph : public MatrixOfBoolean {
    //Atributes
private:
    

    //Constructors & Destructor
public:
    RNGraph(DistancesBetweenNodes & distancesBetweenNodes);
    
    //Methods
public:
  
    
private:
    bool isThereANodeCloserThan(DistancesBetweenNodes & distancesBetweenNodes, float distance, unsigned int node);
    
    bool isThereAnEdgeBetweenTwoNodes(DistancesBetweenNodes & distancesBetweenNodes, unsigned int node_A, unsigned int node_B);
    bool isDistanceTheMinInList(std::vector<float> list, unsigned int valueToTest);
    
};

#endif /* RNGraph_hpp */
