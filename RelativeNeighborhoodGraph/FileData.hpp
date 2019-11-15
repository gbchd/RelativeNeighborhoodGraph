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

class FileData{
    
    //Attributes
private:
    char separationCharacter;
    
    std::vector<std::vector<std::string>> matrixOfString;
    std::vector<int> isColumnAClass;
    
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
    
    //Constructors & Destructors
public:
    FileData();
    FileData(std::string filename);
    FileData(std::string filenameOfGraph, std::string filenameForIsColumnAClass);
    
    //Methods
public:
    char getSeparationCharacter();
    unsigned int getNumberOfRows();
    unsigned int getNumberOfColumns();
    
    bool isColumnAClassAttribute(unsigned int column);
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
};


#endif /* FileData_hpp */