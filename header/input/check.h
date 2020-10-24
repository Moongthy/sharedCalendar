#pragma once

#ifndef __CHECK__
#define __CHECK__

#include<string>
using std::string;

class check{
public:

    check(){ }

    bool qCheck(const string& s){
        if(s.size() == 1 && s[0] == 'q')
            return true;
        return false;
    }

    bool lengthCheck(const string& s, int n){
        if((n == 0) && (s.size() != 1)) return false;

        // 캘이름
        if((n == 1) && (s.size() < 2 || s.size() > 10)) return false;

        // 캘 비번
        if((n == 2) && (s.size() < 2 || s.size() > 15)) return false;

        // 입장인원
        if((n == 3) &&(stoi(s) < 2 || stoi(s) > 5)) return false;

        // 유효기간
        if((n == 4) && (s.size() < 2 || s.size() > 10)) return false;

        return true; 
    }

    bool encodingCheck(const string& s){
        string e = "";
        for(int i = (int)'a'; i <= (int)'z'; ++i) e += (char)i;
        for(int i = (int)'A'; i <= (int)'Z'; ++i) e += (char)i;
        // for(int i = (int)'가'; i <= (int)'힣'; ++i) s += (char)i;
        for(int i = (int)'0'; i <= (int)'9'; ++i) e += (char)i;

        for(char u : s)
            if(e.find(u) == string::npos)
                return false;
        return true;
    }

    bool numberCheck(const string & s, int n){
        
        if(s.size() != 1) return false;
        
        string number = "1234567890";

        if(number.find(s) == string::npos) return false;

        if(stoi(s) > n) return false;

        return true;
    }

    bool totalCheck(const string& s, int n){
        if(!lengthCheck(s, n) || !encodingCheck(s)) return false;
        return true;
    }
};

#endif