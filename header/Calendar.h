#pragma once
#ifndef __CALENDER__
#define __CALENDER__

#include <bits/stdc++.h>
#include "strings.h"
#include "./type/Date.h"
using namespace std;

/**
 * 개인 캘린더 클래스 및 공유캘린더 부모 클래스
 * 
 * @param S Schedule(일정) type 
 * @param U User(사용자) type
 * @param D Date(날짜, 시간) type
 * 
 * @author 문근 & 예슬
 */

template <typename S, typename U, typename D>
class Calendar
{
protected:
    // 일정 목록
    vector<vector<S>> scheduleList(1200, vector<S>);
    
    // 캘린더 현재 년도월에 대한 index (0 ~ 1199)
    int ym_idx;

    // 만든사람
    U administrator;

    // 캘린더 id
    string calendarID;

public:
    /**
     *  개인 캘린더 생성자
     *  일정목록의 크기는 0으로 초기화됨
     * 
     *  @param user 이 캘린더를 생성한 사람. 관리자
     */
    Calendar(U user);

    /**
     *  공유 캘린더 생성자에서 호출될 생성자
     *  일정목록의 크기는 0으로 초기화됨
     * 
     *  @param administrator 이 캘린더를 생성한 사람. 관리자
     *  @param sharedCalendarId 공유캘린더 Id. 현재있는 공유캘린더 수 + 1000 으로 매겨짐
     */
    Calendar(U user, string sharedCalendarId);

    /**
     *  캘린더 생성자
     *  MenuInput의 currentDateTime으로 ym_idx 초기화
     */
    Calendar();

    /**
     *  getter of caledarID 
     */
    string getCalendarID();

    U getCalendarAdministrator();

    /*************************일정 파트********************************/
        
    /**
     *  일정 옵션 선택
     */
    void select_Schedules_option();

    /**
     *  일정을 보여줌
     */
    void show_Schedules(int ym_idx);

    /**
     *  새로운 일정을 일정목록에 추가함
     * 
     *  @param startTime 일정 시작 시간
     *  @param endTime  일정 끝 시간
     *  @param content 일정 내용
     */
    void addSchedule();

    /**
     *  일정을 수정함
     */
    void modifySchedule();
    int modifyTitle(S s, string title);
    int modifyTime(S s, string hhmm);
    int modifyContent();
    int modifyLocation();
    int modifyDate(S s, string yymmdd);

    /**
     *  일정을 삭제함.
     * 
     *  @param keyword  사용자가 입력한 문자열
     */
    void deleteSchedule(string keyword);

    /**
     *  일정을 검색함.
     * 
     *  @param keyword  검색한 문자열
     *  @return 검색한 일정 
     */
    vector<S>& searchSchedule(string keyword);

    /**
     *  저번달, 다음달 일정을 보여줌
     */
    void showNextMonthSchedules();
    void showPrevMonthSchedules();
};

#include "../source/Calendar.hpp"
#include "../source/Schedule.hpp"
#include "../source/ScheduleManager.hpp"

#endif