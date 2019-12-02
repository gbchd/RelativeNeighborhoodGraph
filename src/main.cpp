//
//  main.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include <iostream>
#include "MatrixOfFloat.hpp"
#include "FileData.hpp"
#include "GraphData.hpp"
#include "DistancesBetweenNodes.hpp"
#include "RNGraph.hpp"
#include "DataExporter.hpp"



/*
 arg -g "path" : graphFile, must be here if not return 1 and ask user to use the program with -g
 arg -c "path" : classesFile, if missing consider that there is no classes attribute in the graphFile.
 arg -d "path" : destinationFolder, if missing print the result of the travel algorithm.
 arg -v version_number : version of the travel algorithm, only version 1 and 2 available for now.
 @return 1 erreur, 0 generation réussie
 */
int main(int argc, const char * argv[]) {
    
    std::string graphFile = "";
    std::string classesFile = "";
    std::string exportDirectory = "";
    unsigned int versionOfTravelAlgorithm = 2;
    
    
    for (unsigned int arg = 1; arg < argc; arg = arg+2) {
        switch (argv[arg][1]) {
            case 'g':
                graphFile = argv[arg+1];
                break;
            case 'c':
                classesFile = argv[arg+1];
                break;
            case 'd':
                exportDirectory = argv[arg+1];
                break;
            case 'v':
                versionOfTravelAlgorithm = atoi(argv[arg+1]);
                break;
            default:
                std::cout << "Invalid arguments : " << argv[arg] << std::endl;
                break;
        }
    }
    
    if (graphFile == "") {
        std::cout << "Invalid arguments, missing the graph file." << std::endl <<  "Use -g \"path\"." << std::endl;
        return 1;
    }
    
    FileData fileData(graphFile, classesFile);
    GraphData graphData(fileData);
    DistancesBetweenNodes distances(graphData);
    RNGraph graph(distances);
    
    TravelAlgorithmResult stats(distances.getNumberOfColumns());
    if (versionOfTravelAlgorithm == 1) {
        stats.generateResultsWithNeighborAlgorithmV1(graph, distances);
    }
    else if (versionOfTravelAlgorithm == 2){
        stats.generateResultsWithNeighborAlgorithmV2(graph, distances);
    }
    else{
        std::cout << "Invalid version of the travel algorithm" << std::endl <<  "Use -v 1 or -v 2" << std::endl;
        return 1;
    }
    
    
    if(exportDirectory == ""){
        stats.print();
    }
    else{
        std::string nodesPath = exportDirectory+"nodes.txt";
        std::string edgesPath = exportDirectory+"edges.txt";
        std::string resultsPath = exportDirectory+"results.txt";
        
        DataExporter::ExportNodes(fileData, nodesPath);
        DataExporter::ExportEdges(graph, distances, edgesPath);
        DataExporter::ExportResults(stats, resultsPath);
    }
    
    
    
    return 0;
}
