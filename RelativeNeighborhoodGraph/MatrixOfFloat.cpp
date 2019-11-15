//
//  MatrixOfFloat.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include "MatrixOfFloat.hpp"


/*
 Constructors & Destructor
 */
MatrixOfFloat::MatrixOfFloat(){
    numberOfRows = 0;
    numberOfColumns = 0;
    matrixArray = NULL;
}

MatrixOfFloat::MatrixOfFloat(MatrixOfFloat & matrix){
    numberOfRows = matrix.numberOfRows;
    numberOfColumns = matrix.numberOfColumns;
    allocateMatrixArray();
    copyArrayToMatrixArray(matrix.matrixArray);
}

MatrixOfFloat::MatrixOfFloat(unsigned int rows, unsigned int columns){
    numberOfRows = rows;
    numberOfColumns = columns;
    allocateMatrixArray();
    setMatrixArrayToZero();
}

MatrixOfFloat::~MatrixOfFloat(){
    desallocateMatrixArray();
    numberOfRows = 0;
    numberOfColumns = 0;
}

/*
 Public Methods
 */
MatrixOfFloat MatrixOfFloat::operator=(MatrixOfFloat & matrix){
    if(!isEmpty()){
        desallocateMatrixArray();
    }
    numberOfRows = matrix.numberOfRows;
    numberOfColumns = matrix.numberOfColumns;
    allocateMatrixArray();
    copyArrayToMatrixArray(matrix.matrixArray);
    
    return *this;
}

unsigned int MatrixOfFloat::getNumberOfRows(){
    return numberOfRows;
}

unsigned int MatrixOfFloat::getNumberOfColumns(){
    return numberOfColumns;
}

bool MatrixOfFloat::isSquare(){
    return (numberOfRows==numberOfColumns);
}

bool MatrixOfFloat::isEmpty(){
    return numberOfRows==0 || numberOfColumns==0;
}

float MatrixOfFloat::getElement(unsigned int row, unsigned int column){
    return matrixArray[row][column];
}

void MatrixOfFloat::setElement(unsigned int row, unsigned int column, float elem){
    matrixArray[row][column] = elem;
}

void MatrixOfFloat::printMatrix(){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            printf("%f ", getElement(row, column));
        }
        printf("\n");
    }
    printf("\n");
}

/*
Protected Methods
*/

/*
Private Methods
*/
void MatrixOfFloat::allocateMatrixArray(){
    if(numberOfRows != 0){
        matrixArray = new float*[numberOfRows];
        for(unsigned int column = 0; column < numberOfRows; column++){
            matrixArray[column] = new float[numberOfColumns];
        }
    }
}

void MatrixOfFloat::desallocateMatrixArray(){
    for(unsigned int column = 0; column < numberOfRows; column++){
        delete[] matrixArray[column];
    }
    delete[] matrixArray;
    
    matrixArray = NULL;
}

void MatrixOfFloat::copyArrayToMatrixArray(float** arrayToCopy){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = arrayToCopy[row][column];
        }
    }
}

void MatrixOfFloat::setMatrixArrayToZero(){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = 0;
        }
    }
}
