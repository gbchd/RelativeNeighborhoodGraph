//
//  TimeClock.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 24/12/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "TimeClock.hpp"

//Constructors
TimeClock::TimeClock():startTime(high_resolution_clock::now()),oldTime(startTime),oldBigTime(startTime),newTime(startTime){
}

TimeClock::TimeClock(const std::string & str):startTime(high_resolution_clock::now()),oldTime(startTime),oldBigTime(startTime),newTime(startTime){
    std::cout << str << std::endl;
}

//Public methods

void TimeClock::tick(){
    newTime = high_resolution_clock::now();
    milliseconds timeSpent = duration_cast<milliseconds>(newTime - oldTime);
    std::cout << "-Task has taken : " << timeSpent.count() << "ms" << std::endl;
    oldTime = newTime;
}

void TimeClock::tick(const std::string & str){
    newTime = high_resolution_clock::now();
    milliseconds timeSpent = duration_cast<milliseconds>(newTime - oldTime);
    std::cout << "-" << str << " : " << timeSpent.count() << "ms" << std::endl;
    oldTime = newTime;
}

void TimeClock::startSection(){
    std::cout << "===Starting a new section===" << std::endl;
}

void TimeClock::startSection(const std::string & str){
    std::cout << "===Starting " << str << "===" << std::endl;
}

void TimeClock::endSection(){
    milliseconds timeSpent = duration_cast<milliseconds>(newTime - oldBigTime);
    std::cout << "===The section has taken : " << timeSpent.count() << "ms===" << std::endl << std::endl;
    oldBigTime = newTime;
}

void TimeClock::endSection(const std::string & str){
    milliseconds timeSpent = duration_cast<milliseconds>(newTime - oldBigTime);
    std::cout << "===" << str << " : " << timeSpent.count() << "ms===" << std::endl << std::endl;
    oldBigTime = newTime;
}

void TimeClock::finalize(){
    newTime = high_resolution_clock::now();
    milliseconds timeSpent = duration_cast<milliseconds>(newTime - startTime);
    std::cout << "The program has been done in " << timeSpent.count() << "ms" << std::endl;
}

