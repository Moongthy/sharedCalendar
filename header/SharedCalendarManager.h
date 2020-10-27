#pragma once

#ifndef __SHAREDCALENDARMANGER__
#define __SHAREDCALENDARMANGER__

#include"SharedCalendar.h"

#include"ReadFile.h"

#include<iostream>

using std::cout;
using std::endl;

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
class SharedCalendarManager{
public:
    // 공유캘린더 목록
    vector<SharedCalendar<S, U, D>> sharedCalendarList;
    
    // 생성자
    SharedCalendarManager();
    ~SharedCalendarManager();

    // @return 공유캘린더 목록
    vector<SharedCalendar<S, U, D>> getSharedCalendarList();

    // @returh 공유캘린더 갯수
    int getSharedCalendarListSize();
    
    /**
     * 공유캘린더 목록에 공유캘린더를 추가한다.
     * 
     * @param user 공유캘린더 만든 사람
     * @param sharedCalndarName 공유캘린더 이름
     * @param acceptable 공유캘린더 수용인원
     * @param startDate 공유캘린더 만든 날짜
     * @param endDate 공유캘린더 유효기간
     **/
    void addSharedCalendar(U user, string sharedCalendarName, string pw,
     int acceptable, D startDate, D endDate);

    /**
     * keyword와 공유캘린더 목록에 있는 공유캘린더의 이름과의 
     * 동치여부를 검색한다.
     * 
     * @param keyword 사용자가 입력한 문자열
     * 
     * @return 
     *      일치하는 공유캘린더 이름이 존재하면, 해당 공유캘린더의 공유캘린더목록 인덱스를 반환
     *      일치하는 공유캘린더 이름이 없다면, -1반환
     */
    int searchSharedCalendarIdx(string keyword);

    /**
     * 공유캘린더에 입장한다.
     * 
     * @param user 입장하고자 하는 사용자
     * @param inputCalendarName 사용자가 입력한 공유캘린더 이름
     * @param inputPassWord 사용자가 입력한 공유캘린더 비번
     * 
     * @return
     *      일치 공유캘린더 없음 : 0
     *      패스워드 불일치 : -1
     *      성공 : 1
     */
    int intoSharedCalendar(U user, string inputCalendarName, string inputPassWord);
    
    /**
     * 공유캘린더에 입장한다.
     * 
     * @param user 입장하고자 하는 사용자
     * @param inputCalendarName 사용자가 입력한 공유캘린더 이름
     * @param inputPassWord 사용자가 입력한 공유캘린더 비번
     * 
     * @return
     *      일치 공유캘린더 없음 : 0
     *      패스워드 불일치 : -1
     *      정원 초과 : -2
     *      성공 : 1
     */
    int joinSharedCalendar(U user, string inputCalendarName, string inputPassWord);

    /**
     * 관리자일 경우 해당 캘린더를 삭제 건웅.
     * 
     * @param user 관리자
     * @param scIdx 삭제할 공캘 인덱스
     * 
     * @return 성공여부
     * 
     */
    int deleteSharedCalendar(U user, int scIdx);

    // 공유캘린더 목록 출력
    void showSharedCalendarList();

    /****************************파일 입출력 파트*********************************/
    int saveSharedCalendarList();
    int loadSharedCalendarList();
};

#include"../source/SharedCalendarManager.hpp"
#endif
