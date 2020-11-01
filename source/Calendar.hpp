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
    if(id_list.size()!=0) maximum_id = stoi(id_list[id_list.size()-1])+1;

    //loadPersonalScheduleList();
 }

template<typename S, typename U, typename D>
Calendar<S, U, D>::Calendar(U user, string sharedCalendarId)
 :administrator(user), calendarID(sharedCalendarId) { 
    // cout << "Calendar Constructor" << endl;
    isShared = true;
    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);
    curr_year = pLocal->tm_year + 1900;
    curr_month = pLocal->tm_mon+1;
    curr_day = pLocal->tm_mday;
    
    // cout << "readSCCalendar in Calendar Constructor" << endl;
    ReadFile re;
    /**
     * SharedCalendar/calID.txt 파일에 저장되어 있는 정보
     *  
     * @param calID 사용자 아이디
     * @param index 0:id, 1:name, 2:date, 3:starttime, 4:endtime, 5:loc, 6:memo
     * 
     * @return
     *      index에 맞는 list
     */
    vector<string> id_list = re.readSCCalendar(sharedCalendarId, 0);
    // cout << "id_list" << endl;
    // for(string s : id_list)
    // {
    //     cout << s << endl;
    // }
    if(id_list.size()!=0) maximum_id = stoi(id_list[id_list.size()-1])+1;
 }

template<typename S, typename U, typename D>
string Calendar<S, U, D>::getCalendarID(){
    return calendarID;
}

template<typename S, typename U, typename D>
U Calendar<S, U, D>::getCalendarAdministrator(){
    return administrator;
}






