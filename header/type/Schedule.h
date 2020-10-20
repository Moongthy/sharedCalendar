#pragma once

#ifndef __SCHEDULE__
#define __SCHEDULE__

#include<string>
using std::string;

class Schedule{
public:
    int startTime;
    int endTime;
    string content;

    Schedule(int startTime, int endTime, string content)
        : startTime(startTime), endTime(endTime), content(content) { }

    int getStartTime(){
        return startTime;
    }

    int getEndTime(){
        return endTime;
    }

    string getContent(){
        return content;
    }

    
};

#endif