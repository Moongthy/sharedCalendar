#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <errno.h>
#include <locale>
#include <Map>
#include <regex>
#include <io.h>

#include"User.h"

using namespace std;

class Users : public User
{
private:
	
	string userPw;

	ifstream read;
	ofstream write;
	int separatorIndex;
	string separator = "$";

public:
	Users(string userId, string userName);

	void setUserId(const string& id);
	void setUserPw(const string& pw);
	void setUserName(const string& name);

	string getUserPw();

	void firstMenu(); // 첫화면
	void signIn(); //로그인
	void signUp(); //회원가입

	map<string, string> getUserList();
	map<string, string> getUserIdName();

	bool isOverlap(string id); // 회원가입 시 ID 중복검사
	bool isFine(string id, string pw); // 로그인 시 ID PW 매칭 검사
	void writeUserList(string id, string pw, string name);

	bool wencodingCheck(const wstring& s);
	wstring getwInput(wstring menuname, wstring purpose, int start,int end);
	string convertWstring(wstring const& wstr, locale const& loc);

	void isDirExist(const char* dirpath);
	void isFileExist(const char* filepath);
};

#include "../../source/Users.hpp"