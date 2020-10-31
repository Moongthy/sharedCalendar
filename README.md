Calendar / sharedCalendar
=========================

data하위 문서/check.hpp/strings.h 만 euc-kr

컴파일 명령어 
    
        ~/shared_calendar$ g++ -o execution/main source/main.cpp

📦shared_calendar  
 ┣ 📂data  
 ┃ ┣ 📂Calendar  
 ┃ ┃ ┗ 📜apple.txt  
 ┃ ┣ 📜SharedCalendarList.txt  
 ┃ ┗ 📜UserList.txt  
 ┣ 📂execution  
 ┃ ┗ 📜main.exe  
 ┣ 📂header  
 ┃ ┣ 📂input  
 ┃ ┃ ┣ 📜check.h  
 ┃ ┃ ┣ 📜check.hpp  
 ┃ ┃ ┗ 📜menuInput.h  
 ┃ ┣ 📂type  
 ┃ ┃ ┣ 📜Date.h  
 ┃ ┃ ┣ 📜Schedule.h  
 ┃ ┃ ┣ 📜User.h  
 ┃ ┃ ┗ 📜Users.h  
 ┃ ┣ 📜Calendar.h  
 ┃ ┣ 📜ReadFile.h  
 ┃ ┣ 📜SharedCalendar.h  
 ┃ ┣ 📜SharedCalendarManager.h  
 ┃ ┗ 📜strings.h  
 ┣ 📂source  
 ┃ ┣ 📜Calendar.hpp  
 ┃ ┣ 📜main.cpp  
 ┃ ┣ 📜menuInput.hpp  
 ┃ ┣ 📜ReadFile.hpp  
 ┃ ┣ 📜SharedCalendar.hpp  
 ┃ ┣ 📜SharedCalendarManager.hpp  
 ┃ ┗ 📜Users.hpp  
 ┗ 📜README.md  
    
-----------------------------------------------------
/************우선순위 목록***************/


1. 완성

    개인&공유 일정목록 로드&세이브

    1줄 1줄꼴로 디버깅 출력문(영문) 박아놓기. 특히 생성자나 소멸자엔 필수임

    로드& 세이브 함수 들어갈 때, 나갈 때, 함수 호출할 때 기타 등등 ,,,, 무적권 박으셈
    ->생성,수정,삭제 되면 바로바로 세이브&로드되야되죠?
    cout << "fncname in xxx.hpp" << endl;
    ㅎ
    관라자일 경우에 공캘 삭제 -> 진짜 제데로 되는지 확인. 


2. 자잘한 예외 처리

    한글 글자 수 처리

    날짜 뒤에 두자리.

    공유 캘린더 들어가기 누르고(3번), 엔터만 눌러버리면 아예 뻑가~

3. 기타

    공유 캘린더 지울때 해당 공유 캘린더의 "일정 목록"을 저장한 텍스트 파일 자체 삭제


4. 공캘목록 로드 & 세이브 시점.(생성자, 소멸자에 로드 & 세이브 넣으면 안됨)

    SharedCalendarList.txt는 정상종료(3눌러서 끄는거) 할 때만 저장됨. 중간에 ctrl + C하면 저장안됨.
    
    또한 로드는 Users.hpp 에 sharedCalendarManager 생성한 직후 로드함수를 호출함.

    디버깅 로그에 call scm Constructor in Users.hpp 라고 뜬후 scm Constructor가 띄워져야 정상.
    
    그냥 scm Constructor 하나만 띡 뜨면 로드 안된것임.
    ------------------------------------------------------------