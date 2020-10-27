#pragma once
#include<string>

using std::string;

string jaum = "ㄱㄴㄷㄹㅁㅂㅅㅇㅈㅊㅋㅌㅍㅎㄲㄸㅃㅆㅉㄳㄵㄶㄺㄻㄼㄽㄾㄿㅀㅄㅏㅑㅓㅕㅗㅛㅜㅠㅡㅣㅐㅒㅔㅖㅘㅙㅚㅝㅞㅟㅢ";

string err[10] = {
    "올바르지 않은 입력형식 입니다.\n",
    "로그인 실패\n",
    "이미 있는 ID입니다\n"
};

string loginMenu[10]={
    "[로그인 선택 메뉴]\n", // 0 
    "1. 로그인\n2. 회원가입\n3. 종료\n> ", // 1 
    "[종료]\n안녕히가세요.\n", // 2
    "로그인 성공!\n", // 3
    "회원가입 성공!\n",// 4
    "[로그인]\n", // 5
    "[회원가입]\n", // 6
    "ID> ", // 7
    "비밀번호> ", // 8
    "이름> " // 9
};

string choiceCalendarMenu[10] = {
    "[캘린더 선택 메뉴]\n",
    "1. 개인 캘린더\n",
    "2. 공유 캘린더\n",
    "3. 종료\n",
    "> "
};

string choiceSharedCalendarAction[10] = {
    "[공유 캘린더]\n",
    "1. 새로운 공유캘린더 생성\n",
    "2. 새로운 공유캘린더 참가\n",
    "3. 내가 속한 캘린더 들어가기\n",
    "> "
};


string inputCreateSharedCalendar[10] = {
    "[새로운 공유 캘린더 생성]\n",
    "캘린더 제목 > ",
    "캘린더 비밀번호 > ",
    "캘린더 입장인원 > ",
    "캘린더 유효기간 > ",
    "성공적으로 저장되었습니다.\n"
};


string inputJoinSharedCalendar[10] = {
    "[새로운 공유캘린더 참가]\n",
    "참가할 공유캘린더 제목 > ",
    "참가할 공유캘린더 비밀번호 > ",
    "성공적으로 저장되었습니다.\n",
    "[참가된 캘린더 목록 출력]\n"
};


string signInShardCalendar[10] = {
    "[내가 속한 공유 캘린더 들어가기]\n",
    "> "
};

string choiceSpecifiedSharedCalendarAction[10] = {
    "[캘린더 기능 선택]",
    "0. 캘린더 삭제",
    "> "
};

string delSharedCalenadr[10]= {
    "[캘린더 삭제]",
    "진짜 삭제하시겠습니까 ? (y/n) > ",
    "[공유캘린더 목록선택]",
    "성공적으로 삭제되었습니다."
};