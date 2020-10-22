#include"../header/input/sharedCalendarName.h"

SharedCalendarName::SharedCalendarName() : UserInput() { };

bool SharedCalendarName::lengthCheck(){
    if(userInput.size() < 2 || userInput.size() > 10)
        return false;
    return true;
}

bool SharedCalendarName::searchCompare(const string& s){
    return userInput.find(s);
}



