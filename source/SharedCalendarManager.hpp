    
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
void SharedCalendarManager<S, U, D>::addSharedCalendar(U user, string sharedCalendarName,
 int acceptable, D startDate, D endDate){

    sharedCalendarList.push_back(SharedCalendar<S, U, D>(user, std::to_string(sharedCalendarList.size() + 1000) , sharedCalendarName,acceptable, startDate, endDate));
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::searchSharedCalendarIdx(string keyword){
    for(int idx = 0; idx < sharedCalendarList.size(); ++idx)
        if(sharedCalendarList[idx].getSharedCalendarName().find(keyword) != string::npos)
            return idx;
    return -1;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::intoSharedCalendar(U user,
 string inputCalendarName, string inputPassWord){

    int scIdx = searchSharedCalendarIdx(inputCalendarName);

    // 일치하는 공유캘린더 없음
    if(scIdx < 0) return 0;

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
    ReadFile rf = ReadFile();
    
    rf.clearSCList();

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
    ReadFile rf = ReadFile();
    vector<string> FileSCList = rf.getSCList();
    int i, separatorIndex;

    string id, SCName, password, startDate, endDate, member;
    for(string SCdata : FileSCList){
        SharedCalendar<S, U, D> SC;
        separatorIndex = 0;
        id="", SCName="", password="", startDate="", endDate="", member="";
        for(i=0; i<SCdata.length(); i++){
            if(SCdata[i]=='$' || i==SCdata.length()) {
                if(separatorIndex==5) {
                    member+=SCdata[i];
                    SC.SharedCalendar(member, id, password, SCName, startDate, endDate);
                }
                else if(separatorIndex>=6) SC.addMember(member);
                separatorIndex++;
                member="";
            }
            else if(separatorIndex==0) id+=SCdata[i];
            else if(separatorIndex==1) SCName+=SCdata[i];
            else if(separatorIndex==2) password+=SCdata[i];
            else if(separatorIndex==3) startDate+=SCdata[i];
            else if(separatorIndex==4) endDate+=SCdata[i];
            else if(separatorIndex>=5) member+=SCdata[i];
        }
        cout << member << endl;
        sharedCalendarList.push_back(SC);
    }
    return 0;
}
