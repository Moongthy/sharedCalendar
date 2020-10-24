#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

//UserList.txt
//SharedCalendarList.txt
//(캘린더 ID).txt

class ReadFile {
    private:
        ifstream read;
        ofstream write;
        int separatorIndex;
        string separator = "$";

    public:

        /**
         * UserList.txt 파일에 저장되어있는 사용자들의 아이디
         * (아이디 중복 확인 사용)
         * 
         * @return 
         *      사용자아이디 리스트
         */        
        vector<string> getUserIDList();


        /**
         * 입력받은 아이디의 패스워드 확인
         * 
         * @param userID 패스워드를 알고 싶은 사용자 아이디
         * 
         * @return 
         *      해당 아이디의 패스워드
         */  
        string getUserpassword(string userID);
        

        /**
         * UserList.txt에 회원가입한 회원정보 입력
         * 
         * @param id 아이디
         * @param password 패스워드
         * @param name 이름
         *
         */  
        void writeUserList(string id, string password, string name);
        

        /**
         * SharedCalendarList.txt에 생성한 공유 캘린더 정보 입력
         * (공유 캘린더 생성 시 기획서에서 공유 캘린더 비밀번호 입력받는데, 
         * 데이터파일에 비밀번호 저장을 안해서 임의로 만들었음.)
         * (데이터 파일에 제한인원 있는데 사용안해서 임의로 없앰.)
         * 
         * @param title 제목
         * @param password 비밀번호 
         * @param startday 시작하는날
         * @param endday 유효기간
         * @param admin 만든 사람
         * 
         */  
        void writeSCList(string title, string password, string startday, string endday, string admin);
        

        /**
         * SharedCalendarList.txt 파일에 저장되어있는 공유 캘린더 제목
         * (제목 중복 확인 사용)
         * 
         * @return 
         *      공유 캘린더 제목 리스트
         */
        vector<string> getSCTitleList();
        

        /**
         * 입력받은 제목의 패스워드 확인
         * 
         * @param inputTitle 패스워드 확인하고 싶은 공유 캘린더 제목
         * 
         * @return 
         *      해당 제목의 패스워드
         */
        string getSCPassword(string inputTitle);
        

        /**
         * SharedCalendarList.txt에 공유 캘린더 멤버 추가 입력
         * 
         * @param title 공유캘린더 제목
         * @param member 사용자 아이디
         * 
         */
        void writeSCMember(string title, string member);


        /**
         * (Calendar/UserID).txt에 일정 입력
         * 
         * @param userID 사용자 아이디
         * @param name 일정 제목
         * @param date 날짜
         * @param starttime 시작 시간
         * @param endtime 종료 시간
         * @param loc 장소(없으면 null 넘겨주기)
         * @param memo 메모(없으면 null 넘겨주기)
         * 
         */
        void writeSchedule(string userID, string name, string date, string starttime, string endtime, string loc, string memo);
        
        /**
         * (Calendar/UserID).txt에 있는 일정 수정
         * 
         * @param userID 사용자 아이디
         * @param scheID 일정 아이디
         * @param index 1:제목, 2:날짜, 3:시작시간, 4:종료시간, 5:장소, 6:메모
         * @param text 수정한 내용
         * 
         */
        void editSchedule(string userID, string scheID, int index, string text);
        

        /**
         * (Calendar/UserID).txt에 있는 일정 삭제
         * 
         * @param userID 사용자 아이디
         * @param scheID 일정 아이디
         * 
         */
        void deleteSchedule(string userID, string scheID);

        

};


#include"../source/ReadFile.hpp"
