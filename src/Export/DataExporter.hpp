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

class DataExporter {
    //Méthodes
public:
    static void ExportNodes(FileData & dataMatrix, TravelAlgorithmResult resultMatrix, std::string nomFichier);
    static void ExportEdges(RNGraph & edgesMatrix, DistancesBetweenNodes & distMatrix, std::string nomFichier);

private:
    // Disallow creating an instance of this object
    DataExporter() {}
};

#endif /* DataExporter_hpp */

