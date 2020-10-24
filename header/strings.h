
#include<string>

using std::string;

string err[10] = {
    "올바른 입력형식이 아닙니다.\n",
    "로그인 실패\n",
    "안녕히 가세요.\n",
    "이미 있는 ID입니다."
    "1 입력함\n",
    "2 입력함\n",
    "3 입력함\n",
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
    "1. 새로운 공유 캘린더 생성\n",
    "2. 새로운 공유 캘린더 참가\n",
    "3. 내가 속한 캘린더 들어가기\n",
    "> "
};

// 새로운 공유 캘린더 생성
string inputCreateSharedCalendar[10] = {
    "[새로운 공유 캘린더 생성]",
    "캘린더 제목 > ",
    "캘린더 비밀번호 > ",
    "캘린더 입장인원 > ",
    "캘린더 유효기간 > ",
    "성공적으로 저장되었습니다.\n"
};

// 새로운 공유 캘린더 참가
string inputJoinSharedCalendar[10] = {
    "[새로운 공유 캘린더 참가]\n",
    "참가할 공유 캘린더 제목 > ",
    "참가할 공유 캘린더 비밀번호 > ",
    "성공적으로 저장되었습니다.\n",
    "[참가된 캘린더 목록 출력]\n"
};

// 내가 속한 캘린더 들어가기
string signInShardCalendar[10] = {
    "[공유 캘린더 목록 선택]\n",
    "> "
};

string choiceSpecifiedSharedCalendarAction[10] = {
    "[목록 선택]",
    "0. 캘린더 삭제",
    "> "
};

string delSharedCalenadr[10]= {
    "[캘린더 삭제]",
    "진짜 삭제하시겠습니까 ? (y/n) > ",
    "[캘린더 삭제 성공]",
    "성공적으로 삭제되었습니다."
};