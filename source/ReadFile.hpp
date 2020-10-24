#include "../header/ReadFile.h"

using namespace std;


vector<string> ReadFile::getUserIDList() 
{
    read.open("../data/UserList.txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    vector<string> userId;

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            string id = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==0) id += str[i];
                else if(separatorIndex==1) break;
            }
            userId.push_back(id);
        }
        
    }
    else cout << "[UserList.txt] read error!" << endl;
    
    read.close();

    return userId;
}


string ReadFile::getUserpassword(string userID)
{
    read.open("../data/UserList.txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    string id, password;
    vector<string> SCTitle;

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            id = "", password = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==0) id += str[i];
                else if(separatorIndex==1) password += str[i];
                else if(separatorIndex==2) break;
            }
            if(userID == id) break;
        }
        
    }
    else cout << "[UserList.txt] read error!" << endl;
    
    read.close();

    return password;   
}



void ReadFile::writeUserList(string id, string password, string name) {
    write.open("../data/UserList.txt", ios::app);
    write << id + separator + password + separator + name << endl;
    write.close();
}

void ReadFile::writeSCList(string title, string password, string startday, string endday, string admin) {
    read.open("../data/SharedCalendarList.txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    string preID;

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            preID = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==0) preID += str[i];
                else if(separatorIndex==1) break;
            }
        }
        
    }
    else cout << "[UserList.txt] read error!" << endl;
    
    read.close();

    if(preID == "") preID = "0";
    int id = stoi(preID)+1;
    // 처음 SharedCalendar 등록할 때는 admin이 제일 첫번째에 들어가서 admin만 넣음.
    write.open("../data/SharedCalendarList.txt", ios::app);
    write << id;
    write << separator + title + separator + password + separator
                + startday + separator + endday + separator + admin << endl;
    write.close();
}


vector<string> ReadFile::getSCTitleList() {
    read.open("../data/SharedCalendarList.txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    vector<string> SCTitle;

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;
            
            string title = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==1) title += str[i];
                else if(separatorIndex==2) break;
            }
            SCTitle.push_back(title);
        }
        
    }
    else cout << "[SharedCalendarList.txt] read error!" << endl;
    
    read.close();

    return SCTitle;
}


string ReadFile::getSCPassword(string inputTitle) {
    read.open("../data/SharedCalendarList.txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    string title, password;
    vector<string> SCTitle;

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            title = "", password = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==1) title += str[i];
                else if(separatorIndex==2) password += str[i];
                else if(separatorIndex==3) break;
            }
            if(inputTitle == title) break;
        }
        
    }
    else cout << "[SharedCalendarList.txt] read error!" << endl;
    
    read.close();

    return password;
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


void ReadFile::writeSchedule(string userID, string name, string date, string starttime, string endtime, string loc, string memo) {
    read.open("../data/Calendar/"+userID+".txt");
    char str[sizeof(read)]={'\0'};
    int i = 0;
    string preID;

    if(read.good())
    {
        while(!read.eof())
        {
            read.getline(str, sizeof(read));
            if(read.eof()) break;

            preID = "";
            separatorIndex = 0;
            for(i=0; i<sizeof(read); i++)
            {
                if(str[i]=='$') separatorIndex++;
                else if(separatorIndex==0) preID += str[i];
                else if(separatorIndex==1) break;
            }
        }
        
    }
    else cout << "read error!" << endl;
    
    read.close();

    if(preID == "") preID = "0";
    int id = stoi(preID)+1;
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