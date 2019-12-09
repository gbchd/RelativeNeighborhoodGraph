//
//  Exception.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 04/12/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(int code){
    errorCode = code;
    comment = "";
}

Exception::Exception(std::string com){
    errorCode = 0;
    comment = com;
}

Exception::Exception(int code, std::string com){
    errorCode = code;
    comment = com;
}

void Exception::print(){
    std::cout << "Error #" << errorCode << " : " << comment << std::endl;
}
