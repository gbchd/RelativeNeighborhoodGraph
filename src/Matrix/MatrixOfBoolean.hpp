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

class MatrixOfBoolean {
    //Atributes
private:
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
    
    bool** matrixArray;
    
    //Constructors & Destructor
public:
    MatrixOfBoolean();
    MatrixOfBoolean(MatrixOfBoolean & matrix);
    MatrixOfBoolean(unsigned int rows, unsigned int columns);
    ~MatrixOfBoolean();
    
    //Methods
public:
    MatrixOfBoolean operator=(MatrixOfBoolean & matrix);
    
    unsigned int getNumberOfRows();
    unsigned int getNumberOfColumns();
    bool isSquare();
    bool isSizeNotValid();
    bool getElement(unsigned int row, unsigned int column);
    void setElement(unsigned int row, unsigned int column, bool elem);
    void print();
   
private:
    void allocateMatrixArray();
    void desallocateMatrixArray();
    void copyArrayToMatrixArray(bool** array);
    void setMatrixArrayToFalse();
};



#endif /* MatrixOfBoolean_hpp */
