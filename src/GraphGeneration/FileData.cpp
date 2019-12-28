//
//  FileData.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "FileData.hpp"

/*
Constructors & Destructor
*/

/**
 @brief Default constructor for the class FileData
 */
FileData::FileData(){
    separationCharacter = ',';
    numberOfRows = 0;
    numberOfColumns = 0;
}

/**
 @brief FileData's constructor that takes the paths of two files and the separation character in those files. It is recommended to use this constructor.
 @arg filenameOfGraph path to the file containing the data used to create the graph
 @arg filenameForIsColumnAClass path to the file containing the information whether the column is a class attribute or not
 @arg sep separation character in the two files
*/
FileData::FileData(std::string filenameOfGraph, std::string filenameForIsColumnAClass, char sep){
    separationCharacter = sep;
    std::string line;
    std::ifstream myfile(filenameOfGraph);
    while (std::getline(myfile, line) && line != ""){
        addRowOfMatrixFromLine(line);
    }
    numberOfRows = (unsigned int) matrixOfString.size();
    numberOfColumns = (unsigned int) matrixOfString[0].size();
    
    if(filenameForIsColumnAClass == ""){
        setIsColumAClassToZero();
    }
    else{
        std::ifstream fileTemp(filenameForIsColumnAClass);
        std::getline(fileTemp, line);
        setIsColumAClassWithString(line);
        checkSize();
    }
}


/*
Public Methods
*/

/**
@brief Getter that return the number of columns that are non class.
*/
unsigned int FileData::getNumberOfColumnsNonClass(){
    unsigned int numberOfColumnsNonClass = 0;
    for(unsigned int column = 0; column < numberOfColumns; column++){
        if(isColumnUsedToGenerateTheGraph(column)){
            numberOfColumnsNonClass++;
        }
    }
    return numberOfColumnsNonClass;
}

/**
@brief Return true if the column given is a class attribute.
*/
bool FileData::isColumnAClassAttribute(unsigned int column){
    if (isColumnAClass[column] == 1 || isColumnAClass[column] == 2) {
        return true;
    }
    else{
        return false;
    }
}

/**
@brief Return true if the column given is use to generate the graph.
*/
bool FileData::isColumnUsedToGenerateTheGraph(unsigned int column){
    if (isColumnAClass[column] == 0 || isColumnAClass[column] == 2) {
        return true;
    }
    else{
        return false;
    }
}

/**
@brief Print the vector of int and the matrix of string
*/
void FileData::print(){
    printIsColumnAClassAttribute();
    printMatrix();
}

/**
@brief Print the matrix of string which is equal to the first file's content.
*/
void FileData::printMatrix(){
    for (unsigned int row = 0; row < numberOfRows; row ++) {
        for (unsigned int column = 0; column < numberOfColumns-1; column++) {
            std::cout << matrixOfString[row][column] << separationCharacter;
        }
        std::cout << matrixOfString[row][numberOfColumns-1] << std::endl;
    }
    std::cout << std::endl;
}

/**
@brief Print the vector of int which indequates whether the column is a class attribute or not. It is also equal to the second file's content.
*/
void FileData::printIsColumnAClassAttribute(){
    for (unsigned int column = 0; column < numberOfColumns-1; column++) {
        std::cout << isColumnAClass[column] << separationCharacter;
    }
    std::cout << isColumnAClass[numberOfColumns-1] << std::endl;
}

/*
Private Methods
*/

/**
 @brief Method that add a row to the matrix of string from a string given.
 @arg line string which contains the matrix's row.
*/
void FileData::addRowOfMatrixFromLine(const std::string & line){
    std::vector<std::string> lineVector = cutStringOnSeparationCharacter(line);
    matrixOfString.push_back(lineVector);
    numberOfRows++;
}

/**
@brief Cut a string using the separation character to turn it into a vector of strings.
*/
std::vector<std::string> FileData::cutStringOnSeparationCharacter(std::string stringToCut){
    std::vector<std::string> vectorToReturn;
    vectorToReturn.push_back(getFirstElementOfString(stringToCut));
    while (findNumberOfSeparationCharacter(stringToCut) > 0) {
        stringToCut = cutStringAfterSperationCharacter(stringToCut);
        vectorToReturn.push_back(getFirstElementOfString(stringToCut));
    }
    return vectorToReturn;
}

/**
@brief Remove the string's part before the the separation character's first occurence.
*/
std::string FileData::cutStringAfterSperationCharacter(std::string stringToCut){
    size_t pos = stringToCut.find(separationCharacter);
    if(pos != std::string::npos){
        stringToCut = stringToCut.substr(pos+1);
    }
    return stringToCut;
}

/**
@brief Return the first substring before the the separation character's first occurence.
*/
std::string FileData::getFirstElementOfString(std::string stringToSearch){
    size_t pos = stringToSearch.find(separationCharacter);
    if(pos != std::string::npos){
        return stringToSearch.substr(0,pos);
    }
    else{
        return stringToSearch;
    }
}

/**
@brief Return the number of the separation character's occurence.
*/
unsigned int FileData::findNumberOfSeparationCharacter(std::string stringToSearch){
    return (unsigned int) std::count(stringToSearch.begin(), stringToSearch.end(), separationCharacter);
}

/**
@brief Setter for the vector of int which indicates whether a column is a class attribute or not from a string.
*/
void FileData::setIsColumAClassWithString(std::string line){
    isColumnAClass.push_back(std::stoi(getFirstElementOfString(line)));
    while(findNumberOfSeparationCharacter(line) > 0){
        line = cutStringAfterSperationCharacter(line);
        isColumnAClass.push_back(std::stoi(getFirstElementOfString(line)));
    }
}

/**
@brief Setter that fill the vector of int with zeros.
*/
void FileData::setIsColumAClassToZero(){
    for(unsigned int column = 0; column < numberOfColumns; column++){
        isColumnAClass.push_back(0);
    }
}

/**
 @brief Check if the size of the vector of int is the same as the number of columns of the matrix of string.
*/
void FileData::checkSize(){
    if(isColumnAClass.size() != matrixOfString[0].size()){
        throw Exception(1, "FileData error - size incorrect, check the files.");
    }
}
