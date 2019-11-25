//
//  DataExporter.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 25/11/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef DataExporter_hpp
#define DataExporter_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "FileData.hpp"

class DataExporter {
    //Méthodes
public:
    static void ExportNodes(FileData & dataMatrix, std::string nomFichier);
    static void ExportEdges();
    static void ExportResults();

private:
    // Disallow creating an instance of this object
    DataExporter() {}
};


#endif /* DataExporter_hpp */
