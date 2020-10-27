#pragma once

#ifndef ___date___
#define ___date___
#include <bits/stdc++.h>

using namespace std;

class Date {
public:
<<<<<<< HEAD
	int yy;
	int mm;
	int dd;
	Date(string yymmdd) {
		yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
		yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());

		yy = stoi(yymmdd.substr(0,1));
		mm = stoi(yymmdd.substr(2,3));
		dd = stoi(yymmdd.substr(4,5));

		if (0 <= yy && yy < 70) yy += 2000;
		else if (70 <= yy && yy < 100) yy += 1900;
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
=======
    int yy;
    int mm;
    int dd;

    Date(int yy, int mm, int dd) : yy(yy), mm(mm), dd(dd) { }
>>>>>>> 1b639908ec041da71eca208f9cfc4b37a8f71b08
};

#endif