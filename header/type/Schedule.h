#pragma once

#ifndef __SCHEDULE__
#define __SCHEDULE__

#include<string>
#include"Date.h"
using std::string;

class Schedule{
public:
    Date startTime;
    Date endTime;
    string content;

    Schedule(Date startTime, Date endTime, string content)
        : startTime(startTime), endTime(endTime), content(content) { }

    Date getStartTime(){
        return startTime;
    }

    Date getEndTime(){
        return endTime;
    }

    string getContent(){
        return content;
    }
};

#endif