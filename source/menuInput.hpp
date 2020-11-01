MenuInput::MenuInput(User user, SharedCalendarManager<Schedule, User, Date> scm)
 :user(user), scm(scm) { 
    //  cout << "MenuInput contructor" << endl;
    //  // 비어있으면 리턴
    // if(!scm.getSharedCalendarListSize()) return;
    
    //  // MenuInput이 생성되기 전에 이미 scm.sharedCalenarList는 이미 로드되어 있음.
    // int yy = scm.getSharedCalendarList()[0].curr_year;
    // int mm = scm.getSharedCalendarList()[0].curr_month;
    // int dd = scm.getSharedCalendarList()[0].curr_day;
    // Date currDate = Date(yy, mm, dd);

    //  // 유효기간 끝났으면 해당 공캘 폭파.
    //  for(int i = 0; i < scm.getSharedCalendarListSize(); ++i)
    //  {
    //     // 현재 날짜랑 유효기간 비교. 유효기간 지났으면 erase.
    //      if(currDate > scm.getSharedCalendarList()[i].getEndDate())
    //         scm.getSharedCalendarList().erase(scm.getSharedCalendarList().begin() + i);
    //  }
 }

#include"../header/Calendar.h"

void MenuInput::mainMenu(){
    while(true){
        int a , b , c = -1;
        a = whatCalendarDoYouWant();
        // 개인 캘린더 메뉴
        Calendar<Schedule, User, Date> personalCal = Calendar<Schedule, User, Date>(user);
        if(a == 1) {
            system("cls");
            personalCal.select_Schedules_option(user);
            system("cls");
        }
        // a에서 공유 캘린더 메뉴로 들어감.
        if(a == 2) b = sharedCalendarActions();
        // 종료
        if(a == 3) {
            // delete &scm;

            /************************************************************/
            //                     종료 되는 시점 임                       /
            /************************************************************/
            //personalCal;
            
            // sharedCalendarList.txt => SharedCalendarManager.hpp
            scm.saveSharedCalendarList();


            // 공유 캘린더 일정 저장
            // SharedCalendar/(calID).txt => Calendar.h
            // vector<SharedCalendar<Schedule, User, Date>> sc = scm.getSharedCalendarList();

            // for(auto sc : scm.getSharedCalendarList())
            // {
            //     sc.saveSharedScheduleList();
            // }

            // 개인 캘린더 일정 저장
            // (userID).txt => Calendar.h
            // personalCal.savePersonalScheduleList();
            // 스케줄 리스트 저장하는것.
            exit(0);
        }
        
        // 공유캘린더 생성
        if(b == 1){
            vector<string> scInfo;
            createNewSc(scInfo, _SCNAME);
        }
        // 공유캘린더 참가
        if(b == 2){
            vector<string> scInfo;
            joinSC(scInfo, _SCNAME);
        }
        /**********************************/
        // 공유캘린더 조회
        if(b == 3) 
        {   
            // 조회할 공유캘린더의 sharedCalendarList 인덱스
            int scIdx = intoSC();
            
            // 조회 실패
            if(scIdx < 0) {
                continue;
            }
            // 조회 할 공유 캘린더.
            SharedCalendar<Schedule, User, Date> sc = scm.getSharedCalendarList()[scIdx];
            //if(sc == NULL) {
              //  cout << choiceSharedCalendarAction[5];
            //}

            /*********************************************************/
            /*********************************************************/
            /*********************************************************/
            /********************일정 파트랑 연결***********************/

            // 0 리턴되면 이상 없이 진행
            // 1 리턴되면 
            // -1 리턴되면 삭제가 이미 된거! scIdx로 여기서 삭제
            int sReturn = sc.select_Schedules_option(user);
            
            if(sReturn == -1) {
                ReadFile rf;
                rf.clearSCScheList(sc.getCalendarID());
                scm.deleteSharedCalendar(user, scIdx);
            }

            /*********************************************************/
            /*********************************************************/
            /*********************************************************/
            /*********************************************************/

            // 이게 혹시 필요할까,,
            // if(!getIntoSpecifiedCalendar(scIdx))
            //     delSc(scIdx);
        }
    }
 }

 // 개인 캘린더 ? 공유 캘린더
int MenuInput::whatCalendarDoYouWant(){

    for(string s : choiceCalendarMenu) cout << s;
    
    // 입력 받음
    string input;
    getline(cin, input);

    check c = check();

    if(c.qCheck(input)) return -1;

    if(c.totalCheck(input, _NORMAL, 3)) return stoi(input);
    cout << err[0];

    return whatCalendarDoYouWant();
}

// 공캘에서 무엇을 하고싶니?
int MenuInput::sharedCalendarActions(){

    for(string s : choiceSharedCalendarAction) cout << s;

    string input;
    
    getline(cin, input);

    check c = check();

    if(c.qCheck(input)) return -1;

    if(c.totalCheck(input, _NORMAL, 3)) {
        if(input.empty()) {
            cout << err[0];
            return sharedCalendarActions();
        }
        return stoi(input);
    }

    cout << err[0];

    return sharedCalendarActions();

}

