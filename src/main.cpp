//
//  main.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 15/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include <iostream>
#include "MatrixOfFloat.hpp"
#include "FileData.hpp"
#include "GraphData.hpp"
#include "MatrixOfDistanceBetweenNodes.hpp"
#include "RNGraph.hpp"

int main(int argc, const char * argv[]) {
    MatrixOfFloat matrix1;
    MatrixOfFloat matrix2(2,2);
    
    matrix2.setElement(0, 0, 1);
    matrix2.setElement(0, 1, 2);
    matrix2.setElement(1, 0, 3);
    matrix2.setElement(1, 1, 4);
    
    MatrixOfFloat matrix3(matrix2);
    
    matrix1.print();
    matrix2.print();
    matrix3.print();
    
    std::string filename = "/Users/guillaume/Workspace/C++/RelativeNeighborhoodGraph/iris.data";
    std::string filenameTemp = "/Users/guillaume/Workspace/C++/RelativeNeighborhoodGraph/temp.data";
    
    FileData matrix4(filename, filenameTemp);
    
    matrix4.print();
    printf("%d %d \n", matrix4.getNumberOfRows(), matrix4.getNumberOfColumns());
    
    GraphData matrix5(matrix4);
    
    matrix5.print();
    
    MatrixOfDistanceBetweenNodes matrix6(matrix5);
    
    matrix6.print();
    
    RNGraph graph(matrix6);
    
    graph.print();
    
    
    
    return 0;
}