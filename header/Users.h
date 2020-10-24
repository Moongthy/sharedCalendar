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

	regex pattern {"/^[��-�Ra-zA-Z0-9]+$/"};

public:
	Users(string userName, string userId);

	string inputUserId(); // ID �Է�
	string inputUserPw(); // ��й�ȣ �Է�
	string inputUserName(); // �̸� �Է�

	string getUserId();
	string getUserPw();
	string getUserName();

	void firstMenu(); //�α��� ���� �޴�
	
	void signIn(); //�α���
	void signUp(); //�ű԰���

	map<string,string> getUserList();
	bool isOverlap(string id); // �ߺ� Ȯ��
	bool isFine(string id, string pw); // �α��� ����


	void writeUserList(string id, string pw, string name);
};