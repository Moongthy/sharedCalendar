#pragma once

#ifndef __SHAREDCALENDARNAME__
#define __SHAREDCALENDARNAME__

#include"UserInput.h"

#include<string>
#include<iostream>

class SharedCalendarName : public UserInput{
public:

    SharedCalendarName() : UserInput() { }

    bool lengthCheck(){
        if(userInput.size() < 2 || userInput.size() > 10)
            return false;
        return true;
    }

    // 검색한 문자열에 해당하는 인덱스를 반환.
    // 둘다 소문자로 바꾼 후 비교함.
    // 검색한 문자열이 매치되지 않는다면 string::npos 반환
    bool searchCompare(const string& s){
        return lower(userInput).find(lower(s));
    }
};

#endif