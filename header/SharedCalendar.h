#pragma once

#ifndef __SHAREDCALENDAR__
#define __SHAREDCALENDAR__

#include"input/check.h"
#include"Calendar.h"

/**
 * 공유캘린더 클래스
 * 
 * @param S Schedule(일정) type 
 * @param U User(사용자) type
 * @param D Date(날짜, 시간) type
 * 
 * @author 문근 조
 */
template<typename S, typename U, typename D>
class SharedCalendar : public Calendar<S, U, D>{
private:
    // 공유 캘린더 이름
    string sharedCalendarName;
    // 공유 캘린더 비밀번호
    string passWord;
    // 수용 가능 인원
    int acceptable;
    // 시작일자
    D startDate;
    // 종료일자
    D endDate;
    // 멤버리스트
    vector<U> memberList;

public:
    /**
     *      공유 캘린더 생성자
     *  @param administrator        만든사람(관리자)
     *  @param sharedCalendarName   공유캘린더 이름
     *  @param sharedCalendarId     공유캘린더 ID
     *  @param acceptable           수용가능인원
     *  @param startDate            만든날짜
     *  @param endDate              유효기간
     */
    SharedCalendar(U administrator, string sharedCalendarId, string sharedCalendarName, string pw, int acceptable, D startDate, D endDate);

    ~SharedCalendar()
    {
        // Calendar<S, U, D>::saveSharedScheduleList();
    }
    
    string getSharedCalendarName();

    // @return 수용가능인원 
    int getAcceptable();

    // @return 만든날짜
    D getStartDate();

    // @return 유효기간 
    D getEndDate();

    // @return 멤버리스트 
    vector<U> getMemberList();

    // @return 비번 
    string getPassWord();   

    /**
     *  @param  newMember 참여하고자 하는 사용자
     *  @return 성공여부
     */
    int addMember(U newMember);


};

#include"../source/SharedCalendar.hpp"
#endif