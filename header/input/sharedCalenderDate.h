#pragma once

#ifndef __SHAREDCALENDARDATE__
#define __SHAREDCALENDARDATE__

#include"UserInput.h"

class SharedCalendar : public UserInput{
    
    int yy;
    int mm;
    int dd;

    bool lengthCheck(){
        if(userInput.size() >= 6 && userInput.size() <= 8)
            return true;
        return false;
    }

};

#endif