//
//  main.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "MatrixOfFloat.hpp"
#include "FileData.hpp"
#include "GraphData.hpp"
#include "DistancesBetweenNodes.hpp"
#include "RNGraph.hpp"
#include "DataExporter.hpp"
#include "Exception.hpp"



/*
 arg -d "path" : dataFile, must be here if not return 1 and ask user to use the program with -g
 arg -c "path" : classesFile, if missing consider that there is no classes attribute in the graphFile.
 arg -e "path" : exportFolder, if missing print the result of the travel algorithm.
 arg -s separationCharacter : specify what the separation character of the file is.
 arg -v version_number : version of the travel algorithm, only version 1 and 2 available for now.
 arg -k numberOfNodes : instead of inserting each node on every nodes of the graph, we randomly select k nodes to insert on.
 @return 1 erreur, 0 generation réussie
 */
int main(int argc, const char * argv[]) {
    
    //Initialization
    std::string dataFile = "";
    std::string classesFile = "";
    std::string exportDirectory = "";
    char separationCharacter = ',';
    unsigned int versionOfTravelAlgorithm = 2;
    int k = -1;
    
    //Arguments verifications
    for (unsigned int arg = 1; arg < argc; arg++) {
        switch (argv[arg][1]) {
            case 'd':
                dataFile = argv[arg+1];
                arg++;
                break;
            case 'c':
                classesFile = argv[arg+1];
                arg++;
                break;
            case 'e':
                exportDirectory = argv[arg+1];
                arg++;
                break;
            case 's':
                separationCharacter = argv[arg+1][0];
                arg++;
                break;
            case 'v':
                versionOfTravelAlgorithm = atoi(argv[arg+1]);
                arg++;
                break;
            case 'k':
                k = atoi(argv[arg+1]);
                arg++;
                break;
            default:
                std::cout << "Invalid arguments : " << argv[arg] << std::endl;
                break;
        }
    }
    
    //Check if we did input a dataFile if not terminate the program.
    if (dataFile == "") {
        std::cout << "Invalid arguments, missing the graph file." << std::endl <<  "Use -g \"path\"." << std::endl;
        return 1;
    }
    
    try{
        //Set up all checkpoints for our clock
        std::time_t timeStart = std::time(nullptr);
        std::time_t timeCheckGraphGeneration;
        std::time_t timeCheckTravelAlgorithm;
        std::time_t oldTime;
        std::time_t newTime;
        oldTime = timeStart;
        
        
        std::cout << "===" << "Starting : Graph generation" << "===" << std::endl;
        
        FileData fileData(dataFile, classesFile, separationCharacter);
        newTime = std::time(nullptr);
        std::cout << "-Files reading done in " << newTime-oldTime << "s" << std::endl;
        oldTime = newTime;
        
        GraphData graphData(fileData);
        newTime = std::time(nullptr);
        std::cout << "-Data transformation done in " << newTime-oldTime << "s" << std::endl;
        oldTime = newTime;
        
        DistancesBetweenNodes distances(graphData);
        newTime = std::time(nullptr);
        std::cout << "-Matrix of distances generation done in " << newTime-oldTime << "s" << std::endl;
        oldTime = newTime;
        
        RNGraph graph(distances);
        newTime = std::time(nullptr);
        std::cout << "-Matrix of edges generation done in " << newTime-oldTime << "s" << std::endl;
        timeCheckGraphGeneration = newTime;
        
        std::cout << "===" << "Graph generation has been done in " << timeCheckGraphGeneration-timeStart << "s" << "===" << std::endl << std::endl;
        
   
        
        std::cout << "===" << "Starting : Travel algorithm application version " << versionOfTravelAlgorithm << "===" << std::endl;
        
        TravelAlgorithmResult stats(distances.getNumberOfColumns());
        
        
        if (versionOfTravelAlgorithm == 1 || versionOfTravelAlgorithm == 2) {
            stats.generateNeighbors(graph, versionOfTravelAlgorithm);
            newTime = std::time(nullptr);
            std::cout << "-Neighbors generation done in " << newTime-timeCheckGraphGeneration << "s" << std::endl;
            oldTime = newTime;
            
            stats.generateResultsWithNeighborAlgorithm(distances, versionOfTravelAlgorithm, k);
            newTime = std::time(nullptr);
            std::cout << "-Travel algorithm done in " << newTime-oldTime << "s" << std::endl;
        }
        else{
            std::cout << "Invalid version of the travel algorithm" << std::endl <<  "Use -v 1 or -v 2" << std::endl;
            return 1;
        }
        
        timeCheckTravelAlgorithm = newTime;
        
        std::cout << "===" << "Travel algorithm has been done in " << timeCheckTravelAlgorithm-timeCheckGraphGeneration << "s" << "===" << std::endl << std::endl;
        
        std::cout << "===" << "Starting : Export results" << "===" << std::endl;
        
        
        
        //Export
        if(exportDirectory == ""){
            stats.print();
            newTime = std::time(nullptr);
        }
        else{
            std::string nodesPath = exportDirectory+"nodes.csv";
            std::string edgesPath = exportDirectory+"edges.csv";
            
            DataExporter::ExportNodes(fileData, stats, nodesPath);
            newTime = std::time(nullptr);
            std::cout << "-Export of nodes.csv done in " << newTime-timeCheckTravelAlgorithm << "s" << std::endl;
            oldTime = newTime;
            
            DataExporter::ExportEdges(graph, distances, edgesPath);
            newTime = std::time(nullptr);
            std::cout << "-Export of edges.csv done in " << newTime-oldTime << "s" << std::endl;
            
            
        }
        
        std::cout << "===" << "Results exportation has been done in " << newTime-timeCheckTravelAlgorithm << "s" << "===" << std::endl << std::endl;
        
        std::cout << "Total program has been done in " << newTime-timeStart << "s" << std::endl << std::endl;
        
    }
    catch(Exception& e){
        e.print();
    }
    
    return 0;
}
