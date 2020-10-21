#pragma once

#ifndef __USER__
#define __USER__

#include<string>

using std::string;

class User{
public:
    string userName;
    string userId;

    string getUserName(){
        return userName;
    }

    User(string userName, string userId) : userName(userName), userId(userId) { };

    string getUserId(){
        return userId;
    }
};

#endif
