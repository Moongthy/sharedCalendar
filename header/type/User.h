#pragma once

#ifndef __USER__
#define __USER__

#include<string>

using std::string;

class User{
public:

    // 사용자 이름
    string userName;
<<<<<<< HEAD
=======
    string userId;
>>>>>>> 4448beadf882fcea1d7e4627976c07e85759b727

    // 사용자 아이디
    string userId;

    // 생성자
    User(string userName, string userId) : userName(userName), userId(userId) { };
    
    // getter
    string getUserName(){
        return userName;
    }

<<<<<<< HEAD
    // getter
=======
    User(string userName, string userId) : userName(userName), userId(userId) { };

>>>>>>> 4448beadf882fcea1d7e4627976c07e85759b727
    string getUserId(){
        return userId;
    }
};

#endif
