//
//  main.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include <iostream>
#include <ctime>
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
 arg -s separationCharacter : specify what the separation character of the file is.
 arg -v version_number : version of the travel algorithm, only version 1 and 2 available for now.
 @return 1 erreur, 0 generation réussie
 */
int main(int argc, const char * argv[]) {
    
    std::string graphFile = "";
    std::string classesFile = "";
    std::string exportDirectory = "";
    char separationCharacter = ',';
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
            case 's':
                separationCharacter = argv[arg+1][0];
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
    
    try{
        std::time_t timeStart = std::time(nullptr);
        std::time_t timeCheckGraphGeneration;
        std::time_t timeCheckTravelAlgorithm;
        std::time_t oldTime;
        std::time_t newTime;
        oldTime = timeStart;
        
        std::cout << "===" << "Starting : Graph generation" << "===" << std::endl;
        
        FileData fileData(graphFile, classesFile, separationCharacter);
        newTime = std::time(nullptr);
        std::cout << "-Reading of the files done in " << newTime-oldTime << "s" << std::endl;
        oldTime = newTime;
        
        GraphData graphData(fileData);
        newTime = std::time(nullptr);
        std::cout << "-Transformation of the data done in " << newTime-oldTime << "s" << std::endl;
        oldTime = newTime;
        
        DistancesBetweenNodes distances(graphData);
        newTime = std::time(nullptr);
        std::cout << "-Generation of the matrix of distances done in " << newTime-oldTime << "s" << std::endl;
        oldTime = newTime;
        
        RNGraph graph(distances);
        newTime = std::time(nullptr);
        std::cout << "-Generation of the matrix of edges done in " << newTime-oldTime << "s" << std::endl;
        timeCheckGraphGeneration = newTime;
        
        std::cout << "===" << "Graph generation has been done in " << timeCheckGraphGeneration-timeStart << "s" << "===" << std::endl << std::endl;
        
        
        std::cout << "===" << "Starting : Application of the travel algorithm version " << versionOfTravelAlgorithm << "===" << std::endl;
        
        TravelAlgorithmResult stats(distances.getNumberOfColumns());
        if (versionOfTravelAlgorithm == 1) {
            stats.generateResultsWithNeighborAlgorithmV1(graph, distances);
            newTime = std::time(nullptr);
        }
        else if (versionOfTravelAlgorithm == 2){
            stats.generateResultsWithNeighborAlgorithmV2(graph, distances);
            newTime = std::time(nullptr);
        }
        else{
            std::cout << "Invalid version of the travel algorithm" << std::endl <<  "Use -v 1 or -v 2" << std::endl;
            return 1;
        }
        
        timeCheckTravelAlgorithm = newTime;
        
        std::cout << "===" << "Travel algorithm has been done in " << timeCheckTravelAlgorithm-timeCheckGraphGeneration << "s" << "===" << std::endl << std::endl;
        
        std::cout << "===" << "Starting : Export results" << "===" << std::endl;
        
        if(exportDirectory == ""){
            stats.print();
            newTime = std::time(nullptr);
        }
        else{
            std::string nodesPath = exportDirectory+"nodes.csv";
            std::string edgesPath = exportDirectory+"edges.csv";
            
            DataExporter::ExportNodes(fileData, stats, nodesPath);
            newTime = std::time(nullptr);
            std::cout << "-Export of nodes.csv done in " << newTime-oldTime << "s" << std::endl;
            oldTime = newTime;
            
            DataExporter::ExportEdges(graph, distances, edgesPath);
            newTime = std::time(nullptr);
            std::cout << "-Export of edges.csv done in " << newTime-oldTime << "s" << std::endl;
        }
        
        
        std::cout << "===" << "Exportation of the results has been done in " << newTime-timeCheckTravelAlgorithm << "s total" << "===" << std::endl << std::endl;
        
        std::cout << "Total program has been done in " << newTime-timeCheckTravelAlgorithm << "s" << std::endl << std::endl;
        
        
    }
    catch(Exception e){
        e.print();
    }
    
    
    
    
    return 0;
}
