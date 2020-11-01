Users::Users(string userName, string userId)
	: User(userId, userName)
{
	// cout<<"Users Constructor"<<endl;
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
	// cout<<"Check if  \"../data\", \"../dataUserList.txt\"  exist... if they don't, create."<<endl;

	isDirExist("../data");
	isFileExist("../data/UserList.txt");
	int select;
	
	select=mainmenuInput(loginMenu[0],loginMenu[1]);

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
	// cout<<"//Users::signIn()//  call \"ReadFile\" Constructor in Users.hpp"<<endl;
	// cout<<"call ReadFile::getUserIdName() in Users.hpp"<<endl;

	ReadFile rf = ReadFile();
	vector<User> userList = rf.getUserIdName();
	
	int flag = 0;
	string id;
	string pw;
	string name;

	while (flag!=1) {
		// cout<<loginMenu[5]<< endl;
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

		// cout<<"call ReadFile::isFine() in Users.hpp  <-- To check a login-verification"<<endl;

		if (isFine(id, pw)) {
			// cout<<"//Users::signIn()//  call Users::getUserNameList() in Users.hpp  <-- Load NAME of account from \"UserList.txt\""<<endl;

			name = getUserNameList(id);
			flag = 1;
		}
		else {
			cout << err[1];
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

		// cout<< "UserName: "<<getUserName()<<" / UserID: "<<getUserId()<<endl;
		// cout << "call scm Contructor in Users.hpp" << endl;
		
		SharedCalendarManager<Schedule, User, Date> scm = SharedCalendarManager<Schedule, User, Date>();
		
		scm.loadSharedCalendarList();
		
		// for(SharedCalendar<Schedule, User, Date> sc : scm.getSharedCalendarList())
		// {
		// 	cout << "load schedule List in Users.hpp"<< endl;
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
		}
	}

	if (flag == -1) {
		firstMenu();
	}
	else if (flag == 1) {
		// cout<<"//In Users::signUp()//  call \"ReadFile\" Constructor in Users.hpp"<<endl;
		// cout<<"call ReadFile::writeUserList() in Users.hpp  <-- Save new ID, PW, NAME in \"UserList.txt\""<<endl;
		ReadFile rf = ReadFile();
		rf.writeUserList(id, pw, name);
		
		cout << loginMenu[4];

		setUserId(id);
		
		setUserName(name);

		string a = name, b = id;

   		User user = User(a, b);

		// cout<< "UserName: "<<getUserName()<<" / UserID: "<<getUserId()<<endl;
		// cout << "call scm Contructor in Users.hpp" << endl;
    	
		SharedCalendarManager<Schedule, User, Date> scm = SharedCalendarManager<Schedule, User, Date>();

    	MenuInput mi = MenuInput(user, scm);

    	mi.mainMenu();

		//move to Calender Select Menu
	}
}

bool Users::isOverlap(string id)
{
	// cout<<"//Users::isOverlap()//  call \"ReadFile\" Constructor in Users.hpp"<<endl;
	// cout<<"call ReadFile::getUserIDList() in Users.hpp"<<endl;
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
	// cout<<"//Users::isFine()//  call \"ReadFile\" Constructor in Users.hpp"<<endl;
	// cout<<"call ReadFile::getUserpassword() in Users.hpp  <-- To check if ID and PW match"<<endl;
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

int Users::mainmenuInput(string menuname,string purpose){
	int retVal;
	string str;
	
	while(true){
		cout<<menuname;
		cout<<purpose;
		getline(cin,str);
		
		if(str.compare("1")==0){
			break;
		}
		if(str.compare("2")==0){
			break;
		}
		if(str.compare("3")==0){
			break;
		}else{
			cout<<err[0];
		}
	}

	retVal = stoi(str);

	return retVal;
}

string Users::getInput(string menuname, string purpose, int start, int end){
	check ck;
	string str;
	if(purpose.compare(loginMenu[7])==0){
		cout << menuname;
	}
	while (true) {
		// system("cls");
		cout << purpose;
		getline(cin,str);
		if (str.compare("q") == 0) {
			break;
		}
		
		if (ck.encodingCheck(str)) {
			if (ck.stringSize(str) >= start && ck.stringSize(str) <= end) {
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
		}
		else {
			if (fclose(f) != 0) {
				cout << "[" << filepath << ("] close error!\n");
			}
		}
	}
}
