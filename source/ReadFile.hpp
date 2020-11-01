#include "../header/ReadFile.h"

using namespace std;

void ReadFile::isFileExist(string filepath)
{
   if (_access(filepath.c_str(), 0) != 0) {
      FILE* f = fopen(filepath.c_str(), "w");
        fclose(f);
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
        return_list.push_back(User(name_list[i], id_list[i]));
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
            // cout << return_pwd;
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
    int i = 0;
    string SCdata;
    vector<string> SCAll;

    if(read.good())
    {
        while(!read.eof())
        {
            char str[sizeof(read)]={'\0'};
            read.getline(str, sizeof(read));
            if(read.eof()) break;
            
            SCdata = "";
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='\0') break;
                SCdata += str[i];
            }
            cout << SCdata << endl;
            SCAll.push_back(SCdata);
        }
        
    }
    else cout << "[SharedCalendarList.txt] read error!" << endl;
    
    read.close();

    return SCAll;
}

void ReadFile::clearSCList() {
    // cout << "in clear SCList" << endl;
    write.open("../data/SharedCalendarList.txt", ios::out);
    write.close();
}

void ReadFile::clearSCScheList(string calId) {
    // cout << calId + "call clearSCScheduleList" << endl;
    isFileExist("../data/SharedCalendar/"+calId+".txt");
    write.open("../data/SharedCalendar/"+calId+".txt", ios::out);
    write.close();
}

void ReadFile::clearPCScheList(string userId) {
    // cout << userId + "call clearPCScheduleList" << endl;
    isFileExist("../data/Calendar/"+userId+".txt");
    write.open("../data/Calendar/"+userId+".txt", ios::out);
    write.close();
}


void ReadFile::writeSCList(string title, string password, string startday, string endday, string admin) {
    vector<string> id_list = readSCList(0);
    // cout << "readSCList(0) success" << endl;

    /*********************여기서 멈춤*************************/
    // cout << "idList size : " << id_list.size() << endl;
    // int tmp = id_list.size()-1;
    // cout << "int tmp : " + tmp << endl;
    // string t = id_list[tmp];
    // cout << "t : " << t << endl;
    // int id = stoi(t)+1;
    // cout << "stoi success" << endl;
    int id =1;
    if(id_list.size()!=0)
        id=stoi(id_list[id_list.size()-1])+1;
    
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
    int i = 0;
    string checkTitle, temp;
    string saveAll = "";

    if(read.good())
    {
        while(!read.eof())
        {
            char str[sizeof(read)]={'\0'};
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
    cout << "open the ../data/SharedCalendar/"+calID+".txt" << endl << endl;
    isFileExist("../data/SharedCalendar/"+calID+".txt");
    read.open("../data/SharedCalendar/"+calID+".txt");
    // cout << "open success" << endl;
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
            // cout << "temp : " << temp << endl;
            return_list.push_back(temp);
        }
    }
    else cout << "readSCCalendar [" << calID << ".txt] read error!" << endl;
    
    read.close();
    // cout << "in readSCCalednar success" << endl;
    return return_list;    
}
//개인캘린더에서 일정 읽는거
vector<string> ReadFile::readCalendar(string userID, int index)
{
    isFileExist("../data/Calendar/"+userID+".txt");
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
    else cout << "readCalendar [" << userID << ".txt] read error!" << endl;
    
    read.close();

    return return_list;    
}


void ReadFile::writeSCSchedule(string calID, string id, string name, string date, string starttime, string endtime, string loc, string memo) 
{
    isFileExist("../data/SharedCalendar/"+calID+".txt");
    write.open("../data/SharedCalendar/"+calID+".txt", ios::app);
    write << id;
    write << separator + name + separator + date + separator + starttime + separator 
                        + endtime + separator + loc + separator + memo << endl;
    write.close(); 
}

//개인캘린더에 쓰는것
void ReadFile::writeSchedule(string userID, string id, string name, string date, string starttime, string endtime, string loc, string memo) 
{
    isFileExist("../data/Calendar/"+userID+".txt");
    write.open("../data/Calendar/"+userID+".txt", ios::app);
    // cout << "writeSChedule" << endl;
    write << id;
    write << separator + name + separator + date + separator + starttime + separator 
                        + endtime + separator + loc + separator + memo << endl;
    write.close(); 
}

void ReadFile::editSchedule(string userID, string scheID, int index, string text) {
    isFileExist("../data/Calendar/"+userID+".txt");
    read.open("../data/Calendar/"+userID+".txt");
    int i = 0;
    int is_edit = 0;
    string temp, id;
    string saveAll = "";

    if(read.good())
    {
        while(!read.eof())
        {

            char str[sizeof(read)]={'\0'};
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
    isFileExist("../data/Calendar/"+userID+".txt");
    read.open("../data/Calendar/"+userID+".txt");
    int i = 0;
    string temp, id;
    string saveAll = "";

    if(read.good())
    {
        while(!read.eof())
        {

            char str[sizeof(read)]={'\0'};
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