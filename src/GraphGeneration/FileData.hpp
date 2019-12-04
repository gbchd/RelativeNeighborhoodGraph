//
//  FileData.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef FileData_hpp
#define FileData_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Exception.hpp"

class FileData{
    
    //Attributes
private:
    char separationCharacter;
    
    std::vector<std::vector<std::string>> matrixOfString;
    
    //We use an int code that specifies if the column is a class attribute of the graph
    //0 Non-class attribute
    //1 Class attribute not used to build the graph
    //2 Class attribute used to build the graph
    std::vector<int> isColumnAClass;
    
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
    
    //Constructors & Destructors
public:
    FileData();
    FileData(std::string filenameOfGraph, std::string filenameForIsColumnAClass, char sep);
    
    //Methods
public:
    char getSeparationCharacter();
    unsigned int getNumberOfRows();
    unsigned int getNumberOfColumns();
    unsigned int getNumberOfColumnsNonClass();
    
    //A column can be both
    bool isColumnAClassAttribute(unsigned int column);
    bool isColumnUsedToGenerateTheGraph(unsigned int column);
    
    std::string getString(unsigned int row, unsigned int column);
    
    void print();
    void printMatrix();
    void printIsColumnAClassAttribute();
    
private:
    void setElement(unsigned int row, unsigned int column, std::string element);
    void addRowOfMatrixFromLine(std::string line);
    std::string cutStringAfterSperationCharacter(std::string stringToCut);
    std::string getFirstElementOfString(std::string stringToSearch);
    std::vector<std::string> cutStringOnSeparationCharacter(std::string stringToCut);
    unsigned int findNumberOfSeparationCharacter(std::string stringToSearch);
    
    void setIsColumAClassWithString(std::string line);
    void setIsColumAClassToZero();
    
    void checkSize();
};


#endif /* FileData_hpp */
