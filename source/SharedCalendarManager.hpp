    
template<typename S, typename U, typename D>
SharedCalendarManager<S, U, D>::SharedCalendarManager(){
    // loadSharedCalendarList();
    cout << "scm Constructor" << endl;
};

template<typename S, typename U, typename D>
SharedCalendarManager<S, U, D>::~SharedCalendarManager(){
    
    cout << "scm Destructor" << endl;
    // for(SharedCalendar<S, U, D> sc : sharedCalendarList)
    // {
    //     delete &sc;
    // }

    // saveSharedCalendarList();
};

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
     cout << "addSharedCalendar" << endl;
    sharedCalendarList.push_back(SharedCalendar<S, U, D>(user, std::to_string(sharedCalendarList.size()+1) , sharedCalendarName, pw, acceptable, startDate, endDate));
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::searchSharedCalendarIdx(string keyword){
    for(int idx = 0; idx < sharedCalendarList.size(); ++idx)
        if(sharedCalendarList[idx].getSharedCalendarName().find(keyword) != string::npos)
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
        // cout << sharedCalendarList[scIdx].getPassWord() << endl;
        return -1;
    }

    // 이미 참여됨
    for(int i = 0; i < sharedCalendarList[scIdx].getMemberList().size(); ++i)
        if(sharedCalendarList[scIdx].getMemberList()[i].getUserId() == user.getUserId())
            return -3;

    // 성공
    return scIdx;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::joinSharedCalendar(U user, string inputCalendarName, string inputPassWord){
        
    int ret = intoSharedCalendar(user, inputCalendarName, inputPassWord);

    if(ret < 0) return ret;

    sharedCalendarList[ret].addMember(user);

    return ret;
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
        cout << "there are no sharedCalendar" << endl;
        return;
    }
    for(int i = 0; i < sharedCalendarList.size(); ++i)
        cout << sharedCalendarList[i].getCalendarID() << ") " << sharedCalendarList[i].getSharedCalendarName() << "\n";
    cout << endl;
}

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>::deleteSharedCalendar(U user, int scIdx){
    if(scIdx < 0 || scIdx > sharedCalendarList.size()-1) return 0;
    sharedCalendarList.erase(sharedCalendarList.begin()+scIdx);
    return 1;
}

/******************************파일 입출력 파트************************************/
template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>:: saveSharedCalendarList(){
    
    ReadFile rf = ReadFile();
    
    rf.clearSCList();
    cout << "end ClearSCList" << endl;
    for(SharedCalendar<S, U, D> sc : sharedCalendarList){
        
        string startDate = "201025", endDate = "201231";
        
        // startDate = to_string(sc.getStartDate().yy) + to_string(sc.getStartDate().mm) + to_string(sc.getStartDate().dd);
        // endDate = to_string(sc.getEndDate().yy) + to_string(sc.getEndDate().mm) + to_string(sc.getEndDate().dd);
        cout << "write " + sc.getCalendarID() + " SCList " << endl;
        rf.writeSCList(sc.getSharedCalendarName(), sc.getPassWord(), startDate, endDate, sc.getCalendarAdministrator().getUserId());

        cout << "write " + sc.getCalendarID() + " SCMember" << endl;

        for(int i = 1; i < sc.getMemberList().size(); ++i){
            cout << sc.getMemberList()[i].getUserId() << endl;
            rf.writeSCMember(sc.getSharedCalendarName(), sc.getMemberList()[i].getUserId());
        }
        cout << sc.getCalendarID() << "save success" << endl;
    }
    return 0;
}

#include<cstring>
#include"../header/type/Schedule.h"

template<typename S, typename U, typename D>
int SharedCalendarManager<S, U, D>:: loadSharedCalendarList(){
    cout << "in loadScharedCalendar List" << endl;
    ReadFile rf = ReadFile();

    cout << "getSCList in loadSharedCalendarList" << endl;
    vector<string> FileSCList = rf.getSCList();

    cout << "getSCList in getUserIdName" << endl;
    // User ID랑 이름이랑 같이 불러오는 것 필요.
    vector<User> userList = rf.getUserIdName();

    // for(User u : userList)
    //     cout << u.getUserId() << " " << u.getUserName() << endl;

    // SCdata는 라인별 내용이다,,, 
    int i=0;
    cout << "iterative start in load" << endl;
    for(i=0; i<FileSCList.size(); i++){
    
        vector<string> calData;
        // cout << FileSCList[i] << endl;

        // $을 기준으로 토큰 분리
        char* token = strtok((char*)FileSCList[i].c_str(), "$");
        calData.push_back(token);

        // 계속 존나 분리.
        while(true){
            token = strtok(NULL, "$");
            if(token == NULL) break;
            calData.push_back(string(token));
        }
        cout << "cal Id : " << calData[0] << endl;
        cout << "cal Name : " << calData[1] << endl;
        cout << "cal Pw : " << calData[2] << endl;
        cout << "cal sDate : " << calData[3] << endl;
        cout << "cal eDate : " << calData[4] << endl;

        // calData[0] = calId

        // calData[1] = calName;

        // calData[2] = calPw;

        // calData[3] = startDate

        // calData[4] = endDate;

        // calData[5] = admin
        
        // startDate와 endDate불러옴 
        D startDate(calData[3]);
        D endDate(calData[4]);

        
        int adminIdx = -1;
        
        // 저장된 관리자Id의 관리자Name을 찾는다.
        cout << "find adminId" << endl;
        for(int i = 0; i < userList.size(); ++i){
            if(userList[i].getUserId() == calData[5]){
                adminIdx = i;
                break;
            }
        }

        // if(adminIdx < 0){
        //     continue;
        // }
        
        cout << "sharedClaendar create" << endl;
        cout << "admin Id : " << userList[adminIdx].getUserId() << endl;

        SharedCalendar<S, U, D> sc = SharedCalendar<S, U, D>(userList[adminIdx], calData[0], calData[1], calData[2], 5, startDate, endDate);

        cout << "add members" << endl;
        // 저장된 멤버들 추가
        for(int i = 6; i <= calData.size(); ++i){
            for(User u : userList){
                if(u.getUserId() == calData[i]){
                    sc.addMember(u);
                    break;
                }
            }
        }        
        cout << "add SC" << endl;
        sharedCalendarList.push_back(sc);

        // showSharedCalendarList();
    }

    return 0;
}


