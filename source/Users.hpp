Users::Users(string userId, string userName)
	: User(userId, userName)
{
	isDirExist("data");
	isFileExist("data/UserList.txt");
}

void Users::setUserId(const string& id)
{
	this->userId = id;
}

void Users::setUserPw(const string& pw)
{
	this->userPw = pw;
}

void Users::setUserName(const string& name)
{
	this->userName = name;
}



string Users::getUserPw()
{
	return userPw;
}

void Users::firstMenu()
{
	int select;

	while (true) {
		string s_select;
		system("cls");
		cout << "[로그인 선택 메뉴]\n";
		cout << "1. 로그인\n2. 회원가입\n3. 종료\n> ";
		cin >> s_select;

		
		if (s_select.compare("1") == 0 || s_select.compare("2") == 0 || s_select.compare("3") == 0 || s_select.compare("4") == 0) {
			
			select = stoi(s_select);
			
			
			break;
		}
		else {
			system("cls");
			cout << ("[로그인 선택 메뉴]\n");
			cout << ("올바른 입력형식이 아닙니다.\n");
			////sleep(1500);
		}
	}

	switch (select) {
	case 1:

		signIn();
		
		break;
	case 2:
		signUp();
		break;
	case 3:
		system("cls");
		cout << ("[종료]\n안녕히가세요.\n");
		exit(0);
		break;
	case 4:
		system("cls");
		map<string, string> map;
		map = getUserList();
		for (const auto& p : map) {
			cout << "id: " << p.first << " / pw: " << p.second << "\n";
		}
		cout << "============================\n";
		map = getUserIdName();
		for (const auto& p : map) {
			cout << "id: " << p.first << " / name: " << p.second << "\n";
		}
	}
}


void Users::signIn()
{
	int flag = 0;
	string id;
	string pw;
	string name;
	wstring wid;
	wstring wpw;
	wstring wname;

	cout << "fuck" << endl;

	std::locale::global(std::locale("C")); // 맨 처음 한번 실행

	std::locale loc("C");

	cout << "fuck" << endl;
	while (flag != 1) {

		wid = getwInput(L"로그인", L"ID", 2, 10);
		if (wid.compare(L"q") == 0) {
			flag = -1;
			break;
		}
		id = convertWstring(wid, loc);

		wpw = getwInput(L"로그인", L"비밀번호", 2, 15);
		if (wpw.compare(L"q") == 0) {
			flag = -1;
			break;
		}
		pw = convertWstring(wpw, loc);


		if (isFine(id, pw)) {
			flag = 1;
			map<string, string> map = getUserIdName();
			auto it = map.find(id);
			name = it->second;
		}
		else {
			cout << "로그인에 실패하였습니다.\n";
			////sleep(1500);
		}
	}

	if (flag == -1) {
		firstMenu();
	}

	else if (flag == 1) {
		cout << "로그인 성공!";
		setUserId(id);
		setUserName(name);

		//캘린더 선택 메뉴로 이동
	}

}

void Users::signUp()
{
	int flag = 0;
	string id;
	string pw;
	string name;
	wstring wid;
	wstring wpw;
	wstring wname;
	locale loc("C");

	while (flag != 1) {
		wid = getwInput(L"회원가입", L"ID", 2, 10);
		if (wid.compare(L"q") == 0) {
			flag = -1;
			break;
		}
		id = convertWstring(wid, loc);

		if (isOverlap(id)) {
			wpw = getwInput(L"회원가입", L"비밀번호", 2, 15);
			if (wpw.compare(L"q") == 0) {
				flag = -1;
				break;
			}
			pw = convertWstring(wpw, loc);

			wname = getwInput(L"회원가입", L"이름", 2, 10);
			if (wpw.compare(L"q") == 0) {
				flag = -1;
				break;
			}
			name = convertWstring(wname, loc);

			flag = 1;
		}
		else {
			cout << "이미 있는 ID입니다.\n";
			////sleep(1500);
		}
	}

	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		writeUserList(id, pw, name);
		cout << "회원가입 성공!";
		setUserId(id);
		setUserName(name);
		//캘린더 선택 메뉴로 이동
	}
}

