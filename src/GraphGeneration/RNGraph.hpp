//
//  RNGraph.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
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
    bool isThereAnEdgeBetweenTwoNodes(DistancesBetweenNodes & distancesBetweenNodes, unsigned int node_A, unsigned int node_B);
    
    
};

#endif /* RNGraph_hpp */
