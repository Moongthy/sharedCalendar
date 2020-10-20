#include"../header/Calendar.h"
#include"../header/SharedCalendar.h"
#include"../header/SharedCalendarManager.h"

#include"../header/type/Schedule.h"
#include"../header/type/User.h"
#include"../header/type/Date.h"

#include<iostream>

using namespace std;

#define C               Calendar<Schedule, User, Date>
#define SC              SharedCalendar<Schedule, User, Date>
#define SCManager       SharedCalendarManager<Schedule, User, Date>


string userNameList[6] = {
    "cho mun geun",
    "song yong soo",
    "lee z u",
    "shin ye seul",
    "kim byeong chan",
    "jeong byung geun"
};  

vector<User> userList;
void userTest(){
    for(int i = 0; i < 6; ++i)
        userList.push_back(User(userNameList[i], i));

    for(User u : userList)
        cout << "userName : " << u.getUserName() << " userId : " << u.getUserId() << "\n";
    cout << endl;
}

SCManager scm;
void sharedCalendarTest(){
    for(int i = 0; i < 6; ++i){
        scm.addSharedCalendar(userList[i], userList[i].getUserName(), 10, {1,2,3}, {1,2,3});
    }
    scm.showSharedCalendarList();
}

int main(){
    userTest();
    sharedCalendarTest();
    return 0;
}