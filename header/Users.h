#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <regex>
#include <Map>

using namespace std;

class Users
{
private:
	string userId;
	string userPw;
	string userName;

	ifstream read;
	ofstream write;
	int separatorIndex;
	string separator = "$";

	regex pattern {"/^[°¡-ÆRa-zA-Z0-9]+$/"};

public:
	Users(string userName, string userId);

	string inputUserId(); // ID ÀÔ·Â
	string inputUserPw(); // ºñ¹Ğ¹øÈ£ ÀÔ·Â
	string inputUserName(); // ÀÌ¸§ ÀÔ·Â

	string getUserId();
	string getUserPw();
	string getUserName();

	void firstMenu(); //·Î±×ÀÎ ¼±ÅÃ ¸Ş´º
	
	void signIn(); //·Î±×ÀÎ
	void signUp(); //½Å±Ô°¡ÀÔ

	map<string,string> getUserList();
	bool isOverlap(string id); // Áßº¹ È®ÀÎ
	bool isFine(string id, string pw); // ·Î±×ÀÎ °ËÁõ


	void writeUserList(string id, string pw, string name);
};