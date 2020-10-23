
template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user)
 :administrator(user), calendarID(user.getUserId()) { }

template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user, string sharedCalendarId)
 :administrator(user), calendarID(sharedCalendarId) { }

template<typename S, typename U, typename D>
string Calendar<S, U, D>::getCalendarID(){
    return calendarID;
}

template<typename S, typename U, typename D>
U Calendar<S, U, D>::getCalendarAdministrator(){
    return administrator;
}

/*************************일정 파트********************************/
//의문사항
//(1) 스케쥴 클래스에 date 자료가 있으니까 따로 여기서 받을 필요는 있을까?
template<typename S, typename U, typename D>
void Calendar<S, U, D>::show_Schedules(){

}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::addSchedule(D startDate, D endDate, string content){
    scheduleList.push_back(S(startDate, endDate, content));
}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule(){

}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::deleteSchedule(string keyword){

}

template<typename S, typename U, typename D>
S& Calendar<S, U, D>::searchSchedule(string keyword){

}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::showNextMonthSchedules(){

}

template<typename S, typename U, typename D>
void Calendar<S, U, D>::showPrevMonthSchedules(){

}




