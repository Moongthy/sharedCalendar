    
template<typename S, typename U, typename D>
SharedCalendarManager<S, U, D>::SharedCalendarManager(){};

template<typename S, typename U, typename D>
vector<SharedCalendar<S, U, D>> SharedCalendarManager<S, U, D>::getSharedCalendarList(){
    return sharedCalendarList;      
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::getSharedCalendarListSize(){
    return sharedCalendarList.size();
}

template<typename S, typename U, typename D>
void SharedCalendarManager<S, U, D>::addSharedCalendar(U user, string sharedCalendarName, string pw,
 int acceptable, D startDate, D endDate){
    sharedCalendarList.push_back(SharedCalendar<S, U, D>(user, std::to_string(sharedCalendarList.size() + 1000) , sharedCalendarName, pw, acceptable, startDate, endDate));
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::searchSharedCalendarIdx(string keyword){
    for(int idx = 0; idx < sharedCalendarList.size(); ++idx)
        if(sharedCalendarList[idx].getSharedCalendarName() == keyword)
            return idx;
    return -3;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::intoSharedCalendar(U user,
 string inputCalendarName, string inputPassWord){

    int scIdx = searchSharedCalendarIdx(inputCalendarName);

    // 일치하는 공유캘린더 없음
    if(scIdx < 0) return -2;

    // 패스워드 불일치
    if(sharedCalendarList[scIdx].getPassWord() != inputPassWord) {
        cout << sharedCalendarList[scIdx].getPassWord() << endl;
        return -1;
    }

    // 성공
    return scIdx;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::joinSharedCalendar(U user, string inputCalendarName, string inputPassWord){
        
    return intoSharedCalendar(user, inputCalendarName, inputPassWord);
    
    // 일치하는 공유캘린더 없음 -2, 패스워드 불일치 -1
    // if(scIdx < 0) return scIdx;

    // 정원 초과 -2
    // 기획서에 없음.
    // if(!sharedCalendarList[scIdx].addMember(user)) return -2;

    // 성공하면 해당 공캘 인덱스 반환.
    // return scIdx;
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
    ReadFile rf = ReadFile();

    // rf.clearSCList(); <---- 이거요

    for(SharedCalendar<S, U, D> sc : sharedCalendarList){
        
        string startDate = "", endDate = "";
        
        startDate = to_string(sc.getStartDate().yy) + to_string(sc.getStartDate().mm) + to_string(sc.getStartDate().dd);
        endDate = to_string(sc.getEndDate().yy) + to_string(sc.getEndDate().mm) + to_string(sc.getEndDate().dd);
        
        rf.writeSCList(sc.getSharedCalendarName(), sc.getPassWord(), startDate, endDate, sc.getCalendarAdministrator().getUserId());
    
    }
    return 0;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>:: loadSharedCalendarList(){

    // while(SCList 다 읽을 때 까지){

    //     User user : 읽어온 사용자 정보
    //     string sharedCalendarNaem : 읽어온 공캘 제목
    //     int acceptable : 읽어온 수용인원
    //     Date startDate : 읽어온 시작 날짜
    //     Date endDate : 읽어온 끝날짜

    //     sharedCalendarList.push_back(SharedCalendar<S, U, D>(user, sharedCalenarName, acceptable, startDate, endDate));
    // }

    return 0;
}


