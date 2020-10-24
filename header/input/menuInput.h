#pragma once

#ifndef __MENUINPUT__
#define __MENUINPUT__

#include"check.h"
#include"../SharedCalendarManager.h"
#include"../strings.h"
#include"../type/User.h"
#include"../type/Schedule.h"
#include"../type/Date.h"

#define _NORMAL 0
#define _SCNAME 1
#define _PW 2
#define _ACCEPTABLE 3
#define _DATE 4

#include<string>
using namespace std;

class MenuInput{
private:
    User user;
    SharedCalendarManager<Schedule, User, Date> scm;
public:

    MenuInput(User user, SharedCalendarManager<Schedule, User, Date> scm);

    void mainMenu();

    // 개인 캘린더 ? 공유 캘린더
    int whatCalendarDoYouWant();

    // 공캘에서 무엇을 할거니?
    int sharedCalendarActions();

    // 새로운 캘린더 정보를 입력받아 
    // 새로운 캘린더를 만든다.
    void createNewSc(vector<string>& scInfo, int stage);

    // 캘린더 이름과 비번을 입력받아
    // 캘린더에 참가한다.
    void joinSC(vector<string>& scInfo, int stage);

    // 캘린더 번호를 입력하여 
    // 캘린더에 들어간다.
    void intoSC();

    // 공유캘린더를 삭제한다.
    bool delSc();

    // 참가된 공유캘린더들의 이름을 출력한다.
    void showJoinedList();
};

#include"../../source/menuInput.hpp"
#endif