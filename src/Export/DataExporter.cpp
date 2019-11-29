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
                fichier << dataMatrix.getSeparationCharacter() << " \"ClassName\"";
            }
        }
        fichier << std::endl;


        for (unsigned int lineIndex = 0; lineIndex < numberOfRows; lineIndex++) {

            fichier << lineIndex;
            for (unsigned int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++) {
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

void DataExporter::ExportEdges(RNGraph & edgesMatrix, DistancesBetweenNodes & distMatrix, std::string nomFichier)
{
    unsigned int numberOfRows = edgesMatrix.getNumberOfRows();

    std::ofstream fichier;
    fichier.open(nomFichier, std::ios::out | std::ios::trunc);
    if (fichier.is_open()) {
        fichier << "\"Source\", \"Target\", \"Length\"" << std::endl;

        for (unsigned int uiIndiceLigne = 0; uiIndiceLigne < numberOfRows; uiIndiceLigne++) {
            for (unsigned int uiIndiceColonne = 0; uiIndiceColonne < numberOfRows; uiIndiceColonne++) {
                if (edgesMatrix.getElement(uiIndiceLigne, uiIndiceColonne) == 1) {
                    float a = distMatrix.getElement(uiIndiceLigne, uiIndiceColonne);
                    fichier << uiIndiceLigne << "," << uiIndiceColonne << "," << a << std::endl;
                }
            }
        }

        fichier.close();
    }
    else {
        printf("Error : Unable to open/create new CSV file\n");
    }
}

void DataExporter::ExportResults(TravelAlgorithmResult & resultMatrix, std::string nomFichier)
{

}
