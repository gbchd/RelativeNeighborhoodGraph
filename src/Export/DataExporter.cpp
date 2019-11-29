#include "DataExporter.hpp"

void DataExporter::ExportNodes(FileData & dataMatrix, std::string nomFichier)
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
        fichier << std::endl;


        for (unsigned int rowIndex = 0; rowIndex < numberOfRows; rowIndex++) {

            fichier << rowIndex;
            for (unsigned int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++) {
                if (dataMatrix.isColumnAClassAttribute(columnIndex)) {
                    fichier << dataMatrix.getSeparationCharacter() << dataMatrix.getString(rowIndex, columnIndex);
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

void DataExporter::ExportResults(TravelAlgorithmResult resultSet, std::string nomFichier)
{
    unsigned int numberOfNodes = resultSet.getNumberOfNodes();

    std::ofstream fichier;
    fichier.open(nomFichier, std::ios::out | std::ios::trunc);
    if (fichier.is_open()) {
        fichier << "\"Node\", \"Found again when inserted\", \"Found right node when inserted on\", \"Used node to travel\"" << std::endl;

        for (unsigned int rowIndex = 0; rowIndex < numberOfNodes; rowIndex++) {
            fichier << rowIndex << ", " << resultSet.getElementFromFoundAgainWhenInserted(rowIndex) << ", " << resultSet.getElementFromFoundRightNodeWhenInsertedOn(rowIndex) << ", " << resultSet.getElementFromUsedNodeToTravel(rowIndex)    << std::endl;
        }

        fichier.close();
    }
    else {
        printf("Error : Unable to open/create new CSV file\n");
    }
}
