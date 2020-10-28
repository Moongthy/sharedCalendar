
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






