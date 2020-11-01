#pragma once

#ifndef __CHECK__
#define __CHECK__

#include <string>
#include <algorithm>
#include "../strings.h"
#include <iostream>
using namespace std;

#define _NORMAL 0
#define _SCNAME 1
#define _PW 2
#define _ACCEPTABLE 3
#define _DATE 4
#define _SCSIZE 5

class check
{
public:
    check() {}

    // 뒤로가기 체크
    bool qCheck(const string &s)
    {
        // 문자열 길이가 1이고 그것이 q라면.
        if (s.size() == 1 && s[0] == 'q')
            return true;
        return false;
    }
    //한글이랑 문자 포함해서 2바이트로 계산안하고 진짜 로우한 길이 재는 함수.
    int stringSize(string s) {
	    int hcount = 0;
	    int count = 0;
	    //cout << s.size() << endl;
	    //cout << s.length() << endl;
	    for (int i = 0; i < s.size(); i++) {
		    if ((s[i] & 0x80) == 0x80) {
			    hcount += 1;
			    //cout << hcount << "@" << endl;
		    }
		    else {
			    count += 1;
			    //cout << count << "!" << endl;
		    }
	    }
	    return (hcount / 2 + count);
    }
    bool hangeulCheck(char &s);

    // 인코딩 체크
    // bool encodingCheck(string &s)
    // {
    //     // cout << s << endl;

    //     string e = "";

    //     for (int i = (int)'a'; i <= (int)'z'; ++i)
    //         e += (char)i;
    //     for (int i = (int)'A'; i <= (int)'Z'; ++i)
    //         e += (char)i;
    //     for (int i = (int)'0'; i <= (int)'9'; ++i)
    //         e += (char)i;

    //     for (int i = 0; i < s.size(); ++i)
    //         // 이게 소문자 or 대문자 or 숫자가 아니라면
    //         if (e.find(s[i]) == string::npos)
    //         {
    //             // 해당위치에서 자름.
    //             string hanguelStart = s.substr(i, s.size());
                
    //             // 한글인지 검사한다.
    //             return hangeulCheck(hanguelStart);

    //         }

    //     return true;
    // }
        // 인코딩 체크
    bool encodingCheck(string& s){
        // cout << s << endl;

        string e = "";

        for(int i = (int)'a'; i <= (int)'z'; ++i) e += (char)i;
        for(int i = (int)'A'; i <= (int)'Z'; ++i) e += (char)i;
        for(int i = (int)'0'; i <= (int)'9'; ++i) e += (char)i;
        e+= ' ';
        // for(int i = 0; i < s.size(); ++i)
        //     // 이게 소문자 or 대문자 or 숫자가 아니라면
        //     if(e.find(s[i]) == string::npos){
        //         // 해당위치에서 자름.
        //         string hanguelStart = s.substr(i, s.size());
        //         // 한글인지 검사한다.
        //         return hangeulCheck(hanguelStart);
        //     }
        for(int i = 0; i < s.size(); ++i)
            if(e.find(s[i]) == string::npos && !hangeulCheck(s[i])) return false;

        return true;
    }
    
    int  getNumberOfDays(int month, int year) {
	    //leap year condition, if month is 2
	    if( month == 2)
	    {
            if(70 <= year <= 99) {
                year += 1900;
            } else {
                year += 2000;
            }
            if((year%400==0) || (year%4==0 && year%100!=0))	
		    	return 29;
		        else	
		    	return 28;
		    
	    }
	    //months which has 31 days
	    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month==12)	
	    	return 31;
	    else 		
	    	return 30;
    } 

    // 이 문자열이 숫자로만 이루어진 문자열이라면 true
    bool isOnlyNumber(const string &s)
    {
        string num = "0123456789";
        for (char c : s)
            if (num.find(c) == string::npos)
                return false;
        return true;
    }

    // 숫자로만 이루어졌고, 1이상 upper이하의 숫자라면 true
    bool numberCheck(const string &s, int upper)
    {
        if (!isOnlyNumber(s))
            return false;
        if (stoi(s) > upper || stoi(s) < 1)
            return false;
        return true;
    }
    bool findCheck(string ss, string s)
    {
        int it = ss.find(s);
        if (it == string::npos)
        {
            return false;
        }
        else
            return true;
    }
    
    int dateVaild(string yymmdd)
    {
        if (findCheck(yymmdd, "$") || yymmdd.length() < 6 || yymmdd.length() == 7 || yymmdd.length() > 8)
        {
            cout << err[0];
            return 2;
        }

        if (yymmdd.length() == 8 && !((yymmdd[2] == '-' || yymmdd[2] == '/') && (yymmdd[5] == '-' || yymmdd[5] == '/')))
        {
            cout << err[0];
            return 2;
        }

        check C = check();

        yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
        yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());

        if (!isOnlyNumber(yymmdd) || yymmdd.length() != 6)
        {
            cout << err[0];
            return 2;
        }

        int mm = stoi(yymmdd.substr(2, 2));
        int dd = stoi(yymmdd.substr(4, 2));

        if (mm < 1 || mm > 12 || dd < 1 || dd > 31)
        {
            cout << err[0];
            return 1;
        }

        return 0;
    }

    // 종합 체크
    bool totalCheck(string &s, int n, int upper)
    {
        // 일반 메뉴 선택 입력
        if (n == _NORMAL)
        {
            if (s.size() != 1)
                return false;
            return numberCheck(s, upper);
        }

        if (n == _SCSIZE)
        {
            if (!isOnlyNumber(s))
                return false;
            if (stoi(s) > upper)
                return false;
        }

        // 캘이름
        if (n == _SCNAME)
        {
            if (stringSize(s) < 2 || stringSize(s) > 10) return false;
            return encodingCheck(s);
        }

        // 캘 비번
        if (n == _PW)
        {
            if (stringSize(s) < 2 || stringSize(s) > 15)
                return false;
            return encodingCheck(s);
        }

        // 입장인원
        if (n == _ACCEPTABLE)
        {
            if (stringSize(s) != 1)
                return false;
            return numberCheck(s, 5);
        }

        // 유효기간
        if (n == _DATE)
        {
            //cout << "this is dateValid" << endl;
            if (dateVaild(s) != 0)
                return false;
        }

        return true;
    }
};

#include "check.hpp"
#endif