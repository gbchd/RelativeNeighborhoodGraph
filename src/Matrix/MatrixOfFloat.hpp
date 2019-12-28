//
//  MatrixOfFloat.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef MatrixOfFloat_hpp
#define MatrixOfFloat_hpp

#include <stdio.h>
#include <vector>
#include "MatrixOfBoolean.hpp"

/**
@name MatrixOfFloat
@brief A matrix class containing float.
*/
class MatrixOfFloat {
    //Atributes
private:
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
    
    float** matrixArray;
    
    //Constructors & Destructor
public:
    /**
    @brief Default constructor, number of columns and rows = 0 and no array allocated.
    */
    MatrixOfFloat();
    
    /**
    @brief Copy constructor, each value of the array is copied.
    */
    MatrixOfFloat(const MatrixOfFloat & matrix);
    
    /**
    @brief Constructor that takes the number of rows and columns as parameter, this allocates the array and set it to false.
    */
    MatrixOfFloat(unsigned int rows, unsigned int columns);
    
    /**
    @brief Destructor which desallocate the array.
    */
    ~MatrixOfFloat();
    
    //Methods
public:
    /**
    @brief Desallocate then copy the given matrix to this matrix.
    */
    MatrixOfFloat& operator=(const MatrixOfFloat & matrix);
    
    //Getters and setters
    unsigned int getNumberOfRows();
    unsigned int getNumberOfColumns();
    float getElement(unsigned int row, unsigned int column);
    void setElement(unsigned int row, unsigned int column, float elem);
    
    /**
    @brief Check if the matrix is square.
    */
    bool isSquare();
    
    /**
    @brief Check if the number of columns or lines is equal 0, if so we return true.
    */
    bool isSizeNotValid();
    
    /**
    @brief Print the matrix.
    */
    void print();
    
    /**
    @brief Print the matrix's dimensions.
    */
    void printDimension();
    
    /**
    @brief Return a certain row of the matrix in a vector format.
    */
    std::vector<float> getRow(unsigned int row);
    /**
    @brief Return a certain row after a given limit of the matrix in a vector format.
     This method is used in our implementation because these matrices are upper triangle, using this method we only get the part with correct data.
     */
    std::vector<float> getRowAfterLimit(unsigned int row, unsigned int limit);
    /**
    @brief Return a certain column of the matrix in a vector format.
    */
    std::vector<float> getColumn(unsigned int column);
    /**
    @brief Return a certain column before a given limit of the matrix in a vector format.
     This method is used in our implementation because these matrices are upper triangle, using this method we only get the part with correct data.
     */
    std::vector<float> getColumnBeforeLimit(unsigned int column, unsigned int limit);
    
    /**
    @brief change the matrix's number of rows and columns.
     */
    void resizeMatrix(unsigned int row, unsigned int column);
    
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
    void copyArrayToMatrixArray(float** array);
    
    /**
    @brief Set the whole matrix arrray to false.
    */
    void setMatrixArrayToZero();
};

#endif /* MatrixOfFloat_hpp */
