//
//  MatrixOfBoolean.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef MatrixOfBoolean_hpp
#define MatrixOfBoolean_hpp

#include <stdio.h>
#include <vector>

/**
 @name MatrixOfBoolean
 @brief A matrix class containing boolean.
 */
class MatrixOfBoolean {
    //Atributes
private:
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
    
    bool** matrixArray;
    
    //Constructors & Destructor
public:
    /**
     @brief Default constructor, number of columns and rows = 0 and no array allocated.
     */
    MatrixOfBoolean();
    
    /**
     @brief Copy constructor, each value of the array is copied.
     */
    MatrixOfBoolean(const MatrixOfBoolean & matrix);
    
    /**
     @brief Constructor that takes the number of rows and columns as parameter, this allocates the array and set it to false.
     */
    MatrixOfBoolean(unsigned int rows, unsigned int columns);
    
    /**
     @brief Destructor which desallocate the array.
     */
    ~MatrixOfBoolean();
    
    //Methods
public:
    /**
     @brief Desallocate then copy the given matrix to this matrix.
     */
    MatrixOfBoolean& operator=(const MatrixOfBoolean & matrix);
    
    //Getters and setters
    unsigned int getNumberOfRows();
    unsigned int getNumberOfColumns();
    bool getElement(unsigned int row, unsigned int column);
    void setElement(unsigned int row, unsigned int column, bool elem);
    
    /**
     @brief Check if the matrix is square.
     */
    bool isSquare();
    
    /**
     @brief Check if the number of columns or lines is equal 0, if so we return true.
     */
    bool isSizeNotValid();
    
    /**
     @brief Print the matrix with 1 if true and 0 if false.
     */
    void print();
   
private:
    /**
     @brief Allocate the array in correspondance of the number of columns and rows.
     */
    void allocateMatrixArray();
    
    /**
     @brief Desallocate the matrix array.
     */
    void desallocateMatrixArray();
    
    /**
     @brief Copy an array to the matrix array.
     @warning Does not check the size of the array.
     */
    void copyArrayToMatrixArray(bool** array);
    
    /**
     @brief Set the whole matrix arrray to false.
     */
    void setMatrixArrayToFalse();
};



#endif /* MatrixOfBoolean_hpp */
