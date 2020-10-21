#pragma once

#ifndef __INPUT__
#define __INPUT__

#include<iostream>
#include<algorithm>
using namespace std;

/**
 *  사용자에게 입력 클래스 
 */

#define LEN_ERR         0
#define ENCODING_ERR    1
#define Q_ERROR         2

struct Input{

    string encoding;
    
    void userInput2Lower(string& s);

    void removeSpace(string& s);
    
    string input();
    
    int colanderEncodingErr(const string& s) const;

    int colanderLenErr(const string& s, std::pair<int, int> len) const;

    int checkSharedCalendarName(const string& s) const; 

    int checkSharedCalendarPassWord(const string& s) const;

    bool simpleCheck(const string& check, string& s) const;

    int checkSharedCalenderAcceptable(const string& s) const;

    int checkSharedCalendrDate(const string& s) const;

};

#endif