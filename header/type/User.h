#pragma once

#ifndef __USER__
#define __USER__

#include<string>

using std::string;

class User{
public:
    string userName;
    int userId;

    string getUserName(){
        return userName;
    }

    User(string userName, int userId) : userName(userName), userId(userId) { };

    int getUserId(){
        return userId;
    }
};

#endif