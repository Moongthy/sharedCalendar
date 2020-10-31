Users::Users(string userName, string userId)
	: User(userId, userName)
{
}

string Users::getUserPw()
{
	return userPw;
}

void Users::setUserPw(string pw)
{
	this->userPw = pw;
}

void Users::firstMenu()
{
	isDirExist("../data");
	isFileExist("../data/UserList.txt");
	int select;

	while (true) {
		string s_select;
		system("cls");
		cout << loginMenu[0];
		cout << loginMenu[1];

		getline(cin,s_select);
		
		if (s_select.compare("1") == 0 || s_select.compare("2") == 0 || s_select.compare("3") == 0 || s_select.compare("4") == 0) {
			select = stoi(s_select);
			break;
		}
		else {
			system("cls");
			cout << loginMenu[0];
			cout << err[0];
			cin.ignore();
		}
	}

	switch (select) {
	case 1:
		system("cls");
		signIn();
		break;
	case 2:
		system("cls");
		signUp();
		break;
	case 3:
		system("cls");
		cout << loginMenu[2];
		exit(0);
		break;
	}
}

void Users::signIn(){
	ReadFile rf = ReadFile();
	vector<User> userList = rf.getUserIdName();
	
	int flag = 0;
	string id;
	string pw;
	string name;

	while (flag!=1) {
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
			name = getUserNameList(id);
			flag = 1;
		}
		else {
			cout << err[1];
			cin.ignore();
			flag=-1;
			break;
		}
	}
	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		cout << loginMenu[3];

		setUserId(id);

		setUserName(name);

		string a = name, b = id;

   		User user = User(a, b);	
		cout << "call scm Contructor in Users.hpp" << endl;
    	SharedCalendarManager<Schedule, User, Date> scm = SharedCalendarManager<Schedule, User, Date>();
		scm.loadSharedCalendarList();
		// for(SharedCalendar<Schedule, User, Date> sc : scm.getSharedCalendarList())
		// {
		// 	cout << "load schedule List in user.hpp"<< endl;
		// 	sc.loadSharedScheduleList();
		// }
    	MenuInput mi = MenuInput(user, scm);

    	mi.mainMenu();
		//move to Calender Select Menu
	}
}

void Users::signUp(){
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
			if (name.compare("q") == 0) {
				flag = -1;
				break;
			}

			flag = 1;
		}
		else {
			cout << err[2];
			// cin.ignore();
		}
	}

	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		ReadFile rf = ReadFile();
		
		rf.writeUserList(id, pw, name);
		
		cout << loginMenu[4];

		setUserId(id);
		
		setUserName(name);

		string a = name, b = id;

   		User user = User(a, b);
    
    	SharedCalendarManager<Schedule, User, Date> scm = SharedCalendarManager<Schedule, User, Date>();

    	MenuInput mi = MenuInput(user, scm);

    	mi.mainMenu();

		//move to Calender Select Menu
	}
}

bool Users::isOverlap(string id)
{
	ReadFile rf = ReadFile();
	vector<string> idList = rf.getUserIDList();
	if(find(idList.begin(),idList.end(),id) != idList.end()){
		//id already exist
		return false;
	}else{
		//id does not exist
		return true;
	}
}

bool Users::isFine(string id, string pw)
{
	ReadFile rf = ReadFile();
	if(pw == rf.getUserpassword(id)){
		//id pw match
		return true;
	}else{
		//id pw not match
		return false;
	}
}

string Users::getUserNameList(string userID){
	ifstream is;
	int separatorIndex;
    string separator = "$";
	
	is.open("../data/UserList.txt");
    char str[sizeof(is)]={'\0'};
    int i = 0;
    string id, name;
    map<string,string> map;
	string retVal;

    if(is.good())
    {
        while(!is.eof())
        {
            is.getline(str, sizeof(is));
            if(is.eof()) break;

            id = "", name = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(is); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==0) id += str[i];
                else if(separatorIndex==2) name += str[i];
                 else if(str[i]=='\0') break;
            }
			map.insert(make_pair(id,name));
        }
    }
    else cout << "[UserList.txt] read error!" << endl;

	auto it = map.find(userID);

	if(it!=map.end()){
		retVal = it->second;
	}
	else{
		cout<< "Failed to find name\n";
	}

    is.close();

    return retVal;   
}

string Users::getInput(string menuname, string purpose, int start, int end){
	check ck=check();
	string str;
	cout << menuname;
	while (true) {
		system("cls");
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
				// cin.ignore();
			}
		}
		else {
			cout << err[0];
			// cin.ignore();
		}
	}
	return str;
}

// ex) isDirExist("data")
void Users::isDirExist(const char* dirpath)
{
   int nResult = access(dirpath, 0);
   if (nResult != 0) {
       mkdir(dirpath);
   }
}

// ex) isFileExist("data/UserList.txt")
void Users::isFileExist(const char* filepath)
{
	if (_access(filepath, 0) != 0) {
		FILE* f;
		if (fopen(filepath, "w") != 0) {
			cout << "[" << filepath << ("] read/create error!\n"); 
			cin.ignore();
		}
		else {
			if (fclose(f) != 0) {
				cout << "[" << filepath << ("] close error!\n"); 
				cin.ignore();
			}
		}
	}
}
