MenuInput::MenuInput(User user, SharedCalendarManager<Schedule, User, Date> scm)
 :user(user), scm(scm) { }

void MenuInput::mainMenu(){
    while(true){
        int a, b, c, d;

        a = whatCalendarDoYouWant();
        // 개인 캘린더 메뉴
        if(a == 1) { }
        // a에서 공유 캘린더 메뉴로 들어감.
        if(a == 2) b = sharedCalendarActions();
        // 종료
        if(a == 3) exit(0);
        
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
        if(b == 3) intoSC();
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
    if(stage < 0) return;

    if(stage == 5){
        scm.addSharedCalendar(user, scInfo[0], stoi(scInfo[2]), Date(20, 10, 24),
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
        scInfo.pop_back();
        createNewSc(scInfo, stage-1);
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
    if(stage < 0) return;

    if(stage == 3){
        if(scm.joinSharedCalendar(user, scInfo[0], scInfo[1]) != 1){
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
        scInfo.pop_back();
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

void MenuInput::intoSC(){
    cout << signInShardCalendar[0];
    showJoinedList();
    cout << signInShardCalendar[1];

    string input;
    getline(cin, input);

    check c = check();

    if(c.qCheck(input)) return;

    if(c.totalCheck(input, _NORMAL, scm.getSharedCalendarListSize()-1)){
        cout << err[0];
        intoSC();
    }

    if(stoi(input) < 0 || stoi(input) > scm.getSharedCalendarListSize()-1){
        cout << err[0];
        intoSC();
    }

    cout << "[" << scm.getSharedCalendarList()[stoi(input)].getSharedCalendarName()<<"기능선택]\n";
}   

// 공유캘린더를 삭제한다.
bool MenuInput::delSc(){ }


void MenuInput::showJoinedList(){
    for(SharedCalendar<Schedule, User, Date> sc : scm.getSharedCalendarList()){
        bool isMyCalendar = false;
        for(User m : sc.getMemberList())
            if(m.getUserId() == user.getUserId()){
                isMyCalendar = true;
                break;
            }
        if(isMyCalendar)
            cout << sc.getSharedCalendarName() << "\n";
    }
}