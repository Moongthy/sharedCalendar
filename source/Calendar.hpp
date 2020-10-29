

template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user)
 :administrator(user), calendarID(user.getUserId()) { 
    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);
    curr_year = pLocal->tm_year + 1900;
    curr_month = pLocal->tm_mon+1;
    curr_day = pLocal->tm_mday;

    ReadFile re;
    vector<string> id_list = re.readCalendar(user.getUserId(), 0);
    maximum_id = stoi(id_list[id_list.size()-1])+1;

    loadPersonalScheduleList();
 }

template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user, string sharedCalendarId)
 :administrator(user), calendarID(sharedCalendarId) { 
    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);
    curr_year = pLocal->tm_year + 1900;
    curr_month = pLocal->tm_mon+1;
    curr_day = pLocal->tm_mday;
 }

template<typename S, typename U, typename D>
string Calendar<S, U, D>::getCalendarID(){
    return calendarID;
}

template<typename S, typename U, typename D>
U Calendar<S, U, D>::getCalendarAdministrator(){
    return administrator;
}






