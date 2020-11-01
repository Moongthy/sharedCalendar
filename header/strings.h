#pragma once
#include<string>

using std::string;

string jaum = "ㄱㄴㄷㄹㅁㅂㅅㅇㅈㅊㅋㅌㅍㅎㄲㄸㅃㅆㅉㄳㄵㄶㄺㄻㄼㄽㄾㄿㅀㅄㅏㅑㅓㅕㅗㅛㅜㅠㅡㅣㅐㅒㅔㅖㅘㅙㅚㅝㅞㅟㅢ";

string err[10] = {
    "올바르지 않은 입력형식 입니다.\n",
    "로그인 실패\n",
    "이미 있는 ID입니다.\n",
    "이동할 수 없습니다.\n\n"
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
    "> ",
    "[",
    "캘린더 기능선택]\n"
};

string choiceSpecifiedSharedCalendarAction[10] = {
    "[캘린더 기능 선택]\n",
    "0. 캘린더 삭제\n",
    "> "
};

string delSharedCalenadr[10]= {
    "[캘린더 삭제]",
    "진짜 삭제하시겠습니까 ? (y/n) > ",
    "[공유캘린더 목록선택]",
    "성공적으로 삭제되었습니다."
};

string calendarSelectionOption[10] = {
    "[캘린더 기능 선택]\n",
    "0. 캘린더 삭제\n",
    "1. 일정 생성\n",
    "2. 일정 수정\n",
    "3. 일정 삭제\n"
    "4. 일정 검색\n",
    "5. 이전 달 일정 보기\n",
    "6. 다음 달 일정 보기\n",
};

string makeScheduleOption[10] = {

};

string modifyScheduleOption[10] = {
    "[수정할 항목]\n",
    "1. 제목\n",
    "2. 날짜\n",
    "3. 시작 시간\n",
    "4. 종료 시간\n",
    "5. 내용\n",
    "6. 장소\n"
};

string myCalendar[10] = {
    "[개인 캘린더]\n",
    "[공유 캘린더]\n"
};

string showSchedulesString[10] = {
    "해당 월에 스케줄이 없습니다!\n"
};

string addSchedulesString[10] = {
    "[일정 생성]\n",
    "제목 > ",
    "날짜 > ",
    "시작시간 > ",
    "종료시간 > ",
    "장소 > ",
    "내용 > ",
    "일정 생성에 성공하였습니다.\n\n"
};

string modifySchedulesString[10] = {
    "[일정 수정]\n",
    "제목 > ",
    "날짜 > ",
    "시작시간 > ",
    "종료시간 > ",
    "장소 > ",
    "내용 > ",
    "일정 생성에 성공하였습니다.\n\n",
    "[다른 항목 수정] Y/N > "
};

string deleteString[10] = {
    "[일정 삭제]\n",
    "1. 삭제할 일정 선택\n",
    "2. 이동할 연/월 선택\n",
    "[정말 삭제하시겠습니까?] Y/N > "
};

string searchSchedulesString[10] = {
    "[일정 검색]\n",
    "[일정 검색 결과]\n",
    "검색 결과가 없습니다.\n",
    "검색어 입력 > "
};

string ScheduleInfo[12] = {
    "제목 : ",
    "날짜 : ",
    "년 ",
    "월 ",
    "일 ",
    "시작시간 : ",
    "시 ",
    "분 ",
    "종료시간 : ",
    "내용 : ",
    "장소 : ",
    "ID : "
};

string line = "==========================================";
string prompt = "> ";
string noID = "없는 ID입니다.\n";

string modifyString[10] = {
    "[일정 수정]\n",
    "1. 수정할 일정 선택\n",
    "2. 이동할 연/월 선택\n",
    "[연 / 월 입력]\n"
};