#pragma once

#ifndef __SHAREDCALENDARPASSWORD__
#define __SHAREDCALENDARPASSWORD__

#include"UserInput.h"

class SharedCalendarPassWord : public UserInput{
public:

    SharedCalendarPassWord() : UserInput() { }

    bool lengthCheck(){
        if(userInput.size() < 1 || userInput.size() > 15)
            return false;
        return true;
    }

    bool otherCheck(){
        string check = "???????"; // 구분자가뭐임.
        for(char x : userInput)
            if(check.find(x) != string::npos)
                return false;
        return true;
    }

    bool compare(const string& s){
        if(s == userInput) return true;
        return false;
    }
};

#endif