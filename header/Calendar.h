#pragma once
#ifndef __CALENDER__
#define __CALENDER__

#include <string>
#include <vector>
#include <algorithm>
#include "strings.h"
#include "./type/Date.h"
#include "./type/Schedule.h"
#include "../header/input/check.h"
#include "./ReadFile.h"
#include <time.h>

using namespace std;

/**
 * 개인 캘린더 클래스 및 공유캘린더 부모 클래스
 * / 
 * @param S Schedule(일정) type 
 * @param U User(사용자) type
 * @param D Date(날짜, 시간) type
 * 
 * @author 문근 & 예슬
 */
template <typename S, typename U, typename D> class Calendar
{
protected:
    // 일정 목록
    bool isShared = false;
    vector<Schedule> scheduleList;

    int maximum_id = 1;
    // 캘린더 id
    string calendarID;

    // 만든사람
    U administrator;
public:
    int curr_year;
    int curr_month;
    int curr_day;
    /**
     *  개인 캘린더 생성자
     *  일정목록의 크기는 0으로 초기화됨
     * 
     * 여기서 load() 호출
     * 
     *  @param user 이 캘린더를 생성한 사람. 관리자
     */
    Calendar(U user);

    /**
     *  공유 캘린더 생성자에서 호출될 생성자
     *  일정목록의 크기는 0으로 초기화됨
     * 
     *  load() 호출
     * 
     *  @param administrator 이 캘린더를 생성한 사람. 관리자
     *  @param sharedCalendarId 공유캘린더 Id. 현재있는 공유캘린더 수 + 1000 으로 매겨짐
     */
    Calendar(U user, string sharedCalendarId);

    // 여기서 save 호출
    // 개인 캘린더 소멸자
    virtual ~Calendar()
    {
        // savePersonalScheduleList();
    }

    /**
     *  getter of caledarID 
     */
    string getCalendarID();

    U getCalendarAdministrator();

/*************************일정 파트********************************/

    #include"ReadFile.h"

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
    // void writeSchedule(string userID, string name, string date, string starttime, string endtime, string loc, string memo);
    
    // void savePersonalScheduleList()
    // {
    //     ReadFile rf = ReadFile();
    //     // txt파일 맨앞에 붙는 숫자
    //     int idx = 1;
    //     // 스케줄 갯수만큼, userId.txt 파일에 써벌임
    //     for(Schedule s : scheduleList)
    //     {
            
    //         // Date 를 string 으로 변환 --> 이러면 이상해짐
            
    //         // string d = to_string(s.getDate().yy.substr(2, 3) + to_string(s.getDate().mm) + to_string(s.getDate().dd); 
    //         string d = to_string(s.getDate().yy.substr(2,2) + to_string(s.getDate().mm) + to_string(s.getDate().dd); 
            
    //         rf.writeSchedule(

    //             administrator.getUserId(),
                
    //             to_string(idx),
    //             s.getTitle(),
    //             d,
    //             to_string(s.getStartTime()),
    //             to_string(s.getEndTime()),
    //             s.getLocation(),
    //             s.getContent()
    //         );
    //         ++idx;
    //     }
    // }

    void saveSharedScheduleList()
    {
        ReadFile rf = ReadFile();

        // 여기다가 넣어줏에요
        rf.clearSCScheList(calendarID);
        
        int idx = 1;
        // 스케줄 갯수만큼, userId.txt 파일에 써벌임
        for(Schedule s : scheduleList)
        {
            // Date 를 string 으로 변환
            string d = to_string(s.getDate().yy) + to_string(s.getDate().mm) + to_string(s.getDate().dd); 
            
            rf.writeSCSchedule(
                calendarID,
                to_string(idx),
                s.getTitle(),
                d,
                to_string(s.getStartTime()),
                to_string(s.getEndTime()),
                s.getLocation(),
                s.getContent()
            );
            
            ++idx;
        }
    }

    void loadPersonalScheduleList()
    {
        
        ReadFile rf = ReadFile();
        
        string adminId = administrator.getUserId(); // 관리자 아이디
        
        // userId.txt 파일에서 읽어옮.
        vector<string> sId          = rf.readCalendar(adminId, 0);
        vector<string> sName        = rf.readCalendar(adminId, 1);
        vector<string> sDate        = rf.readCalendar(adminId, 2);
        vector<string> sStartTime   = rf.readCalendar(adminId, 3);
        vector<string> sEndTime     = rf.readCalendar(adminId, 4);
        vector<string> sLoc         = rf.readCalendar(adminId, 5);
        vector<string> sMemo        = rf.readCalendar(adminId, 6);
        
        // 저장된 스케줄 갯수 만큼. 스케줄리스트에 불러온다.
        for(int i = 0; i < sId.size(); ++i)
        {
            // 하나의 스케줄 생성
            Schedule s = Schedule( sName[i], Date(sDate[i]), stoi(sStartTime[i]), stoi(sEndTime[i]), sMemo[i], sLoc[i], stoi(sId[i]));
            
            // 끝에다 넣어줌
            scheduleList.push_back(s);
        }
    }

    void loadSharedScheduleList()
    {
        ReadFile rf = ReadFile();
        // 캘린더id.txt 파일에서 읽어옮.
        vector<string> sId          = rf.readSCCalendar(calendarID, 0);
        vector<string> sName        = rf.readSCCalendar(calendarID, 1);
        vector<string> sDate        = rf.readSCCalendar(calendarID, 2);
        vector<string> sStartTime   = rf.readSCCalendar(calendarID, 3);
        vector<string> sEndTime     = rf.readSCCalendar(calendarID, 4);
        vector<string> sLoc         = rf.readSCCalendar(calendarID, 5);
        vector<string> sMemo        = rf.readSCCalendar(calendarID, 6);

        // 저장된 스케줄 갯수 만큼. 스케줄리스트에 불러온다.
        for(int i = 0; i < sId.size(); ++i)
        {
            // 하나의 스케줄 생성
            Schedule s = Schedule( sName[i], Date(sDate[i]), stoi(sStartTime[i]), stoi(sEndTime[i]), sMemo[i], sLoc[i], stoi(sId[i]));
            
            // 끝에다 넣어줌
            scheduleList.push_back(s);
        }
    }

    check Check = check();
    /**
     *  일정 옵션 선택
     */
    int select_Schedules_option(U user);

    /**
     *  일정을 보여줌
     */
    void show_Schedules(int curr_year, int curr_month);

    /**
     *  새로운 일정을 일정목록에 추가함
     * 
     *  @param startTime 일정 시작 시간
     *  @param endTime  일정 끝 시간
     *  @param content 일정 내용
     */
    void addSchedule(U user);

    /**
     *  일정을 수정함
     */
    void modify(U user);
    void modifySchedule(U user);
    int modifyTitle(int mod_id);
    int modifySTime(int mod_id);
    int modifyETime(int mod_id);
    int modifyContent(int mod_id);
    int modifyLocation(int mod_id);
    int modifyDate(int mod_id);
    int deleteCalendar(U user);
    void deleteS(U user);
    /**
     *  일정을 삭제함.
     * 
     *  @param keyword  사용자가 입력한 문자열
     */
    void deleteSchedule(U user);

    /**
     *  일정을 검색함.
     * 
     *  @param keyword  검색한 문자열
     *  @return 검색한 일정 
     */
    void searchSchedule(U user);

    /**
     *  저번달, 다음달 일정을 보여줌
     */
    void showNextMonthSchedules(U user);
    void showPrevMonthSchedules(U user);
};

#include"../source/Calendar.hpp"
#include"../source/Schedule.hpp"
#include "../source/ScheduleManager.hpp"
#endif