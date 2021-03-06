#pragma once

#ifndef __USER__
#define __USER__

#include<string>

using std::string;

class User{
public:

    // 사용자 이름
    string userName;

    // 사용자 아이디
    string userId;

    // 생성자
    User(string userName, string userId) : userName(userName), userId(userId) { };
    
    // getter
    string getUserName(){
        return userName;
    }

    string getUserId(){
        return userId;
    }

        // setter
    void setUserId(string id)
    {
	    userId = id;
    }
    
    void setUserName(string name)
    {
	    userName = name;
    }
};

#endif