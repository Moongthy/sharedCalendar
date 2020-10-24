//#include "Users.h"
#include "../header/Users.h"

Users::Users(string userName, string userId)
	: userName(userName), userId(userId)
{

}


string Users::inputUserId()
{
	string id;
	cout << ("ID> ");
	while (true) {
		cin >> id;
		if (id.compare("q") == 0) {
			break;
		}

		if (regex_match(id, pattern) && (id.length() >= 2 && id.length() <= 10)) {
			break;
		}
		else {
			cout << "올바른 입력형식이 아닙니다.\n";
			Sleep(1500);
		}
	}
	return id;
}

string Users::inputUserPw()
{
	string pw;
	cout << ("비밀번호> ");
	while (true) {
		cin >> pw;
		if (pw.compare("q") == 0) {
			break;
		}

		if (regex_match(pw, pattern) && (pw.length() >= 2 && pw.length() <= 15)) {
			break;
		}
		else {
			cout << "올바른 입력형식이 아닙니다.\n";
			Sleep(1500);
		}
	}

	return pw;
}

string Users::inputUserName()
{
	string name;
	cout << ("이름> ");
	while (true) {
		cin >> name;
		if (name.compare("q") == 0) {
			break;
		}

		if (regex_match(name, pattern) && (name.length() >= 2 && name.length() <= 10)) {
			break;
		}
		else {
			cout << "올바른 입력형식이 아닙니다.\n";
			Sleep(1500);
		}
	}

	return name;
}


string Users::getUserId()
{
	return userId;
}

string Users::getUserPw()
{
	return userPw;
}

string Users::getUserName()
{
	return userName;
}


// [로그인 선택 메뉴]
void Users::firstMenu()
{
	int select;

	while (true) {
		string s_select;
		system("cls");
		cout << "[로그인 메뉴 선택]\n";
		cout << "1. 로그인\n2. 신규가입\n3. 종료\n> ";
		cin >> s_select;

		if (s_select.compare("1") == 0 || s_select.compare("2") == 0 || s_select.compare("3") == 0) {
			select = stoi(s_select);
			break;
		}
		else {
			system("cls");
			cout << ("[로그인 메뉴 선택]\n");
			cout << ("올바른 입력형식이 아닙니다.\n");
			Sleep(1500);
		}
	}

	switch (select) {
	case 1:
		//로그인 이동
		signIn();
		break;
	case 2:
		//회원가입 이동
		signUp();
		break;
	case 3:
		//프로그램 종료
		system("cls");
		cout << ("[종료]\n안녕히가세요.\n");
		exit(0);
		break;
	}
}

// [로그인]
void Users::signIn()
{
	system("cls");
	cout << ("[로그인]\n");

	int flag = 0;
	string id;
	string pw;

	while (true) {

		id = inputUserId();
		if (id.compare("q") == 0) {
			flag = -1;
			break;
		}

		pw = inputUserPw();
		if (pw.compare("q") == 0) {
			flag = -1;
			break;
		}

		if (isFine(id, pw)) {
			flag = 1;
			break;
		}
		else {
			flag = -1;
			//로그인 실패 메세지
			break;
		}
	}

	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		//Calendar(id,name);
	}
}

// [회원가입]
void Users::signUp()
{
	system("cls");
	cout << ("[회원가입]\n");
	int flag = 0;
	string id;
	string pw;
	string name;


	while (true) {
		// 아이디 입력
		while (true) {
			id = inputUserId();
			if (id.compare("q") == 0) {
				flag = -1;
				break;
			}

			if (!isOverlap(id)) {
				cout << ("이미 존재하는 ID입니다\n");
				Sleep(1500);
			}
			else {
				break;
			}
		}

		// 비밀번호 입력
		pw = inputUserPw();
		if (pw.compare("q") == 0) {
			flag = -1;
			break;
		}

		// 이름 입력
		name = inputUserName();
		if (name.compare("q") == 0) {
			flag = -1;
			break;
		}
	}

	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		writeUserList(id, pw, name);
		// Calender(Users(id,name));
	}
}

// 회원가입 시 id 중복 검사 (true -> 중복 X, false -> 중복 O)
bool Users::isOverlap(string id)
{
	map<string, string> map = getUserList();
	auto it = map.find(id);

	if (it != map.end()) {
		//중복 검사 통과
		return true;
	}
	else {
		//중복 발견
		return false;
	}
}

// 로그인 검증
bool Users::isFine(string id, string pw)
{
	map<string, string> map = getUserList();
	auto it = map.find(id);

	if (it != map.end()) {
		//가입된 ID 없음
		return false;
	}
	else {
		if (it->first == id && it->second == pw) {
			return true;
		}
		else {
			//ID,비번 불일치
			return false;
		}

	}
}

// ID,PW 담는 vector 반환
map<string, string> Users::getUserList()
{
	read.open("data/UserList.txt");
	char str[sizeof(read)] = { '\0' };
	int i = 0;
	map<string, string> userInfo;
	if (read.good())
	{
		while (!read.eof())
		{
			read.getline(str, sizeof(read));
			if (read.eof()) break;

			string id = "";
			string pw = "";
			string name = "";
			separatorIndex = 0;
			for (i = 0; i < sizeof(read); i++)
			{
				if (str[i] == '$') {
					separatorIndex++;
					i++;
				}
				else {
					if (separatorIndex == 0) id += str[i];
					else if (separatorIndex == 1) pw += str[i];
					else if (separatorIndex == 2) break;
				}
			}
			userInfo.insert(make_pair(id, pw));
		}

	}
	else cout << "[UserList.txt] read error!" << endl;

	read.close();

	return userInfo;
}

// data/UserList.txt에 쓰기
void Users::writeUserList(string id, string pw, string name)
{
	write.open("data/UserList.txt", ios::app);
	write << id + separator + pw + separator + name << endl;
	write.close();
}
