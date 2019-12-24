//
//  Exception.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 04/12/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(int code):comment(""){
    errorCode = code;
}

Exception::Exception(const std::string & com):comment(com){
    errorCode = 0;
}

Exception::Exception(int code, const std::string & com):comment(com){
    errorCode = code;
}

void Exception::print(){
    std::cout << "Error #" << errorCode << " : " << comment << std::endl;
}
