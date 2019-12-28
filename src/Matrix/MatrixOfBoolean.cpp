//
//  MatrixOfBoolean.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "MatrixOfBoolean.hpp"


/*
 Constructors & Destructor
 */

/**
@brief Default constructor, number of columns and rows = 0 and no array allocated.
*/
MatrixOfBoolean::MatrixOfBoolean(){
    numberOfRows = 0;
    numberOfColumns = 0;
    matrixArray = NULL;
}

/**
@brief Copy constructor, each value of the array is copied.
*/
MatrixOfBoolean::MatrixOfBoolean(const MatrixOfBoolean & matrix){
    numberOfRows = matrix.numberOfRows;
    numberOfColumns = matrix.numberOfColumns;
    allocateMatrixArray();
    copyArrayToMatrixArray(matrix.matrixArray);
}

/**
@brief Constructor that takes the number of rows and columns as parameter, this allocates the array and set it to false.
*/
MatrixOfBoolean::MatrixOfBoolean(unsigned int rows, unsigned int columns){
    numberOfRows = rows;
    numberOfColumns = columns;
    allocateMatrixArray();
    setMatrixArrayToFalse();
}

/**
@brief Destructor which desallocate the array.
*/
MatrixOfBoolean::~MatrixOfBoolean(){
    desallocateMatrixArray();
    numberOfRows = 0;
    numberOfColumns = 0;
}

/*
 Public Methods
 */

/**
@brief Desallocate then copy the given matrix to this matrix.
*/
MatrixOfBoolean& MatrixOfBoolean::operator=(const MatrixOfBoolean & matrix){
    if(!isSizeNotValid()){
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

bool MatrixOfBoolean::getElement(unsigned int row, unsigned int column){
    return matrixArray[row][column];
}

void MatrixOfBoolean::setElement(unsigned int row, unsigned int column, bool elem){
    matrixArray[row][column] = elem;
}


/**
@brief Check if the matrix is square.
*/
bool MatrixOfBoolean::isSquare(){
    return (numberOfRows==numberOfColumns);
}

/**
@brief Check if the number of columns or lines is equal 0, if so we return true.
*/
bool MatrixOfBoolean::isSizeNotValid(){
    return numberOfRows==0 || numberOfColumns==0;
}

/**
@brief Print the matrix with 1 if true and 0 if false.
*/
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

/**
@brief Allocate the array in correspondance of the number of columns and rows.
*/
void MatrixOfBoolean::allocateMatrixArray(){
    if(numberOfRows > 0 && numberOfColumns > 0){
        matrixArray = new bool*[numberOfRows];
        for(unsigned int column = 0; column < numberOfRows; column++){
            matrixArray[column] = new bool[numberOfColumns];
        }
    }
}

/**
@brief Desallocate the matrix array.
*/
void MatrixOfBoolean::desallocateMatrixArray(){
    if (numberOfRows > 0 && numberOfColumns > 0) {
        for(unsigned int column = 0; column < numberOfRows; column++){
            delete[] matrixArray[column];
        }
        delete[] matrixArray;
        
        matrixArray = NULL;
    }
}

/**
@brief Copy an array to the matrix array.
@warning Does not check the size of the array.
*/
void MatrixOfBoolean::copyArrayToMatrixArray(bool** arrayToCopy){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = arrayToCopy[row][column];
        }
    }
}

/**
@brief Set the whole matrix arrray to false.
*/
void MatrixOfBoolean::setMatrixArrayToFalse(){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = false;
        }
    }
}
 
