
template<typename S, typename U, typename D>
SharedCalendar<S, U, D>::SharedCalendar(U administrator, string sharedCalendarId, string sharedCalendarName, string pw, int acceptable, D startDate, D endDate)
 :Calendar<S, U, D>(administrator, sharedCalendarId), sharedCalendarName(sharedCalendarName), passWord(pw), acceptable(acceptable), startDate(startDate), endDate(endDate) { 
     
    Calendar<S, U, D>::isShared = true;

    Calendar<S, U, D>::loadSharedScheduleList();
     
     memberList.push_back(administrator);
 }

template<typename S, typename U, typename D>
int SharedCalendar<S, U, D>::getAcceptable(){
    return acceptable;
}

template<typename S, typename U, typename D>
string SharedCalendar<S, U, D>::getSharedCalendarName(){
    return sharedCalendarName;
}

template<typename S, typename U, typename D>
D SharedCalendar<S, U, D>::getStartDate(){
    return startDate;
}

template<typename S, typename U, typename D>
D SharedCalendar<S, U, D>::getEndDate(){
    return endDate;
}

template<typename S, typename U, typename D>
vector<U> SharedCalendar<S, U, D>::getMemberList(){
    return memberList;
}

template<typename S, typename U, typename D>
string SharedCalendar<S, U, D>::getPassWord(){
    return passWord;
}

template<typename S, typename U, typename D>
int SharedCalendar<S, U, D>::addMember(U newMember){
    if(memberList.size() == acceptable) return 0;
    memberList.push_back(newMember);
    return 1;
}