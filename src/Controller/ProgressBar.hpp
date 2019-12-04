//
//  ProgressBar.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard on 04/12/2019.
//  Copyright © 2019 GuillaumeBouchard. All rights reserved.
//

#ifndef ProgressBar_hpp
#define ProgressBar_hpp

#include <stdio.h>
#include <iostream>

class ProgressBar{
    //Atributes
private:
    unsigned int length;
    unsigned int cursor;
    
    unsigned int cursorSetToRatio;
    unsigned int lengthSetToRatio;
    
    unsigned int ratio;
    
    //Constructors & Destructor
public:
    ProgressBar(unsigned int ratioGiven);
    
    //Methods
public:
    void initialize(unsigned int l);
    void update();
    void print();
    
private:
    unsigned int setToRatio(unsigned int value);
    
};

#endif /* ProgressBar_hpp */
