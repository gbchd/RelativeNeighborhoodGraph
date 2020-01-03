//
//  DataExporter.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaineon 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef DataExporter_hpp
#define DataExporter_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "FileData.hpp"
#include "TravelAlgorithmResult.hpp"
#include "RNGraph.hpp"

/**
 @name DataExporter
 @brief A class used to export the data to two files nodes and edges. These files are used to import the graph in Tulip.
 */
class DataExporter {
    //Méthodes
public:
    /**
     @brief Exports the list of nodes from the graph and all their stats generated from the travel algorithm.
     */
    static void ExportNodes(FileData & dataMatrix, TravelAlgorithmResult resultMatrix, std::string nomFichier);
    /**
    @brief Exports the list of all edges from the graph and their distances.
    */
    static void ExportEdges(RNGraph & edgesMatrix, DistancesBetweenNodes & distMatrix, std::string nomFichier);

private:
    // Disallow creating an instance of this object
    DataExporter() {}
};

#endif /* DataExporter_hpp */

