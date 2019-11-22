//
//  MatrixOfBoolean.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include "MatrixOfBoolean.hpp"


/*
 Constructors & Destructor
 */
MatrixOfBoolean::MatrixOfBoolean(){
    numberOfRows = 0;
    numberOfColumns = 0;
    matrixArray = NULL;
}

MatrixOfBoolean::MatrixOfBoolean(MatrixOfBoolean & matrix){
    numberOfRows = matrix.numberOfRows;
    numberOfColumns = matrix.numberOfColumns;
    allocateMatrixArray();
    copyArrayToMatrixArray(matrix.matrixArray);
}

MatrixOfBoolean::MatrixOfBoolean(unsigned int rows, unsigned int columns){
    numberOfRows = rows;
    numberOfColumns = columns;
    allocateMatrixArray();
    setMatrixArrayToFalse();
}

MatrixOfBoolean::~MatrixOfBoolean(){
    desallocateMatrixArray();
    numberOfRows = 0;
    numberOfColumns = 0;
}

/*
 Public Methods
 */
MatrixOfBoolean MatrixOfBoolean::operator=(MatrixOfBoolean & matrix){
    if(!isEmpty()){
        desallocateMatrixArray();
    }
    numberOfRows = matrix.numberOfRows;
    numberOfColumns = matrix.numberOfColumns;
    allocateMatrixArray();
    copyArrayToMatrixArray(matrix.matrixArray);
    
    return *this;
}

unsigned int MatrixOfBoolean::getNumberOfRows(){
    return numberOfRows;
}

unsigned int MatrixOfBoolean::getNumberOfColumns(){
    return numberOfColumns;
}

bool MatrixOfBoolean::isSquare(){
    return (numberOfRows==numberOfColumns);
}

bool MatrixOfBoolean::isEmpty(){
    return numberOfRows==0 || numberOfColumns==0;
}

bool MatrixOfBoolean::getElement(unsigned int row, unsigned int column){
    return matrixArray[row][column];
}

void MatrixOfBoolean::setElement(unsigned int row, unsigned int column, bool elem){
    matrixArray[row][column] = elem;
}

void MatrixOfBoolean::print(){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            if(getElement(row, column)){
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}



/*
Private Methods
*/
void MatrixOfBoolean::allocateMatrixArray(){
    if(numberOfRows != 0){
        matrixArray = new bool*[numberOfRows];
        for(unsigned int column = 0; column < numberOfRows; column++){
            matrixArray[column] = new bool[numberOfColumns];
        }
    }
}

void MatrixOfBoolean::desallocateMatrixArray(){
    for(unsigned int column = 0; column < numberOfRows; column++){
        delete[] matrixArray[column];
    }
    delete[] matrixArray;
    
    matrixArray = NULL;
}

void MatrixOfBoolean::copyArrayToMatrixArray(bool** arrayToCopy){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = arrayToCopy[row][column];
        }
    }
}

void MatrixOfBoolean::setMatrixArrayToFalse(){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = false;
        }
    }
}
 
