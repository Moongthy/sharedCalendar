#pragma once

#include <direct.h>
#include <io.h>
#include <map>
#include "User.h"
#include "../ReadFile.h"
#include "../input/check.h"

using namespace std;

class Users : public User
{
private:
	string userPw;

public:
	Users(string userName, string userId);

	string getUserPw();
	void setUserPw(string pw);

	void firstMenu(); 
	void signIn();
	void signUp();

	bool isOverlap(string id); // id already exist?
	bool isFine(string id, string pw); // (id, pw) match?

	string getUserNameList(string userId);
	string getInput(string menuname, string purpose, int start, int end);

	void isDirExist(const char* dirpath);
	void isFileExist(const char* filepath);
};

#include "../../source/Users.hpp"