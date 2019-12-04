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

