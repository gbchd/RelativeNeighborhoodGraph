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
#include "TimeClock.hpp"


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
        
        TimeClock clock;
        clock.startSection("Graph generation");
        
        FileData fileData(dataFile, classesFile, separationCharacter);
        clock.tick("Files reading");
        
        GraphData graphData(fileData);
        clock.tick("Data transformation");
        
        DistancesBetweenNodes distances(graphData);
        clock.tick("Matrix of distances generation");
        
        RNGraph graph(distances);
        clock.tick("Matrix of edges generation");
        
        clock.endSection("Graph generation");
        clock.startSection("Travel algorithm application version " + std::to_string(versionOfTravelAlgorithm));
        
        TravelAlgorithmResult stats(distances.getNumberOfColumns());
        
        if (versionOfTravelAlgorithm == 1 || versionOfTravelAlgorithm == 2) {
            stats.generateNeighbors(graph, versionOfTravelAlgorithm);
            clock.tick("Neighbors generation");
            
            stats.generateResultsWithNeighborAlgorithm(distances, versionOfTravelAlgorithm, k);
            clock.tick("Travel algorithm");
        }
        else{
            std::cout << "Invalid version of the travel algorithm" << std::endl <<  "Use -v 1 or -v 2" << std::endl;
            return 1;
        }
        
        clock.endSection("Travel algorithm");
        
        clock.startSection("Export results");
        
        
        //Export
        if(exportDirectory == ""){
            stats.print();
            clock.tick();
        }
        else{
            std::string nodesPath = exportDirectory+"nodes.csv";
            std::string edgesPath = exportDirectory+"edges.csv";
            
            DataExporter::ExportNodes(fileData, stats, nodesPath);
            clock.tick("Export of nodes.csv");
            
            DataExporter::ExportEdges(graph, distances, edgesPath);
            clock.tick("Export of edges.csv");
        }
        
        clock.endSection("Results exportation");
        clock.finalize();
        
    }
    catch(Exception& e){
        e.print();
    }
    
    return 0;
}
