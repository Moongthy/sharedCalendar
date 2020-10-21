    
template<typename S, typename U, typename D>
SharedCalendarManager<S, U, D>::SharedCalendarManager(){};

template<typename S, typename U, typename D>
vector<SharedCalendar<S, U, D>> SharedCalendarManager<S, U, D>::getSharedCalendarList(){
    return getSharedCalendarList;      
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::getSharedCalendarListSize(){
    return sharedCalendarList.size();
}

template<typename S, typename U, typename D>
void SharedCalendarManager<S, U, D>::addSharedCalendar(U user, string sharedCalendarName,
 int acceptable, D startDate, D endDate){
    ;
    sharedCalendarList.push_back(SharedCalendar<S, U, D>(user, sharedCalendarList.size() + 1000,sharedCalendarName,acceptable, startDate, endDate));
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::searchSharedCalendarIdx(string keyword){

    for(int idx = 0; idx < sharedCalendarList.size(); ++idx)
        if(sharedCalendarList[idx].getCalendarName() == keyword)
            return idx;
    return -1;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::intoSharedCalendar(U user,
 string inputCalendarName, string inputPassWord){

    int scIdx = searchSharedCalendarIdx(inputCalendarName);

    // 일치하는 공유캘린더 없음
    if(!scIdx) return 0;

    // 패스워드 불일치
    if(sharedCalendarList[scIdx].getPassWord() != inputPassWord) return -1;

    // 성공
    return scIdx;
}

    
template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::joinSharedCalendar(U user, string inputCalendarName, string inputPassWord){
        
    int scIdx = intoSharedCalendar(user, inputCalendarName, inputPassWord);
    
    // 일치하는 공유캘린더 없음 0, 패스워드 불일치 -1
    if(scIdx < 1) return scIdx;

    // 정원 초과 -2
    if(!sharedCalendarList[scIdx].addMember(user)) return -2;

    // 성공
    return 1;
}

template<typename S, typename U, typename D>
void SharedCalendarManager<S, U, D>::showSharedCalendarList(){
    if(!sharedCalendarList.size()){
        cout << "공유캘린더가 존재하지 않습니다." << endl;
        return;
    }
    for(int i = 0; i < sharedCalendarList.size(); ++i)
        cout << sharedCalendarList[i].getCalendarID() << ") " << sharedCalendarList[i].getSharedCalendarName() << "\n";
    cout << endl;
}



/******************************파일 입출력 파트************************************/
template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>:: saveSharedCalendarList(){
    // to do : 현재 sharedCalendarList를 .txt파일로 저장한다.
    return 0;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>:: loadSharedCalendarList(){
    // to do : .txt파일을 sharedCalendarList로 불러온다.
    return 0;
}
