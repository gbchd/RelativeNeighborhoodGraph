//
//  Exception.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 04/12/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <iostream>
#include <stdio.h>
#include <string>

class Exception{
private:
    int errorCode;
    std::string comment;
    
public:
    explicit Exception(int code);
    explicit Exception(const std::string & com);
    Exception(int code, const std::string & com);
    
    void print();
};

#endif /* Exception_hpp */
