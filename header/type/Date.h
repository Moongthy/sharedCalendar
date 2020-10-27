#pragma once

#ifndef ___date___
#define ___date___
#include <bits/stdc++.h>

using namespace std;

class Date {
public:
	int yy;
	int mm;
	int dd;
	Date(string yymmdd) {
		yymmdd.erase(std::remove(str.begin(), str.end(), '#'), str.end());
		yymmdd.erase(std::remove(str.begin(), str.end(), '#'), str.end());

		yy = stoi(yymmdd[0]+yymmdd[1]);
		mm = stoi(yymmdd[2]+yymmdd[3]);
		dd = stoi(yymmdd[4]+yymmdd[5]);
	}
	Date(int yy, int mm, int dd) : mm(mm), dd(dd) {
		if (0 <= yy && yy < 70) yy += 2000;
		else if (70 <= yy && yy < 100) yy += 1900;
	}
	
	bool operator>(Date date) {
		if (yy > date.yy) {
			return true;
		}
		else if (yy == date.yy && mm > date.mm) {
			return true;
		}
		else if (yy == date.yy && mm == date.mm) {
			if (dd > date.dd) {
				return true;
			}
			else return false;
		}
		return false;
	}
};

#endif