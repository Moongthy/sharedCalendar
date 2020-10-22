#pragma once

#ifndef __SHAREDCALENDARIDINPUT__
#define __SHAREDCALENDARIDINPUT__

#include"UserInput.h"

#include<string>
#include<iostream>

class SharedCalendarName : public UserInput{
public:
    SharedCalendarName();

    bool lengthCheck();

    // 검색한 문자열에 해당하는 인덱스를 반환.
    // 검색한 문자열이 매치되지 않는다면 string::npos 반환
    bool searchCompare(const string& s);
};

#endif