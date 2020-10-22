#pragma once

#ifndef __USERINPUT__
#define __USERINPUT__

#include<string>
#include<algorithm>
#include<iostream>

using std::string;
using std::cin;
class UserInput{

public:

    string userInput;

    UserInput();

    bool qCheck();

    bool encodingCheck();

    string lower(const string& s);

    virtual bool lengthCheck();

    virtual bool serachCompare();
    
};

#endif