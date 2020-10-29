
template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user)
 :administrator(user), calendarID(user.getUserId()) { 
    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);
    curr_year = pLocal->tm_year + 1900;
    curr_month = pLocal->tm_mon+1;
    loadPersonalScheduleList();
 }

template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user, string sharedCalendarId)
 :administrator(user), calendarID(sharedCalendarId) { 
    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);
    curr_year = pLocal->tm_year + 1900;
    curr_month = pLocal->tm_mon+1;
 }

template<typename S, typename U, typename D>
string Calendar<S, U, D>::getCalendarID(){
    return calendarID;
}

template<typename S, typename U, typename D>
U Calendar<S, U, D>::getCalendarAdministrator(){
    return administrator;
}






