//
//  GraphData.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef GraphData_hpp
#define GraphData_hpp

#include <stdio.h>
#include "MatrixOfFloat.hpp"
#include "FileData.hpp"

/**
 @name GraphData
 @brief A matrix that stocks all the data that will be used to build the graph.
 The data comes from a FileData and are normalized.
 */
class GraphData : public MatrixOfFloat {
    //Constructors & Destructor
public:
    /**
    @brief GraphData's constructor that takes a FileData object as a parameter. It copies the data while ignoring the column that are not used to build the graph then normalize every column.
    */
    explicit GraphData(FileData & fileData);
   
    
    //Methods
private:
    /**
    @brief copy the data from a FileData object to the GraphData while ignoring the column which are not used to build the graph.
    */
    void copyDataFromFileData(FileData & fileData);
    
    /**
    @brief return the maximum value from a given column.
    */
    float getMaxOfColumn(unsigned int column);
    /**
    @brief return the minimin value from a given column.
    */
    float getMinOfColumn(unsigned int column);
    
    /**
    @brief normalize a value using a maximum and a minimum.
    */
    void normalizeColumn(unsigned int column);
    /**
    @brief normalize a whole column by using the maximum and the minimum found in the column.
    If the maximim equals the minimum then the whole column is set at 0.
    */
    float getNormalizedValueOfX(float x, float xmax, float xmin);
};


#endif /* GraphData_hpp */
