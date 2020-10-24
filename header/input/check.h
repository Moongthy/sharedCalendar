#pragma once

#ifndef __CHECK__
#define __CHECK__

#include<string>
using std::string;

#define _NORMAL 0
#define _SCNAME 1
#define _PW 2
#define _ACCEPTABLE 3
#define _DATE 4

class check{
public:

    check(){ }

    bool qCheck(const string& s){
        if(s.size() == 1 && s[0] == 'q')
            return true;
        return false;
    }

    bool encodingCheck(const string& s){
        string e = "";
        for(int i = (int)'a'; i <= (int)'z'; ++i) e += (char)i;
        for(int i = (int)'A'; i <= (int)'Z'; ++i) e += (char)i;
        // for(int i = 44032; i <= 55203; ++i) e+= (wchar_t)i;
        for(int i = (int)'0'; i <= (int)'9'; ++i) e += (char)i;

        for(char u : s)
            if(e.find(u) == string::npos)
                return false;

        return true;
    }

    bool numberCheck(const string& s, int upper){
        string num = "0123456789";
        if(num.find(s) == string::npos)
            return false;
        if(stoi(s) > upper) return false;
        return true;
    }

    bool dateCheck(const string& s){
        string num = "0123456789";
        for(char c : s)
            if(num.find(c) == string::npos){
                cout << "fuck" << "\n";
                return false;
            }
        return true;
    }

    bool totalCheck(string& s, int n, int upper){
        // 일반 메뉴 선택 입력
        if(n == _NORMAL){
            if(s.size() != 1) return false;
            return numberCheck(s, upper);
        }

        // 캘이름
        if(n == _SCNAME){
            if(s.size() < 2 || s.size() > 10) return false;
            return encodingCheck(s);
        }

        // 캘 비번
        if(n == _PW){
            if(s.size() < 2 || s.size() > 15) return false;
            return encodingCheck(s);
        }

        // 입장인원
        if(n == _ACCEPTABLE){
            if(s.size() != 1) return false;
            return numberCheck(s, 5);
        }

        // 유효기간
        if(n == _DATE){
            return true;
        }

        return true; 
    }
};

#endif