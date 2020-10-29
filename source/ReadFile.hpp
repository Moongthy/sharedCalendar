#include "../header/ReadFile.h"

using namespace std;

void ReadFile::isFileExist(string filepath)
{
	if (_access(filepath.c_str(), 0) != 0) {
		FILE* f;
		if (fopen(filepath.c_str(), "w") != 0) {
			cout << "[" << filepath << ("] read/create error!\n");
			//cin.ignore(); 
		}
		else {
			if (fclose(f) != 0) {
				cout << "[" << filepath << ("] close error!\n"); 
				//cin.ignore();
			}
		}
	}
}

vector<string> ReadFile::readUserList(int index) 
{
    read.open("../data/UserList.txt");
    int i = 0;
    string temp;
    vector<string> return_list;
    
    if(read.good())
    {
        while(!read.eof())
        {
            char str[sizeof(read)]={'\0'};
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            separatorIndex = 0;
            temp = "";
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]==separator) separatorIndex++;
                else if(separatorIndex==index) temp += str[i];
                else if(str[i]=='\0') break;
            }
            return_list.push_back(temp);
        }
    }
    else cout << "[UserList.txt] read error!" << endl;
    
    read.close();

    return return_list;    
}

vector<User> ReadFile::getUserIdName() 
{
    vector<User> return_list;
    vector<string> id_list = readUserList(0); 
    vector<string> name_list = readUserList(2);

    int i = 0;
    for(i=0; i<id_list.size(); i++)
    {
        return_list.push_back(User(id_list[i], name_list[i]));
    }

    return return_list; 
}

vector<string> ReadFile::getUserIDList() 
{
    vector<string> return_list;
    vector<string> id_list = readUserList(0);

    int i = 0;
    for(i=0; i<id_list.size(); i++)
    {
        return_list.push_back(id_list[i]);
    }

    return return_list; 
}

string ReadFile::getUserpassword(string userID)
{
    vector<string> id_list = readUserList(0);
    vector<string> pwd_list = readUserList(1);

    int i = 0;
    string return_pwd;
    for(i=0; i<id_list.size(); i++)
    {
        if(id_list[i]==userID) 
        {
            return_pwd = pwd_list[i];
            cout << return_pwd;
            break;
        }
    }

    return return_pwd; 
}

void ReadFile::writeUserList(string id, string password, string name) {
    write.open("../data/UserList.txt", ios::app);
    write << id + separator + password + separator + name << endl;
    write.close();
}

vector<string> ReadFile::readSCList(int index) 
{
    read.open("../data/SharedCalendarList.txt");
    int i = 0;
    string temp;
    vector<string> return_list;
    
    if(read.good())
    {
        while(!read.eof())
        {
            char str[sizeof(read)]={'\0'};
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            separatorIndex = 0;
            temp = "";
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]==separator) separatorIndex++;
                else if(separatorIndex==index) temp += str[i];
                else if(str[i]=='\0') break;
            }
            return_list.push_back(temp);
        }
    }
    else cout << "[SharedCalendarList.txt] read error!" << endl;
    
    read.close();

    return return_list;    
}

vector<string> ReadFile::getSCList() {
    read.open("../data/SharedCalendarList.txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    string SCdata;
    vector<string> SCAll;

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;
            
            SCdata = "";
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='\0') break;
                SCdata += str[i];
            }
            SCAll.push_back(SCdata);
        }
        
    }
    else cout << "[SharedCalendarList.txt] read error!" << endl;
    
    read.close();

    return SCAll;
}


void ReadFile::clearSCList() {
    write.open("../data/SharedCalendarList.txt", ios::out);
    write.close();
}


void ReadFile::writeSCList(string title, string password, string startday, string endday, string admin) {
    vector<string> id_list = readSCList(0);

    int id = stoi(id_list[id_list.size()-1])+1;
    
    // 처음 SharedCalendar 등록할 때는 admin이 제일 첫번째에 들어가서 admin만 넣음.
    write.open("../data/SharedCalendarList.txt", ios::app);
    write << id;
    write << separator + title + separator + password + separator
                + startday + separator + endday + separator + admin << endl;
    write.close();
}


vector<string> ReadFile::getSCTitleList() 
{
    vector<string> return_list;
    vector<string> title_list = readUserList(1);

    int i = 0;
    for(i=0; i<title_list.size(); i++)
    {
        return_list.push_back(title_list[i]);
    }

    return return_list; 
}


string ReadFile::getSCPassword(string inputTitle) {
    vector<string> title_list = readUserList(0);
    vector<string> pwd_list = readUserList(1);

    int i = 0;
    string return_pwd;
    for(i=0; i<title_list.size(); i++)
    {
        if(title_list[i]==inputTitle) 
        {
            return_pwd = pwd_list[i];
            break;
        }
    }

    return return_pwd;
}


