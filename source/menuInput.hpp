MenuInput::MenuInput(User user, SharedCalendarManager<Schedule, User, Date> scm)
 :user(user), scm(scm) { 

     // 비어있으면 리턴
    if(!scm.getSharedCalendarListSize()) return;

     // MenuInput이 생성되기 전에 이미 scm.sharedCalenarList는 이미 로드되어 있음.
    int yy = scm.getSharedCalendarList()[0].curr_year;
    int mm = scm.getSharedCalendarList()[0].curr_month;
    int dd = scm.getSharedCalendarList()[0].curr_day;
    Date currDate = Date(yy, mm, dd);

     // 유효기간 끝났으면 해당 공캘 폭파.
     for(int i = 0; i < scm.getSharedCalendarListSize(); ++i)
     {
        // 현재 날짜랑 유효기간 비교. 유효기간 지났으면 erase.
         if(currDate > scm.getSharedCalendarList()[i].getEndDate())
            scm.getSharedCalendarList().erase(scm.getSharedCalendarList().begin() + i);
     }
 }

#include"../header/Calendar.h"

void MenuInput::mainMenu(){

    // scm.showSharedCalendarList();

    while(true){

        int a , b , c = -1;

        a = whatCalendarDoYouWant();
        // 개인 캘린더 메뉴
        if(a == 1) { 
            Calendar<Schedule, User, Date> personalCal = Calendar<Schedule, User, Date>(user);
            personalCal.select_Schedules_option(user);
        }
        // a에서 공유 캘린더 메뉴로 들어감.
        if(a == 2) b = sharedCalendarActions();
        // 종료
        if(a == 3) {
            delete &scm;
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
            if(scIdx < 0) continue;
            
            SharedCalendar<Schedule, User, Date> sc = scm.getSharedCalendarList()[scIdx];

            /********************일정 파트랑 연결***********************/
            sc.select_Schedules_option(user);
            /*********************************************************/

            if(!getIntoSpecifiedCalendar(scIdx))
                delSc(scIdx);
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

    if(c.totalCheck(input, _NORMAL, 3)) return stoi(input);

    cout << err[0];

    return sharedCalendarActions();

}

// 새로운 캘린더 정보를 입력받아 
// 새로운 캘린더를 만든다.
void MenuInput::createNewSc(vector<string>& scInfo, int stage){
    if(stage == 0) return;

    if(stage == 5){

        int yy = scm.getSharedCalendarList()[0].curr_year;
        int mm = scm.getSharedCalendarList()[0].curr_month;
        int dd = scm.getSharedCalendarList()[0].curr_day;
        
        Date startDate = Date(yy, mm, dd);

        scm.addSharedCalendar(user, scInfo[0], scInfo[1], stoi(scInfo[2]), startDate,
         Date(stoi(scInfo[3].substr(0, 1)), stoi(scInfo[3].substr(2,3)), stoi(scInfo[3].substr(4,5))));
        cout << inputCreateSharedCalendar[stage];
        return;
    }

    cout << inputCreateSharedCalendar[0];
    cout << inputCreateSharedCalendar[stage];

    string input;

    getline(cin, input);

    check c = check();

    if(c.qCheck(input)){
        if(scInfo.size()) scInfo.pop_back();
        createNewSc(scInfo, stage-1);
        return;
    }

    // 공캘이 이미 있는 공캘이다?
    if(stage == _SCNAME && c.totalCheck(input, stage, 0) && scm.searchSharedCalendarIdx(input) >= 0)
    {
        cout << err[0];
        createNewSc(scInfo, stage);
        return;
    }

    if(!c.totalCheck(input, stage, 0)){
        cout << err[0];
        createNewSc(scInfo, stage);
        return;
    }

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
            // cout << x << endl;
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

    check c = check();

    if(c.qCheck(input)) return -1;

    if(!c.totalCheck(input, _SCSIZE, scm.getSharedCalendarListSize()) || stoi(input) == 0){ 
        cout << err[0];
        return intoSC();
    }

    return stoi(input) - 1;
}   

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
    for(SharedCalendar<Schedule, User, Date> sc : scm.getSharedCalendarList()){
        bool isMyCalendar = false;
        for(User m : sc.getMemberList())
            if(m.getUserId() == user.getUserId()){
                isMyCalendar = true;
                break;
            }
        if(isMyCalendar)
            cout << i+1 << " " << sc.getSharedCalendarName() << "\n";
        ++i;
    }
}