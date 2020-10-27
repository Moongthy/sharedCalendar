#pragma once

#ifndef __SCHEDULE__
#define __SCHEDULE__

#include <bits/stdc++.h>
#include "Date.h"
#include "string.h"
using namespace std;

class Schedule{
private:
    int id;
    string title;
    Date date;
    int startTime;
    int endTime;
    string content;
    string location;
    
    Schedule(string title, Date date, int startTime, int endTime, string content = "", string location = "", int id = -1)
        : id(id), title(title), date(date), startTime(startTime), endTime(endTime), location(location), content(content) {
        if (this -> date > date) {
            cout << "";
        }
        cout << "";
    }

public :
    string getTitle() {
        return title;
    }
    string setTitle(string title) {
        title = title;
    }
    Date getDate() {
        return date;
    }
    Date setDate(Date date) {
        date = date;
    }
    int getStartTime(){
        return startTime;
    }
    int setStartTime(int startTime) {
        startTime = startTime;
    }
    int getEndTime(){
        return endTime;
    }
    int setEndTime(int endTime) {
        endTime = endTime;
    }
    string getContent(){
        return content;
    }
    string setContent(string content) {
        content = content;
    }
    string getLocation() {
        return location;
    }
    string setLocation(string location) {
        location = location;
    }
};

#endif