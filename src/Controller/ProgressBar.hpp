//
//  ProgressBar.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 04/12/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
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
    
    unsigned int cursorBar;
    unsigned int cursorPercent;
    
    unsigned int lengthBar;
    
    //Constructors & Destructor
public:
    ProgressBar();
    
    //Methods
public:
    void initialize(unsigned int l);
    void update();
    void print();
    
private:
    unsigned int setToPercent(unsigned int value);
};

#endif /* ProgressBar_hpp */
