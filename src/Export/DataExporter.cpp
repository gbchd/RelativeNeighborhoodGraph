//
//  DataExporter.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include "DataExporter.hpp"

void DataExporter::ExportNodes(FileData & dataMatrix, std::string nomFichier)
{
    //RNGGraph + FileData pour les noms de classe
    std::ofstream fichier;
    fichier.open(nomFichier, std::ios::out | std::ios::trunc);
    if (fichier.is_open()) {

        fichier << "\"Node\"";
        for (unsigned int columnIndex = 0; columnIndex < dataMatrix.getNumberOfColumns(); columnIndex++) {
            if (dataMatrix.isColumnAClassAttribute(columnIndex)) {
                fichier << dataMatrix.getSeparationCharacter() << " \"ClassName\"";
            }
        }
        fichier << std::endl;

        unsigned int numberOfRows = dataMatrix.getNumberOfRows();
        unsigned int numberOfColumns = dataMatrix.getNumberOfColumns();

            for (unsigned int lineIndex = 0; lineIndex < numberOfRows; lineIndex++) {
                
                fichier << lineIndex;
                for (unsigned int columnIndex = 0; columnIndex < dataMatrix.getNumberOfColumns(); columnIndex++) {
                    if (dataMatrix.isColumnAClassAttribute(columnIndex)) {
                        fichier << dataMatrix.getSeparationCharacter() << dataMatrix.getString(lineIndex, columnIndex);
                    }
                }

                fichier << std::endl;

            }

        fichier.close();
    }
    else {
        printf("Error : Unable to open/create new CSV file\n");
    }
}

void DataExporter::ExportEdges()
{

}

void DataExporter::ExportResults()
{

}
