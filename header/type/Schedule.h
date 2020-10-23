#pragma once

#ifndef __SCHEDULE__
#define __SCHEDULE__

#include<string>
#include"Date.h"
using std::string;

class Schedule{
private:
    int id
    string title;
    Date date;
    int startTime;
    int endTime;
    string content;
    string location;
    
    Schedule(string title, Date date, int startTime, int endTime, string content = '', string location = '', int id = -1)
        : id(id), title(title), date(date), startTime(startTime), endTime(endTime), location(location), content(content) {
        if (this.date > date) {
            cout << "잘못 된 시간을 일정에 입력함"
        }
        cout << "스케쥴 객채 생성 완료";
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
        endTime = endTime
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