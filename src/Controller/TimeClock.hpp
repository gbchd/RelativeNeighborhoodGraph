//
//  TimeClock.hpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 24/12/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#ifndef TimeClock_hpp
#define TimeClock_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>

using namespace std::chrono;

class TimeClock{
    //Atributes
private:
    high_resolution_clock::time_point startTime;
    
    high_resolution_clock::time_point oldTime;
    high_resolution_clock::time_point oldBigTime;
    
    high_resolution_clock::time_point newTime;
    
    
    //Constructors & Destructor
public:
    TimeClock();
    explicit TimeClock(const std::string & str);
    
    //Methods
public:
    void tick();
    void tick(const std::string & str);
    
    void startSection();
    void startSection(const std::string & str);
    void endSection();
    void endSection(const std::string & str);
    
    void finalize();
};

#endif /* TimeClock_hpp */
