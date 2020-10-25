#pragma once
#include<string>

using std::string;

string jaum = "ㄱㄴㄷㄹㅁㅂㅅㅇㅈㅊㅋㅌㅍㅎㄲㄸㅃㅆㅉㄳㄵㄶㄺㄻㄼㄽㄾㄿㅀㅄㅏㅑㅓㅕㅗㅛㅜㅠㅡㅣㅐㅒㅔㅖㅘㅙㅚㅝㅞㅟㅢ";

string err[10] = {
    "올바르지 않은 입력형식 입니다.\n",
    "로그인 실페\n",
    "?븞?뀞?엳 媛??꽭?슂.\n",
    "?씠誘? ?엳?뒗 ID?엯?땲?떎."
    "1 ?엯?젰?븿\n",
    "2 ?엯?젰?븿\n",
    "3 ?엯?젰?븿\n",
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

// ?깉濡쒖슫 怨듭쑀 罹섎┛?뜑 ?깮?꽦
string inputCreateSharedCalendar[10] = {
    "[새로운 공유 캘린더 생성]\n",
    "캘린더 제목 > ",
    "캘린더 비밀번호 > ",
    "캘린더 입장인원 > ",
    "캘린더 유효기간 > ",
    "성공적으로 저장되었습니다.\n"
};

// ?깉濡쒖슫 怨듭쑀 罹섎┛?뜑 李멸??
string inputJoinSharedCalendar[10] = {
    "[새로운 공유캘린더 참가]\n",
    "참가할 공유캘린더 제목 > ",
    "참가할 공유캘린더 비밀번호 > ",
    "성공적으로 저장되었습니다.\n",
    "[참가된 캘린더 목록 출력]\n"
};

// ?궡媛? ?냽?븳 罹섎┛?뜑 ?뱾?뼱媛?湲?
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