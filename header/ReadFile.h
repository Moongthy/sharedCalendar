#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <io.h>
#include "../header/type/User.h"

using namespace std;

class ReadFile {
    private:
        ifstream read;
        ofstream write;
        int separatorIndex;
        char separator = '$';

    public:

        /**
         * 파일 생성 
         */
        void isFileExist(string filepath);


        /**
         * UserList.txt 파일에 저장되어 있는 정보
         * 
         * @param index 0:id, 1:password, 2:name
         * 
         * @return
         *      index에 맞는 list
         */
        vector<string> readUserList(int index);



        /**
         * UserList.txt 파일에 저장되어있는 사용자 아이디와 이름을 User 타입저장 후 반환
         * 
         * @return 
         *      User 타입으로 저장한 list
         */
        vector<User> getUserIdName();


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
         * SharedCalendarList.txt 파일에 저장되어 있는 정보
         * 
         * @param index 0:id, 1:title, 2:password, 3:startday, 4:endday, 5:admin
         * 
         * @return
         *      index에 맞는 list
         */
        vector<string> readSCList(int index);


        /**
         * SharedCalendarList.txt 전체 불러오기 
         * 
         * @return
         *      line별 내용
         */          
        vector<string> getSCList();


        /**
         * SharedCalendarList.txt 전체 삭제 
         */          
        void clearSCList();

        /**
         * SharedCalendarList.txt 전체 삭제 
         */          
        void clearSCScheList(string calId);



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
         * SharedCalendar/calID.txt 파일에 저장되어 있는 정보
         *  
         * @param calID 사용자 아이디
         * @param index 0:id, 1:name, 2:date, 3:starttime, 4:endtime, 5:loc, 6:memo
         * 
         * @return
         *      index에 맞는 list
         */
        vector<string> readSCCalendar(string calID, int index);    



        /**
         * (SharedCalendar/cal_ID).txt에 일정 입력
         * 
         * @param calID 공유 캘린더 아이디
         * @param name 일정 제목
         * @param date 날짜
         * @param starttime 시작 시간
         * @param endtime 종료 시간
         * @param loc 장소(없으면 null 넘겨주기)
         * @param memo 메모(없으면 null 넘겨주기)
         * 
         */
         void writeSCSchedule(string calID, string id, string name, string date, string starttime, string endtime, string loc, string memo);
           

        /**
         * 캘린더 UserID.txt 파일에 저장되어 있는 정보
         *  
         * @param userID 사용자 아이디
         * @param index 0:id, 1:name, 2:date, 3:starttime, 4:endtime, 5:loc, 6:memo
         * 
         * @return
         *      index에 맞는 list
         */
        vector<string> readCalendar(string userID, int index);    


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
        void writeSchedule(string userID, string id, string name, string date, string starttime, string endtime, string loc, string memo);


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