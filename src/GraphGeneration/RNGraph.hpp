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



/**
 *\name RNGraph
 *\brief A upper triangle matrix of boolean that stocks the whether there is an edge betwen two nodes of the relative neighborhood graph.
 *These values are generated from the distances within a DistancesBetweenNodes object.
 */
class RNGraph : public MatrixOfBoolean {
    //Constructors & Destructor
public:
    /**
     *\brief RNGraph's constructor that takes a DistancesBetweenNodes object to determine whether there is an edge between two nodes or not.
     */
    explicit RNGraph(DistancesBetweenNodes & distancesBetweenNodes);
    
    //Methods
private:
    /**
     *\brief Determine whether there is an edge between two nodes.
     *There is an edge between two nodes (A and B) if there is no other node (C) closer to A AND B.
     *That means that if we take the distance between A and B and calls it r, then if the distance A-C < r AND the distance B-C < r then there is no edge between A and B.
     */
    bool isThereAnEdgeBetweenTwoNodes(DistancesBetweenNodes & distancesBetweenNodes, unsigned int node_A, unsigned int node_B);
};

#endif /* RNGraph_hpp */
