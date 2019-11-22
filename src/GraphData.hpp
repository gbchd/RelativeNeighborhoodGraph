//
//  GraphData.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 22/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef GraphData_hpp
#define GraphData_hpp

#include <stdio.h>
#include "MatrixOfFloat.hpp"
#include "FileData.hpp"


class GraphData : public MatrixOfFloat {
    //Atributes
private:

    //Constructors & Destructor
public:
    GraphData(FileData & fileData);
    
    //Methods
public:
    
    
private:
    void copyDataFromFileData(FileData & fileData);
    
    float getMaxOfColumn(unsigned int column);
    float getMinOfColumn(unsigned int column);
    
    void normalizeColumn(unsigned int column);
    float getNormalizedValueOfX(float x, float xmax, float xmin);

    
};


#endif /* GraphData_hpp */