bool Users::isOverlap(string id)
{
	map<string, string> map = getUserList();
	auto it = map.find(id);

	if (it != map.end()) {
		return false;
	}
	else {
		return true;
	}
}

bool Users::isFine(string id, string pw)
{
	map<string, string> map = getUserList();
	auto it = map.find(id);

	if (it != map.end()) {

		if (it->first == id && it->second == pw) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

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
			separatorIndex = 0;
			for (i = 0; i < sizeof(read); i++)
			{
				if (str[i] == '$') {
					separatorIndex++;
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
	else perror("[UserList.txt] error\n");

	read.close();

	return userInfo;
}

map<string, string> Users::getUserIdName() {
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
			string name = "";
			separatorIndex = 0;
			for (i = 0; i < sizeof(read); i++)
			{
				if (str[i] == '$') {
					separatorIndex++;
				}
				else {
					if (separatorIndex == 0) id += str[i];
					else if (separatorIndex == 2) name += str[i];
				}
			}
			userInfo.insert(make_pair(id, name));
		}
	}
	else perror("[UserList.txt] error\n");

	read.close();

	return userInfo;
}

void Users::writeUserList(string id, string pw, string name)
{
	write.open("data/UserList.txt", ios::app);
	write << id + separator + pw + separator + name << endl;
	write.close();
	cout << "id: " << id << " / pw: " << pw << " / name: " << name << " 저장 성공!\n";
}

bool Users::wencodingCheck(const wstring& s)
{
	wstring e;

	for (int i = (int)L'a'; i <= (int)L'z'; ++i) {
		e += (wchar_t)i;
	}

	for (int i = (int)L'A'; i <= (int)L'Z'; ++i) {
		e += (wchar_t)i;
	}

	for (int i = (int)L'가'; i <= (int)L'힣'; ++i) {
		e += (wchar_t)i;
	}

	for (int i = (int)L'0'; i <= (int)L'9'; ++i) {
		e += (wchar_t)i;
	}

	for (wchar_t u : s)
		if (e.find(u) == wstring::npos)
			return false;

	return true;
}


wstring Users::getwInput(wstring menuname, wstring purpose, int start, int end)
{
	wcin.imbue(locale("C"));
	wcout.imbue(locale("C"));
	wstring wstr;
	while (true) {
		system("cls");
		wcout << L"[" + (menuname) + L"]\n";
		wcout << purpose + L"> ";
		wcin >> wstr;
		if (wstr.compare(L"q") == 0) {
			break;
		}

		if (wencodingCheck(wstr)) {
			if (wstr.length() >= start && wstr.length() <= end) {
				break;
			}
			else {
				wcout << L"올바른 입력형식이 아닙니다.\n";
				////sleep(1500);
			}
		}
		else {
			wcout << L"올바른 입력형식이 아닙니다.\n";
			////sleep(1500);
		}
	}

	return wstr;
}

// wstring -> string 
// locale loc("KOR") 선언하고 사용
string Users::convertWstring(wstring const& wstr, locale const& loc)
{
	typedef codecvt<wchar_t, char, mbstate_t> codecvt_t;
	codecvt<wchar_t, char, mbstate_t> const& codecvt = use_facet<codecvt_t>(loc);
	mbstate_t state = mbstate_t();
	vector<char> buff((wstr.size() + 1) * codecvt.max_length());
	wchar_t const* in_next = wstr.c_str();
	char* out_next = &buff[0];
	codecvt_t::result r = codecvt.out(state, wstr.c_str(), wstr.c_str() + wstr.size(), in_next, &buff[0], &buff[0] + buff.size(), out_next);

	return string(&buff[0]);
}

// ex) isDirExist(L"data")
void Users::isDirExist(const char* dirpath)
{
   int nResult = access(dirpath, 0);
   if (nResult != 0) {
      mkdir("data");
   }
}

// ex) isFileExist("data/UserList.txt")
void Users::isFileExist(const char* filepath)
{
	if (_access(filepath, 0) != 0) {
		FILE* f;
		if (fopen(filepath, "w") != 0) {
			cout << filepath << (" 읽기 또는 생성 오류\n");
		}
		else {
			if (fclose(f) != 0) {
				cout << filepath << (" 닫기 오류\n");
			}
		}
	}
}
