#include"../header/Calendar.h"
#include"../header/SharedCalendar.h"
#include"../header/SharedCalendarManager.h"

#include"../header/type/Schedule.h"
#include"../header/type/User.h"
#include"../header/type/Date.h"

#include<iostream>

#include"../header/input/Input.h"
#include"../header/strings.h"
using namespace std;

#define C               Calendar<Schedule, User, Date>
#define SC              SharedCalendar<Schedule, User, Date>
#define SCManager       SharedCalendarManager<Schedule, User, Date>

#define rep(n) for(int i = 0; i < n; ++i) 

void stage_1();
void stage_2();
void createSC(vector<string>& scInfo, int stage);
void stage_4();
void stage_5();
void stage_6();



void stage_1(){
    rep(5) cout << choiceCalendarMenu[i];
    
    Input input;
    string c = input.input();

    if(!input.simpleCheck("123q",c)){
        cout << err[0] << endl;
        stage_1();
        return;
    }

    if(c == "q"){
        cout << err[1] << endl;
        return;
    }

    if(c == "1"){
        cout << err[2] << endl;
        return;
    }

    if(c == "2"){
        stage_2();
        return;
    }

    if(c == "3"){
        cout << "종료" << endl;
        exit(0);
    }
}

void stage_2(){
    rep(5) cout << choiceSharedCalendarAction[i];
    
    vector<string> scInfo;
    Input input;
    string c = input.input();

    if(!input.simpleCheck("123q",c)){
        cout << err[0] << endl;
        stage_2();
        return;
    }

    if(c == "q"){
        stage_1();
        return;
    }

    if(c == "1"){
        createSC(scInfo, 1);
        stage_2();
        return;
    }

    if(c == "2"){
        cout << err[3] << endl;
        return;
    }

    if(c == "3"){
        cout << err[4] << endl;
        exit(0);
    }
}

void createSC(vector<string>& scInfo, int stage){
    cout << inputCreateSharedCalendar[0];
    cout << inputCreateSharedCalendar[stage];

    if(stage == 5) return;

    Input input;
    string c = input.input();

    // 공캘 이름 체크
    if(stage == 1){
        int check = input.checkSharedCalendarName(c);

        if(check == 2){
            createSC(scInfo, stage-1);
            return;
        }

        if(check == 0 || check == -1){
            cout << err[0] << endl;
            createSC(scInfo, stage);
            return;
        }
    }

    // 공캘 비번 체크
    if(stage == 2){
        int check = input.checkSharedCalendarPassWord(c);

        if(check == 2){
            createSC(scInfo, stage-1);
            return;
        }

        if(check == 0 || check == -1){
            cout << err[0] << endl;
            createSC(scInfo, stage);
            return;
        }
    }

    // 공캘 수용인원 체크
    if(stage == 3){
        int check = input.checkSharedCalenderAcceptable(c);

        if(check == 2){
            createSC(scInfo, stage-1);
            return;
        }

        if(check == 0 || check == -1){
            cout << err[0] << endl;
            createSC(scInfo, stage);
            return;
        }
    }

    // 공캘 날짜 체크
    if(stage == 4){
        int check = input.checkSharedCalenderAcceptable(c);

        if(check == 2){
            createSC(scInfo, stage-1);
            return;
        }

        if(check == 0 || check == -1){
            cout << err[0] << endl;
            createSC(scInfo, stage);
            return;
        }
    }

    scInfo.push_back(c);
    createSC(scInfo, stage+1);
}


int main(){
    stage_1();

    cout << ("q" == "q") << endl;
    return 0;
}