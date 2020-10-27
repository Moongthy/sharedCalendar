User::User(string userName, string userId)
	: userName(userName), userId(userId)
{
	
}

string User::getUserId()
{
	return userId;
}

string User::getUserPw()
{
	return userPw;
}

string User::getUserName()
{
	return userName;
}

void User::setUserId(string id)
{
	userId = id;
}

void User::setUserPw(string pw)
{
	userPw = pw;
}

void User::setUserName(string name)
{
	userName = name;
}

void User::firstMenu()
{
	isDirExist("../data");
	isFileExist("../data/UserList.txt");
	int select;

	while (true) {
		string s_select;
		system("cls");
		cout << loginMenu[0];
		cout << loginMenu[1];
		cin >> s_select;

		if (s_select.compare("1") == 0 || s_select.compare("2") == 0 || s_select.compare("3") == 0 || s_select.compare("4") == 0) {
			select = stoi(s_select);
			break;
		}
		else {
			system("cls");
			cout << loginMenu[0];
			cout << err[0];
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
		cout << loginMenu[2];
		exit(0);
		break;
	case 4:
		system("cls");
		map<string, string> mapA;
		map<string, string> mapB;
		mapA = getUserInfo(0);
		for (const auto& p : mapA) {
			cout << "id: " << p.first << " / pw: " << p.second << "\n";
		}
		cout << "============================\n";
		mapB = getUserInfo(1);
		for (const auto& p : mapB) {
			cout << "id: " << p.first << " / name: " << p.second << "\n";
		}
	}
}

void User::signIn(){
	int flag = 0;
	string id;
	string pw;
	string name;

	while (flag != 1) {

		id = getInput(loginMenu[5], loginMenu[7], 2, 10);
		if (id.compare("q") == 0) {
			flag = -1;
			break;
		}

		pw = getInput(loginMenu[5], loginMenu[8], 2, 15);
		if (pw.compare("q") == 0) {
			flag = -1;
			break;
		}

		if (isFine(id, pw)) {
			flag = 1;
			map<string, string> map = getUserInfo(1);
			auto it = map.find(id);
			name = it->second;
		}
		else {
			cout << loginMenu[3];
		}
	}

	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		cout << loginMenu[3];
		setUserId(id);
		setUserName(name);

		//캘린더 선택 메뉴로 이동
	}
}

void User::signUp(){
	int flag = 0;
	string id;
	string pw;
	string name;

	while (flag != 1) {
		id = getInput(loginMenu[6], loginMenu[7], 2, 10);
		
		if (id.compare("q") == 0) {
			flag = -1;
			break;
		}

		if (isOverlap(id)) {
			pw = getInput(loginMenu[6], loginMenu[8], 2, 15);
			if (pw.compare("q") == 0) {
				flag = -1;
				break;
			}

			name = getInput(loginMenu[6], loginMenu[9], 2, 10);
			if (pw.compare("q") == 0) {
				flag = -1;
				break;
			}

			flag = 1;
		}
		else {
			cout << err[2];
			//sleep(1500);
		}
	}

	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		writeUserList(id, pw, name);
		cout << loginMenu[4];
		setUserId(id);
		setUserName(name);
		//캘린더 선택 메뉴로 이동
	}
}

bool User::isOverlap(string id)
{
	map<string, string> map = getUserInfo(0);
	auto it = map.find(id);

	if (it != map.end()) {
		return false;
	}
	else {
		return true;
	}
}

bool User::isFine(string id, string pw)
{
	map<string, string> map = getUserInfo(0);
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


// 인자가 0이면 id, pw / 1이면  id, name 반환
map<string,string> User::getUserInfo(int flag){
read.open("../data/UserList.txt");
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
			string info = "";
			separatorIndex = 0;
			if (flag==0){
				for (i = 0; i < sizeof(read); i++)
				{
					if(flag==0){

						if (str[i] == '$') {
							separatorIndex++;
						}
						else {
							if (separatorIndex == 0) id += str[i];
							else if (separatorIndex == 1) info += str[i];
							else if (separatorIndex == 2) break;
						}
					}
					else if(flag==1){
						if (str[i] == '$') {
							separatorIndex++;
						}
						else {
							if (separatorIndex == 0) id += str[i];
						else if (separatorIndex == 2) info += str[i];
							}
					}
				}
				userInfo.insert(make_pair(id, info));
			}
			
		}
	}
	else cout << "[UserList.txt] read error!" << endl;

	read.close();

	return userInfo;

}

void User::writeUserList(string id, string pw, string name)
{

	write.open("../data/UserList.txt", ios::app);
	write << id + separator + pw + separator + name << endl;
	write.close();
	cout << "id: " << id << " / pw: " << pw << " / name: " << name << " save success!\n";
}

bool User::grammerCheck(string& inputVal){
	string e;

	for (int i = (int)'a'; i <= (int)'z'; ++i) {
		e += (char)i;
	}

	for (int i = (int)'A'; i <= (int)'Z'; ++i) {
		e += (char)i;
	}

	for (int i = 44032; i <= 55203; ++i) {
		e += (char)i;
	}

	for (int i = (int)'0'; i <= (int)'9'; ++i) {
		e += (char)i;
	}

	for (char u : inputVal)
		if (e.find(u) == string::npos)
			return false;

	return true;
} 

string User::getInput(string menuname, string purpose, int start, int end){
	check ck=check();
	string str;
	while (true) {
		system("cls");
		cout << menuname;
		cout << purpose;
		getline(cin,str);
		if (str.compare("q") == 0) {
			break;
		}

		if (ck.encodingCheck(str)) {
			if (str.length() >= start && str.length() <= end) {
				break;
			}
			else {
				cout << err[0];
			}
		}
		else {
			cout << err[0];
			
		}
	}
	return str;
}

// ex) isDirExist("data")
void User::isDirExist(const char* dirpath)
{
   int nResult = access(dirpath, 0);
   if (nResult != 0) {
       mkdir(dirpath);
   }
}

// ex) isFileExist("data/UserList.txt")
void User::isFileExist(const char* filepath)
{
	if (_access(filepath, 0) != 0) {
		FILE* f;
		if (fopen(filepath, "w") != 0) {
			cout << "[" << filepath << ("] read/create error!\n"); 
		}
		else {
			if (fclose(f) != 0) {
				cout << "[" << filepath << ("] close error!\n"); 
			}
		}
	}
}

