//
//  GraphData.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "GraphData.hpp"

/*
Constructors & Destructor
*/

/**
 @brief GraphData's constructor that takes a FileData object as a parameter. It copies the data while ignoring the column that are not used to build the graph then normalize every column.
 */
GraphData::GraphData(FileData & fileData):MatrixOfFloat(fileData.getNumberOfRows(),fileData.getNumberOfColumnsNonClass()){
    //We have a matrix of the correct size, we just need to get the data and normalize them

    //We start by copying the correct columns from fileData
    copyDataFromFileData(fileData);
    
    //Then we normalize them
    #pragma omp parallel for
    for(int column = 0; column < getNumberOfColumns(); column++){
        normalizeColumn(column);
    }
}


/*
Public methods
*/

/*
Private methods
*/

/**
 @brief copy the data from a FileData object to the GraphData while ignoring the column which are not used to build the graph.
 */
void GraphData::copyDataFromFileData(FileData &fileData){
    unsigned int columnFileData = 0;
    for (unsigned int columnGraphData = 0; columnGraphData < getNumberOfColumns(); columnGraphData++) {
        while(!fileData.isColumnUsedToGenerateTheGraph(columnFileData)){columnFileData++;} //We copy only the column used to create the graph
        for (unsigned int row = 0; row < getNumberOfRows(); row++) {
            setElement(row, columnGraphData, std::stof(fileData.getString(row, columnFileData)));
        }
        columnFileData++;
    }
}

/**
 @brief return the maximum value from a given column.
 */
float GraphData::getMaxOfColumn(unsigned int column){
    float maxOfColumn = getElement(0, column);
    for(unsigned int row = 1; row < getNumberOfRows(); row++){
        if(maxOfColumn<getElement(row, column)){
            maxOfColumn = getElement(row, column);
        }
    }
    return maxOfColumn;
}

/**
 @brief return the minimin value from a given column.
 */
float GraphData::getMinOfColumn(unsigned int column){
    float minOfColumn = getElement(0, column);
    for(unsigned int row = 1; row < getNumberOfRows(); row++){
        if(minOfColumn>getElement(row, column)){
            minOfColumn = getElement(row, column);
        }
    }
    return minOfColumn;
}

/**
 @brief normalize a value using a maximum and a minimum.
 */
float GraphData::getNormalizedValueOfX(float x, float xmax, float xmin){
    return (x-xmin)/(xmax-xmin);
}

/**
 @brief normalize a whole column by using the maximum and the minimum found in the column.
 If the maximim equals the minimum then the whole column is set at 0.
 */
void GraphData::normalizeColumn(unsigned int column){
    float maxOfColumn = getMaxOfColumn(column);
    float minOfColumn = getMinOfColumn(column);
    if (maxOfColumn != minOfColumn) {
        for(unsigned int row = 0; row < getNumberOfRows(); row++){
            float x = getElement(row, column);
            setElement(row, column, getNormalizedValueOfX(x, maxOfColumn, minOfColumn));
        }
    }
    else{
        for(unsigned int row = 0; row < getNumberOfRows(); row++){
            setElement(row, column, 0);
        }
    }
}
