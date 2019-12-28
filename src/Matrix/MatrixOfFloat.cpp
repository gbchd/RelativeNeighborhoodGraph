//
//  MatrixOfFloat.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "MatrixOfFloat.hpp"


/*
 Constructors & Destructor
 */
/**
@brief Default constructor, number of columns and rows = 0 and no array allocated.
*/
MatrixOfFloat::MatrixOfFloat(){
    numberOfRows = 0;
    numberOfColumns = 0;
    matrixArray = NULL;
}

/**
@brief Copy constructor, each value of the array is copied.
*/
MatrixOfFloat::MatrixOfFloat(const MatrixOfFloat & matrix){
    numberOfRows = matrix.numberOfRows;
    numberOfColumns = matrix.numberOfColumns;
    allocateMatrixArray();
    copyArrayToMatrixArray(matrix.matrixArray);
}

/**
@brief Constructor that takes the number of rows and columns as parameter, this allocates the array and set it to false.
*/
MatrixOfFloat::MatrixOfFloat(unsigned int rows, unsigned int columns){
    numberOfRows = rows;
    numberOfColumns = columns;
    allocateMatrixArray();
    setMatrixArrayToZero();
}

/**
@brief Destructor which desallocate the array.
*/
MatrixOfFloat::~MatrixOfFloat(){
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
MatrixOfFloat& MatrixOfFloat::operator=(const MatrixOfFloat & matrix){
    if(!isSizeNotValid()){
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

float MatrixOfFloat::getElement(unsigned int row, unsigned int column){
    return matrixArray[row][column];
}

void MatrixOfFloat::setElement(unsigned int row, unsigned int column, float elem){
    matrixArray[row][column] = elem;
}

/**
@brief Check if the matrix is square.
*/
bool MatrixOfFloat::isSquare(){
    return (numberOfRows==numberOfColumns);
}

/**
@brief Check if the number of columns or lines is equal 0, if so we return true.
*/
bool MatrixOfFloat::isSizeNotValid(){
    return numberOfRows==0 || numberOfColumns==0;
}

/**
@brief Print the matrix.
*/
void MatrixOfFloat::print(){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            printf("%f ", getElement(row, column));
        }
        printf("\n");
    }
    printf("\n");
}

/**
@brief Print the matrix's dimensions.
*/
void MatrixOfFloat::printDimension(){
    printf("%u %u \n",numberOfRows, numberOfColumns);
}

/**
@brief Return a certain row of the matrix in a vector format.
*/
std::vector<float> MatrixOfFloat::getRow(unsigned int row){
    std::vector<float> rowToReturn;
    for(unsigned int column = 0; column < getNumberOfColumns(); column++){
        rowToReturn.push_back(getElement(row, column));
    }
    return rowToReturn;
}

/**
@brief Return a certain row after a given limit of the matrix in a vector format.
 This method is used in our implementation because these matrices are upper triangle, using this method we only get the part with correct data.
 */
std::vector<float> MatrixOfFloat::getRowAfterLimit(unsigned int row, unsigned int limit){
    std::vector<float> rowToReturn;
    for(unsigned int column = limit; column < getNumberOfColumns(); column++){
        rowToReturn.push_back(getElement(row, column));
    }
    return rowToReturn;
}

/**
@brief Return a certain column of the matrix in a vector format.
*/
std::vector<float> MatrixOfFloat::getColumn(unsigned int column){
    std::vector<float> columnToReturn;
    for(unsigned int row = 0; row < getNumberOfColumns(); row++){
        columnToReturn.push_back(getElement(row, column));
    }
    return columnToReturn;
}

/**
@brief Return a certain column before a given limit of the matrix in a vector format.
 This method is used in our implementation because these matrices are upper triangle, using this method we only get the part with correct data.
 */
std::vector<float> MatrixOfFloat::getColumnBeforeLimit(unsigned int column, unsigned int limit){
    std::vector<float> columnToReturn;
    for(unsigned int row = 0; row < limit; row++){
        columnToReturn.push_back(getElement(row, column));
    }
    return columnToReturn;
}

/**
@brief change the matrix's number of rows and columns.
 */
void MatrixOfFloat::resizeMatrix(unsigned int rows, unsigned int columns){
    desallocateMatrixArray();
    numberOfRows = rows;
    numberOfColumns = columns;
    allocateMatrixArray();
}



/*
Private Methods
*/
/**
@brief Allocate the array in correspondance of the number of columns and rows.
*/
void MatrixOfFloat::allocateMatrixArray(){
    if(numberOfRows != 0 && numberOfColumns != 0){
        matrixArray = new float*[numberOfRows];
        for(unsigned int column = 0; column < numberOfRows; column++){
            matrixArray[column] = new float[numberOfColumns];
        }
    }
}

/**
@brief Desallocate the matrix array.
*/
void MatrixOfFloat::desallocateMatrixArray(){
    if (numberOfRows > 0 && numberOfColumns > 0) {
        for(unsigned int row = 0; row < numberOfRows; row++){
            delete[] matrixArray[row];
        }
        
        delete[] matrixArray;
    }
    
    matrixArray = NULL;
}

/**
@brief Copy an array to the matrix array.
@warning Does not check the size of the array.
*/
void MatrixOfFloat::copyArrayToMatrixArray(float** arrayToCopy){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = arrayToCopy[row][column];
        }
    }
} 

/**
@brief Set the whole matrix arrray to false.
*/
void MatrixOfFloat::setMatrixArrayToZero(){
    for(unsigned int row = 0; row < numberOfRows; row++){
        for (unsigned int column = 0; column < numberOfColumns; column++) {
            matrixArray[row][column] = 0;
        }
    }
}
