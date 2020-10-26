#pragma once
#include<string>

using std::string;

string err[10] = {
    "올바르지 않은 입력형식 입니다.\n",
    "로그인 실페\n",
};

string choiceCalendarMenu[10] = {
    "\n[캘린더 선택 메뉴]\n",
    "1. 개인 캘린더\n",
    "2. 공유 캘린더\n",
    "3. 종료\n",
    "> "
};

string choiceSharedCalendarAction[10] = {
    "\n[공유 캘린더]\n",
    "1. 새로운 공유캘린더 생성\n",
    "2. 새로운 공유캘린더 참가\n",
    "3. 내가 속한 캘린더 들어가기\n",
    "> "
};


string inputCreateSharedCalendar[10] = {
    "\n[새로운 공유 캘린더 생성]\n",
    "캘린더 제목 > ",
    "캘린더 비밀번호 > ",
    "캘린더 입장인원 > ",
    "캘린더 유효기간 > ",
    "성공적으로 저장되었습니다.\n"
};


string inputJoinSharedCalendar[10] = {
    "\n[새로운 공유캘린더 참가]\n",
    "참가할 공유캘린더 제목 > ",
    "참가할 공유캘린더 비밀번호 > ",
    "성공적으로 저장되었습니다.\n",
    "\n[참가된 캘린더 목록 출력]\n"
};

string signInShardCalendar[10] = {
    "\n[내가 속한 공유 캘린더 들어가기]\n",
    "> ",
    "\n[", "기능선택]\n"
};

string choiceSpecifiedSharedCalendarAction[10] = {
    "\n[캘린더 기능 선택]\n",
    "0. 캘린더 삭제",
    "> "
};

string delSharedCalenadr[10]= {
    "\n[캘린더 삭제]\n",
    "진짜 삭제하시겠습니까 ? (y/n) > ",
    "\n[공유캘린더 목록선택]\n",
    "성공적으로 삭제되었습니다.\n"
};