// 새로운 캘린더 정보를 입력받아 
// 새로운 캘린더를 만든다.
void MenuInput::createNewSc(vector<string>& scInfo, int stage){
    if(stage == 0) return;

    if(stage == 5){

        // cout << "see curr year" << endl;
        time_t curTime = time(NULL);
        struct tm *pLocal = localtime(&curTime);
        int yy = pLocal->tm_year + 1900;
        int mm = pLocal->tm_mon+1;
        int dd = pLocal->tm_mday;
        // cout << yy << mm << dd << "this is yymmdd" << endl;
        // int yy = scm.getSharedCalendarList()[0].curr_year;
        // int mm = scm.getSharedCalendarList()[0].curr_month;
        // int dd = scm.getSharedCalendarList()[0].curr_day;
        // cout << "see success" << endl;
        yy = yy%100;
        Date startDate = Date(yy, mm, dd);
        // cout << startDate.yy << startDate.mm << startDate.dd << "this is yymmdd2" << endl;
        
        scm.addSharedCalendar(user, scInfo[0], scInfo[1], stoi(scInfo[2]), startDate, Date(scInfo[3])) ;
        cout << inputCreateSharedCalendar[stage];
        return;
    }

    cout << inputCreateSharedCalendar[0];
    cout << inputCreateSharedCalendar[stage];

    string input;

    getline(cin, input);

    check c = check();
    // cout << "before q check" << endl;
    if(c.qCheck(input)){
        if(scInfo.size()) scInfo.pop_back();
        createNewSc(scInfo, stage-1);
        return;
    }

    // 공캘이 이미 있는 공캘이다?
    
    // cout << "before total Check1" << endl;
    if(stage == _SCNAME && c.totalCheck(input, stage, 0) && scm.searchSharedCalendarIdx(input) >= 0)
    {
        cout << err[0];
        createNewSc(scInfo, stage);
        return;
    }

    // cout << "before total Check2" << endl;
    if(!c.totalCheck(input, stage, 0)){
        cout << err[0];
        createNewSc(scInfo, stage);
        return;
    }

    // cout << "before total Check3" << endl;

    scInfo.push_back(input);
    createNewSc(scInfo, stage+1);
}

// 캘린더 이름과 비번을 입력받아
// 캘린더에 참가한다.
void MenuInput::joinSC(vector<string>& scInfo, int stage){
    if(stage == 0) return;

    if(stage == 3){
        int x = scm.joinSharedCalendar(user, scInfo[0], scInfo[1]); 
        if(x < 0){
            cout << scInfo[1] << endl;
            cout << err[1];
            return;
        }
        cout << inputJoinSharedCalendar[stage];
        cout << inputJoinSharedCalendar[stage+1];
        showJoinedList();
        return;
    }

    cout << inputJoinSharedCalendar[0];
    cout << inputJoinSharedCalendar[stage];

    string input;
    getline(cin, input);

    check c = check();

    if(c.qCheck(input)){
        if(scInfo.size()) scInfo.pop_back();
        joinSC(scInfo, stage-1);
        return;
    }

    if(!c.totalCheck(input, stage, 0)){
        cout << err[0];
        joinSC(scInfo, stage);
        return;
    }

    scInfo.push_back(input);
    joinSC(scInfo, stage+1);
}


int MenuInput::intoSC(){
    cout << signInShardCalendar[0];
    showJoinedList();
    cout << signInShardCalendar[1];

    string input;
    getline(cin, input);

    if(input.compare("\0")==0) {
        cout << err[0];
        return intoSC();
    }

    check c = check();

    if(c.qCheck(input)) return -1;

    if(!c.totalCheck(input, _SCSIZE, scm.getSharedCalendarListSize()) || stoi(input) == 0){ 
        cout << err[0];
        return intoSC();
    }
    if ( input.empty()) {
        cout << err[0];
        return intoSC();
    }
    return stoi(input) - 1;
}   

// 특정한 공유 캘린더를 선택 했을 때. -> 0.캘린더 제거!
int MenuInput::getIntoSpecifiedCalendar(int scIdx)
{
    
    cout << signInShardCalendar[2] << scm.getSharedCalendarList()[scIdx].getSharedCalendarName() <<
     signInShardCalendar[3];
    
    // 들어온 사람이 관리자라면
    if(user.getUserId() == scm.getSharedCalendarList()[scIdx].getMemberList()[0].getUserId())
        cout << choiceSpecifiedSharedCalendarAction[1];
    
    for(int i = 2; i < 8; ++i)
        cout << choiceSharedCalendarAction[i];


    cout << choiceSpecifiedSharedCalendarAction[2];

    string input;
    check c = check();

    getline(cin, input);

    if(c.qCheck(input)) return -1;
        
    return stoi(input);
}

// 공유캘린더를 삭제한다.
bool MenuInput::delSc(int scIdx){ 
    cout << delSharedCalenadr[0];
    cout << delSharedCalenadr[1];

    string input;
    check c = check();
    
    getline(cin, input);

    if(c.qCheck(input)) return true;

    if(input[0] == 'y' || input[0] == 'Y'){
        scm.deleteSharedCalendar(user, scIdx);
        delSharedCalenadr[3];
        return true;
    }

    if(input[0] == 'n' || input[0] == 'N') return false;

    cout << err[0];
    delSc(scIdx);
}

void MenuInput::showJoinedList(){
    int i = 0;  
    int calnum = 0;
    for(SharedCalendar<Schedule, User, Date> sc : scm.getSharedCalendarList()){
        bool isMyCalendar = false;
        for(User m : sc.getMemberList())
            if(m.getUserId() == user.getUserId()){
                isMyCalendar = true;
                break;
            }
        if(isMyCalendar) {
            cout << i+1 << " " << sc.getSharedCalendarName() << "\n";
            calnum++;
        }
        ++i;
    }
    // if(calnum == 0) cout << choiceSharedCalendarAction[5];
}