void ReadFile::writeSCMember(string title, string member) {
    read.open("../data/SharedCalendarList.txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    string checkTitle, temp;
    string saveAll = "";

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;
            
            checkTitle = "";
            temp = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==1) checkTitle += str[i];
                else if(str[i]=='\0') break;
                temp += str[i];
                
            }
            if(checkTitle == title)
            {
                temp += separator;
                for(int j=0; j<member.length(); j++)
                {
                    temp += member[j]; 
                }
            }
            saveAll += (temp+"\n");
        }
    }
    read.close();

    write.open("../data/SharedCalendarList.txt");
    write << saveAll;
    write.close();
}


vector<string> ReadFile::readSCCalendar(string calID, int index)
{
    read.open("../data/SharedCalendar/"+calID+".txt");
    int i = 0;
    string temp;
    vector<string> return_list;
    
    if(read.good())
    {
        while(!read.eof())
        {
            char str[sizeof(read)]={'\0'};
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            separatorIndex = 0;
            temp = "";
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]==separator) separatorIndex++;
                else if(separatorIndex==index) temp += str[i];
                else if(str[i]=='\0') break;
            }
            return_list.push_back(temp);
        }
    }
    else cout << "[" << calID << ".txt] read error!" << endl;
    
    read.close();

    return return_list;    
}


void ReadFile::writeSCSchedule(string calID, string id, string name, string date, string starttime, string endtime, string loc, string memo) 
{
    // vector<string> id_list = readSCCalendar(calID, 0);
    // int id = 1;

    // if(id_list.size()!=0) id = stoi(id_list[id_list.size()-1])+1;

    write.open("../data/SharedCalendar/"+calID+".txt", ios::app);
    write << id;
    write << separator + name + separator + date + separator + starttime + separator 
                        + endtime + separator + loc + separator + memo << endl;
    write.close(); 
}

vector<string> ReadFile::readCalendar(string userID, int index)
{
    read.open("../data/Calendar/"+userID+".txt");
    int i = 0;
    string temp;
    vector<string> return_list;
    
    if(read.good())
    {
        while(!read.eof())
        {
            char str[sizeof(read)]={'\0'};
            read.getline(str, sizeof(read));
            
            separatorIndex = 0;
            temp = "";
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]==separator) separatorIndex++;
                else if(separatorIndex==index) temp += str[i];
                else if(str[i]=='\0') break;
            }
            return_list.push_back(temp);
            if(read.eof()) break;
        }
    }
    else cout << "[" << userID << ".txt] read error!" << endl;
    
    read.close();

    return return_list;    
}


void ReadFile::writeSchedule(string userID, string id, string name, string date, string starttime, string endtime, string loc, string memo) 
{
    // 없는 파일에다가 쓰려하면 강제종료됨..?

    // 없는 파일이면 생성하는 코드가 필요할듯.

    // ReadFile re;
    // vector<string> id_list = re.readCalendar(userID, 0);
    // int id = 1;

    // if(id_list.size()!=0) id = stoi(id_list[id_list.size()-1])+1;

    write.open("../data/Calendar/"+userID+".txt", ios::app);
    write << id;
    write << separator + name + separator + date + separator + starttime + separator 
                        + endtime + separator + loc + separator + memo << endl;
    write.close(); 
}

void ReadFile::editSchedule(string userID, string scheID, int index, string text) {
    read.open("../data/Calendar/"+userID+".txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    int is_edit = 0;
    string temp, id;
    string saveAll = "";

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            id = "";
            temp = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==0) id += str[i]; 
                else if(str[i]=='\0') break;
                
                if(str[i]=='$') temp += str[i];
                else if(id==scheID && separatorIndex==index) {
                    if(is_edit==0) {
                        for(int j=0; j<text.length(); j++) 
                        {
                            temp += text[j];
                        }
                    }
                    is_edit = 1;
                } 
                else temp += str[i];        
            }
            saveAll += (temp+"\n");
        }
    }
    read.close();

    write.open("../data/Calendar/"+userID+".txt");
    write << saveAll;
    write.close();
}


void ReadFile::deleteSchedule(string userID, string scheID) {
    read.open("../data/Calendar/"+userID+".txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    string temp, id;
    string saveAll = "";

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            id = "";
            temp = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==0) id += str[i]; 
                else if(str[i]=='\0') break;

                temp += str[i];     
            }
            if(id!=scheID) saveAll += (temp+"\n");
        }
    }
    read.close();

    write.open("../data/Calendar/"+userID+".txt");
    write << saveAll;
    write.close();
}