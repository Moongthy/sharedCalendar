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
			cout << "�ùٸ� �Է������� �ƴմϴ�.\n";
			Sleep(1500);
		}
	}
	return id;
}

string Users::inputUserPw()
{
	string pw;
	cout << ("��й�ȣ> ");
	while (true) {
		cin >> pw;
		if (pw.compare("q") == 0) {
			break;
		}

		if (regex_match(pw, pattern) && (pw.length() >= 2 && pw.length() <= 15)) {
			break;
		}
		else {
			cout << "�ùٸ� �Է������� �ƴմϴ�.\n";
			Sleep(1500);
		}
	}

	return pw;
}

string Users::inputUserName()
{
	string name;
	cout << ("�̸�> ");
	while (true) {
		cin >> name;
		if (name.compare("q") == 0) {
			break;
		}

		if (regex_match(name, pattern) && (name.length() >= 2 && name.length() <= 10)) {
			break;
		}
		else {
			cout << "�ùٸ� �Է������� �ƴմϴ�.\n";
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


// [�α��� ���� �޴�]
void Users::firstMenu()
{
	int select;

	while (true) {
		string s_select;
		system("cls");
		cout << "[�α��� �޴� ����]\n";
		cout << "1. �α���\n2. �ű԰���\n3. ����\n> ";
		cin >> s_select;

		if (s_select.compare("1") == 0 || s_select.compare("2") == 0 || s_select.compare("3") == 0) {
			select = stoi(s_select);
			break;
		}
		else {
			system("cls");
			cout << ("[�α��� �޴� ����]\n");
			cout << ("�ùٸ� �Է������� �ƴմϴ�.\n");
			Sleep(1500);
		}
	}

	switch (select) {
	case 1:
		//�α��� �̵�
		signIn();
		break;
	case 2:
		//ȸ������ �̵�
		signUp();
		break;
	case 3:
		//���α׷� ����
		system("cls");
		cout << ("[����]\n�ȳ���������.\n");
		exit(0);
		break;
	}
}

// [�α���]
void Users::signIn()
{
	system("cls");
	cout << ("[�α���]\n");

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
			//�α��� ���� �޼���
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

// [ȸ������]
void Users::signUp()
{
	system("cls");
	cout << ("[ȸ������]\n");
	int flag = 0;
	string id;
	string pw;
	string name;


	while (true) {
		// ���̵� �Է�
		while (true) {
			id = inputUserId();
			if (id.compare("q") == 0) {
				flag = -1;
				break;
			}

			if (!isOverlap(id)) {
				cout << ("�̹� �����ϴ� ID�Դϴ�\n");
				Sleep(1500);
			}
			else {
				break;
			}
		}

		// ��й�ȣ �Է�
		pw = inputUserPw();
		if (pw.compare("q") == 0) {
			flag = -1;
			break;
		}

		// �̸� �Է�
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

// ȸ������ �� id �ߺ� �˻� (true -> �ߺ� X, false -> �ߺ� O)
bool Users::isOverlap(string id)
{
	map<string, string> map = getUserList();
	auto it = map.find(id);

	if (it != map.end()) {
		//�ߺ� �˻� ���
		return true;
	}
	else {
		//�ߺ� �߰�
		return false;
	}
}

// �α��� ����
bool Users::isFine(string id, string pw)
{
	map<string, string> map = getUserList();
	auto it = map.find(id);

	if (it != map.end()) {
		//���Ե� ID ����
		return false;
	}
	else {
		if (it->first == id && it->second == pw) {
			return true;
		}
		else {
			//ID,��� ����ġ
			return false;
		}

	}
}

// ID,PW ��� vector ��ȯ
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

// data/UserList.txt�� ����
void Users::writeUserList(string id, string pw, string name)
{
	write.open("data/UserList.txt", ios::app);
	write << id + separator + pw + separator + name << endl;
	write.close();
}
