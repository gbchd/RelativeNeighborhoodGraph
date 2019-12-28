//
//  FileData.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef FileData_hpp
#define FileData_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Exception.hpp"

/**
 @name FileData
 @brief Class that corresponds to a file of data used to generate the graph.
 This class needs to take two files as input and a separation character.
 The first file is the data file, it contains all the data which will be used to create the nodes of our graph.
 The second file is a small configuration file which contains a simple line to set if a column is a class attribute or not.
 */
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
    /**
    @brief Default constructor for the class FileData
    */
    FileData();
    
    /**
     @brief FileData's constructor that takes the paths of two files and the separation character in those files. It is recommended to use this constructor.
     @arg filenameOfGraph path to the file containing the data used to create the graph
     @arg filenameForIsColumnAClass path to the file containing the information whether the column is a class attribute or not
     @arg sep separation character in the two files
    */
    FileData(std::string filenameOfGraph, std::string filenameForIsColumnAClass, char sep);
    
    //Methods
public:
    char getSeparationCharacter(){return separationCharacter;}
    unsigned int getNumberOfRows(){return numberOfRows;}
    unsigned int getNumberOfColumns(){return numberOfColumns;}
    /**
    @brief Getter that return the number of columns that are non class.
    */
    unsigned int getNumberOfColumnsNonClass();
    
    //A column can be both a class attribute and used to generate the graph
    /**
    @brief Return true if the column given is a class attribute.
    */
    bool isColumnAClassAttribute(unsigned int column);
    /**
    @brief Return true if the column given is use to generate the graph.
    */
    bool isColumnUsedToGenerateTheGraph(unsigned int column);
    
    std::string getString(unsigned int row, unsigned int column){return matrixOfString[row][column];}
    
    /**
    @brief Print the vector of int and the matrix of string
    */
    void print();
    
    /**
    @brief Print the matrix of string which is equal to the first file's content.
    */
    void printMatrix();
    
    /**
    @brief Print the vector of int which indequates whether the column is a class attribute or not. It is also equal to the second file's content.
    */
    void printIsColumnAClassAttribute();
    
private:
    /**
     @brief Method that add a row to the matrix of string from a string given.
     @arg line string which contains the matrix's row.
    */
    void addRowOfMatrixFromLine(const std::string & line);
    
    /**
    @brief Cut a string using the separation character to turn it into a vector of strings.
    */
    std::string cutStringAfterSperationCharacter(std::string stringToCut);
    
    /**
    @brief Remove the string's part before the the separation character's first occurence.
    */
    std::string getFirstElementOfString(std::string stringToSearch);
    
    /**
    @brief Return the first substring before the the separation character's first occurence.
    */
    std::vector<std::string> cutStringOnSeparationCharacter(std::string stringToCut);
    
    /**
    @brief Return the number of the separation character's occurence.
    */
    unsigned int findNumberOfSeparationCharacter(std::string stringToSearch);
    
    /**
    @brief Setter for the vector of int which indicates whether a column is a class attribute or not from a string.
    */
    void setIsColumAClassWithString(std::string line);
    
    /**
    @brief Setter that fill the vector of int with zeros.
    */
    void setIsColumAClassToZero();
    
    /**
    @brief Check if the size of the vector of int is the same as the number of columns of the matrix of string.
    */
    void checkSize();
};


#endif /* FileData_hpp */
