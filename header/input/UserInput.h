#pragma once

#ifndef __USERINPUT__
#define __USERINPUT__

#include<string>
#include<iostream>
using std::string;
using std::cin;
class UserInput{

public:

    string userInput;

    UserInput();

    bool qCheck();

    virtual bool encodingCheck();

    virtual bool lengthCheck();

    virtual bool serachCompare();
    
};

#endif