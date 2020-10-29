#pragma once

#ifndef __SCHEDULE__
#define __SCHEDULE__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Date.h"
#include "string.h"

using namespace std;

class Schedule{
private:
    
    // 일정 아이디.
    int id;
    
    // 이게 뭐죠?
    string title;

    Date date;
    
    // 일정 시작 시간
    int startTime;
    
    // 일정 끝 시간
    int endTime;
    
    // 일정 내용
    string content;
    
    // 일정 장소
    string location;

public :
    Schedule(string title, Date date, int startTime, int endTime, string content = "", string location = "", int id = -1)
        : id(id), title(title), date(date), startTime(startTime), endTime(endTime), location(location), content(content) {
        if (this -> date > date) {
            std::cout << "";
        }
        std::cout << "";
    }

    //임시 생성자
    Schedule();

    string getTitle() {
        return title;
    }
    void setTitle(string title) {
        this -> title = title;
    }
    Date getDate() {
        return date;
    }
    void setDate(Date date) {
        this -> date = date;
    }
    int getStartTime(){
        return startTime;
    }
    void setStartTime(int startTime) {
        this -> startTime = startTime;
    }
    int getEndTime(){
        return endTime;
    }
    void setEndTime(int endTime) {
        this -> endTime = endTime;
    }
    string getContent(){
        return content;
    }
    void setContent(string content) {
        this -> content = content;
    }
    string getLocation() {
        return location;
    }
    void setLocation(string location) {
        this -> location = location;
    }
    int getID() {
        return id;
    }
};

#endif