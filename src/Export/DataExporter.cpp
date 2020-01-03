//
//  DataExporter.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaineon 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "DataExporter.hpp"

/**
@brief Exports the list of nodes from the graph and all their stats generated from the travel algorithm.
*/
void DataExporter::ExportNodes(FileData & dataMatrix, TravelAlgorithmResult resultSet, std::string nomFichier)
{
    unsigned int numberOfRows = dataMatrix.getNumberOfRows();
    unsigned int numberOfColumns = dataMatrix.getNumberOfColumns();

    std::ofstream fichier;
    fichier.open(nomFichier, std::ios::out | std::ios::trunc);
    if (fichier.is_open()) {
        fichier << "\"Node\"";
        for (unsigned int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++) {
            if (dataMatrix.isColumnAClassAttribute(columnIndex)) {
                fichier << dataMatrix.getSeparationCharacter() << "\"ClassName\"";
            }
        }
        fichier << dataMatrix.getSeparationCharacter() << "\"Found again when inserted\""
            << dataMatrix.getSeparationCharacter() << "\"Found right node when inserted on\""
            << dataMatrix.getSeparationCharacter() << "\"Used node to travel\""
            << dataMatrix.getSeparationCharacter() << "\"Mean distance to vertex when failed to insert on\""
            << dataMatrix.getSeparationCharacter() << "\"Mean distance travelling\""
            << dataMatrix.getSeparationCharacter() << "\"Min distance travelling\""
            << dataMatrix.getSeparationCharacter() << "\"Max distance travelling\""
            << dataMatrix.getSeparationCharacter() << "\"Mean distance\""
        << std::endl;


        for (unsigned int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {
            fichier << rowIndex;
            for (unsigned int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++) {
                if (dataMatrix.isColumnAClassAttribute(columnIndex)) {
                    fichier << dataMatrix.getSeparationCharacter()<< dataMatrix.getString(rowIndex, columnIndex);
                }
            }

            fichier << dataMatrix.getSeparationCharacter()<< resultSet.getElementFromFoundAgainWhenInserted(rowIndex)
                << dataMatrix.getSeparationCharacter() << resultSet.getElementFromFoundRightNodeWhenInsertedOn(rowIndex)
                << dataMatrix.getSeparationCharacter() << resultSet.getElementFromUsedNodeToTravel(rowIndex)
                << dataMatrix.getSeparationCharacter() << resultSet.getElementFromMeanDistanceToVertex(rowIndex)
                << dataMatrix.getSeparationCharacter() << resultSet.getElementFromMeanTravelDistance(rowIndex)
                << dataMatrix.getSeparationCharacter() << resultSet.getElementFromMinTravelDistance(rowIndex)
                << dataMatrix.getSeparationCharacter() << resultSet.getElementFromMaxTravelDistance(rowIndex)
                << dataMatrix.getSeparationCharacter() << resultSet.getMeanDistancesBetweenNodes()
            << std::endl;
        }

        fichier.close();
    }
    else {
        printf("Error : Unable to open/create new CSV file\n");
    }
}

/**
@brief Exports the list of all edges from the graph and their distances.
*/
void DataExporter::ExportEdges(RNGraph & edgesMatrix, DistancesBetweenNodes & distMatrix, std::string nomFichier)
{
    unsigned int numberOfRows = edgesMatrix.getNumberOfRows();

    std::ofstream fichier;
    fichier.open(nomFichier, std::ios::out | std::ios::trunc);
    if (fichier.is_open()) {
        fichier << "\"Source\", \"Target\", \"Length\"" << std::endl;

        for (unsigned int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {
            for (unsigned int columnIndex = 0; columnIndex < numberOfRows; columnIndex++) {
                if (edgesMatrix.getElement(rowIndex, columnIndex) == 1) {
                    float a = distMatrix.getElement(rowIndex, columnIndex);
                    fichier << rowIndex << ", " << columnIndex << ", " << a << std::endl;
                }
            }
        }

        fichier.close();
    }
    else {
        printf("Error : Unable to open/create new CSV file\n");
    }
}

