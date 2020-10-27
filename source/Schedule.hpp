/*************************일정 파트********************************/
//의문사항
//(1) 스케쥴 클래스에 date 자료가 있으니까 따로 여기서 받을 필요는 있을까?
template<typename S, typename U, typename D>
void Calendar<S, U, D>::show_Schedules(int curr_year, int curr_month){
    //현재 날짜에 대한 정보 필요
    time_t curr_time = time(nullptr);
    struct tm * curr_tm = localtime(&curr_time);

    int currentYear = curr_tm -> tm_year + 1900;
    int currentMonth = curr_tm -> tm_mon + 1;
    int idx = (curr_year * 100 + curr_month) - 197001;

    if (scheduleList[idx].length() != 0) {
        cout << "Noting to show" << endl;
    }
    else {
        for(int i = 0; i<scheduleList[idx].length(); i++) {
            // Schedule Print
        }
    }
}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::addSchedule(D startDate, D endDate, string content){
    scheduleList.push_back(S(startDate, endDate, content));
}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule(){
    //id로 수정하는건데
    //parameter 수정 필요

}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::deleteSchedule(string keyword){
    // searchSchedule에서 vector에 추가 대신 원래 vector에서 pop해주면 될듯
}

template<typename S, typename U, typename D>
vector<S>& Calendar<S, U, D>::searchSchedule(string keyword){
    vector<S> SearchScheduleList;
    for(int i = 0; i<1200; i++) {
        int len = scheduleList[i].length();
        for(int j = 0; j<len; j++) {
            string content = S.getContent();
            if(content.find(keyword)) {
                SearchScheduleList.push_back(S);
            }
        }
    }
    //schedulelist 탐색하면서 keyword 들어있는 S탐색
    //SearchScheduleList에 넣어줌

    // SearchScheduleList의 크기 0이면 해당하는 것 없음

    return SearchScheduleList;
}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::showNextMonthSchedules(){
    //계속 가져가는 인덱스 필요
    //원래 인덱스와 옆으로 넘어가는 인덱스
    // 인덱스만 감소, 유효성 확인(가능한 달인가?)
    // show schedules 함수 사용 하면 좋을듯
    int idx = (currentYear * 100 + currentMonth) - 197001;
    if(idx - 1 >= 0) {
        if (scheduleList[idx-1].length() == 0) {
            cout << "Noting to show" << endl;
        }
        else {
            for(int i = 0; i<scheduleList[idx-1].length(); i++) {
            // Schedule Print
            }
        }
    }
    else {
        // 이전 달이 없습니다.
    }
}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::showPrevMonthSchedules(){
    int idx = (currentYear * 100 + currentMonth) - 197001;
    if(idx + 1 >= 1200) {
        if (scheduleList[idx+1].length() == 0) {
            cout << "Noting to show" << endl;
        }
        else {
            for(int i = 0; i<scheduleList[idx+1].length(); i++) {
            // Schedule Print
            }
        }
    }
    else {
        // 다음 달이 없습니다.
    }
}