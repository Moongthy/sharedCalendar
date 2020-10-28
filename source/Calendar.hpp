
template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user)
 :administrator(user), calendarID(user.getUserId()) { }

template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user, string sharedCalendarId)
 :administrator(user), calendarID(sharedCalendarId) { }

template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar() {
    // 현재 날짜에 대한 정보 필요
    // 메뉴 인풋에서 Date 가져와서

    //D curr = MenuInput::currentDateTime();
    //ym_idx = ((curr.yy - 1970) * 12 + curr.mm - 1);
    
    time_t curr_time = time(nullptr);
    struct tm * curr_tm = localtime(&curr_time);

    curr_year = curr_tm -> tm_year + 1900;
    curr_month = curr_tm -> tm_mon + 1;
}

template<typename S, typename U, typename D>
string Calendar<S, U, D>::getCalendarID(){
    return calendarID;
}

template<typename S, typename U, typename D>
U Calendar<S, U, D>::getCalendarAdministrator(){
    return administrator;
}