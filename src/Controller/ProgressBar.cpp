//
//  ProgressBar.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 04/12/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#include "ProgressBar.hpp"

ProgressBar::ProgressBar(unsigned int ratioGiven){
    ratio = ratioGiven;
    length = 0;
    cursor = 0;
    
    lengthSetToRatio = 0;
    cursorSetToRatio = 0;
}

void ProgressBar::initialize(unsigned int l){
    length = l;
    lengthSetToRatio = setToRatio(length);
    print();
}

void ProgressBar::update(){
    cursor++;
    if(cursorSetToRatio != setToRatio(cursor)){
        cursorSetToRatio++;
        print();
    }
    if (cursor == length) {
        std::cout << std::endl;
    }
}

void ProgressBar::print(){
    std::cout <<"[";
    for (unsigned int i = 0; i < cursorSetToRatio ; i++) {
        std::cout << "=";
    }
    for (unsigned int i = cursorSetToRatio; i < lengthSetToRatio; i++) {
        std::cout << " ";
    }
    std::cout << "] " << cursorSetToRatio*100/ratio << "%" << '\r' << std::flush;
    
}


unsigned int ProgressBar::setToRatio(unsigned int value){
    return (((float)value) / ((float)length)) * ratio;
}

