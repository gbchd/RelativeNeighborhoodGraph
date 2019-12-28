//
//  TimeClock.cpp
//  RelativeNeighborhoodGraph
//
//  Created by GuillaumeBouchard ColinTroisemaine on 24/12/2019.
//  Copyright © 2019 GuillaumeBouchard ColinTroisemaine. All rights reserved.
//

#include "TimeClock.hpp"

//Constructors
TimeClock::TimeClock():startTime(std::time(nullptr)),oldTime(startTime),oldBigTime(startTime),newTime(startTime){
}

TimeClock::TimeClock(const std::string & str):startTime(std::time(nullptr)),oldTime(startTime),oldBigTime(startTime),newTime(startTime){
    std::cout << str << std::endl;
}

//Public methods

void TimeClock::tick(){
    newTime = std::time(nullptr);
    std::cout << "-Task has taken : " << newTime - oldTime << "s" << std::endl;
    oldTime = newTime;
}

void TimeClock::tick(const std::string & str){
    newTime = std::time(nullptr);
    std::cout << "-" << str << " : " << newTime - oldTime << "s" << std::endl;
    oldTime = newTime;
}

void TimeClock::startSection(){
    std::cout << "===Starting a new section===" << std::endl;
}

void TimeClock::startSection(const std::string & str){
    std::cout << "===Starting " << str << "===" << std::endl;
}

void TimeClock::endSection(){
    std::cout << "===The section has taken : " << newTime - oldBigTime << "s===" << std::endl << std::endl;
    oldBigTime = newTime;
}

void TimeClock::endSection(const std::string & str){
    std::cout << "===" << str << " : " << newTime - oldBigTime << "s===" << std::endl << std::endl;
    oldBigTime = newTime;
}

void TimeClock::finalize(){
    newTime = std::time(nullptr);
    std::cout << "The program has been done in " << newTime - startTime << "s" << std::endl;
}

