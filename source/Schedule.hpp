
/*************************일정 파트********************************/
bool isNumber(const string& str);
bool findCheck(string ss,string s);
int titleVaild(string title);
int dateVaild(string yymmdd);
int hhmmVaild(string hhmm);
int contentVaild(string contents);
int locationVaild(string location);

int checkValidSelection(int boundary) {
    string input;
    int selection;
    while (1)
    {
        cout << prompt;
        cin >> input;
        if (input.length() != 1)
        {
            cout << err[0];
        }
        else
        {
            if (input == "q")
            {
                // q에 대한 처리
            }
            else
            {   
                if(isNumber(input)) {
                    selection = stoi(input);
                } else {
                    selection = -1;
                    return selection;
                }
                
                if (selection <= 0 || selection > boundary)
                {
                    cout << err[0];
                }
                else 
                {
                    return selection;
                }
            }
        }
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::select_Schedules_option()
{
    cout << myCalendar[0];
    cout << curr_year << ScheduleInfo[2] <<curr_month << ScheduleInfo[3] << endl;
    cout << line << endl;
    show_Schedules(curr_year, curr_month);
    cout << line << endl;

    for(string s : calendarSelectionOption) cout << s;
    int selection = checkValidSelection(6);
    system("cls");
    switch (selection)
    {
    case 1:
        /* 일정생성 */
        addSchedule();
        break;
    case 2:
        /* 일정수정 */
        modifySchedule();
        break;
    case 3:
        /* 일정삭제 */
        deleteSchedule();
        break;
    case 4:
        /* 일정검색 */
        searchSchedule();
        break; 
    case 5:
        /* 이전 달 일정 */
        showPrevMonthSchedules();
        break; 
    case 6:
        /* 다음 달 일정 */
        showNextMonthSchedules();
        break; 
    default:
        cout << err[0];
        /* 오류 */
        break;
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::show_Schedules(int curr_year, int curr_month)
{
    // struct tm curr_tm;
    // time_t curr_time = time(nullptr);

    // localtime_r(&curr_time, &curr_tm);
    // int curr_year = curr_tm.tm_year + 1900;
    // int curr_month = curr_tm.tm_mon + 1;

    if (scheduleList.size() != 0)
    {
        bool check = false;
        for (int i = 0; i < scheduleList.size(); i++)
        {
            Date search = scheduleList[i].getDate();
            int s_yy = search.yy;
            int s_mm = search.mm;
            int s_dd = search.dd;

            if(s_yy == curr_year && s_mm == curr_month) {
                check = true;
                cout << ScheduleInfo[0] << scheduleList[i].getTitle() << endl;
                cout << ScheduleInfo[1] << s_yy << ScheduleInfo[2] << s_mm << ScheduleInfo[3] << s_dd << ScheduleInfo[4] << endl;
                cout << ScheduleInfo[5] << scheduleList[i].getStartTime()/100 << ScheduleInfo[6] << scheduleList[i].getStartTime()%100 << ScheduleInfo[7] << endl;
                cout << ScheduleInfo[8] << scheduleList[i].getEndTime()/100 << ScheduleInfo[6] << scheduleList[i].getEndTime()%100 << ScheduleInfo[7] << endl;
                cout << ScheduleInfo[9] << scheduleList[i].getContent() << endl;
                cout << ScheduleInfo[10] << scheduleList[i].getLocation() << endl;
            }
            if(!check) cout << showSchedulesString[0];
        }
    }
    else
    {
        cout << showSchedulesString[0];
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::addSchedule()
{
    cout << addSchedulesString[0];
    string title, yymmdd, startTime, endTime, location, content;
    do {
        cout << addSchedulesString[1];
        cin >> title;
    } while(titleVaild(title) != 0);

    do {
        cout << addSchedulesString[2];
        cin >> yymmdd;
        cout << "debugging : "<< endl;
    } while(dateVaild(yymmdd) != 0);
    Date newD = Date(yymmdd);

    do {
        cout << addSchedulesString[3];
        cin >> startTime;
    } while(hhmmVaild(startTime) != 0);

    do {
        cout << addSchedulesString[4];
        cin >> endTime;
    } while(hhmmVaild(endTime) != 0);
        
    do {
        cout << addSchedulesString[5];
        cin >> location;
    } while(contentVaild(location) != 0);    

    do {
        cout << addSchedulesString[6];
        cin >> content;
    } while(contentVaild(content) != 0);

    Schedule new_s = Schedule(title, newD, stoi(startTime), stoi(endTime), content, location, maximum_id);
    maximum_id++;
    scheduleList.push_back(new_s);
    system("cls");
    cout << addSchedulesString[7];
    select_Schedules_option();
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule()
{
    int modify_id;
    string input;
    do {
        do {
            cout << modifySchedulesString[0];
            cin >> input;
            if(Check.qCheck(input)) {
                // q 동작 수행
            }
        } while(!Check.isOnlyNumber(input));

        int input_id = stoi(input);
        modify_id = -1;

        for(int i = 0; i<scheduleList.size(); i++) {
            if(scheduleList[i].getID() == input_id) {
                modify_id = i;
                break;
            }
        }

        if(modify_id == -1) {
            cout << noID;
        }

    } while(modify_id == -1);

    Schedule modSchedule = scheduleList[modify_id];

    for(string s : modifyScheduleOption) cout << s;
    int selection = checkValidSelection(6);

    switch (selection)
    {
    case 1:
        /* 제목수정 */
        modifyTitle(modSchedule);
        select_Schedules_option();
        break;
    case 2:
        /* 날짜수정 */
        modifyDate(modSchedule);
        break;
    case 3:
        /* 시작시간 수정 */
        modifySTime(modSchedule);
        break;
    case 4:
        /* 종료시간 수정 */
        modifyETime(modSchedule);
        break; 
    case 5:
        /* 내용 수정 */
        modifyContent(modSchedule);
        break; 
    case 6:
        /* 장소 수정 */
        modifyLocation(modSchedule);
        break; 
    default:
        /* 오류 */
        break;
    }
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyTitle(S &s){
    cout << modifySchedulesString[1];
    string title;
    cin >> title;
    int select;
    if( ( select = titleVaild(title) ) == 0) {
        s.setTitle(title);
        return 0;
    }
    return select;
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyDate(S &s){
    cout << modifySchedulesString[2];
    string yymmdd;
    cin >> yymmdd;
    int select;
    if((select = dateVaild(yymmdd)) == 0) {
        Date new_date = Date(yymmdd);
        s.setDate(new_date);
    }
    return select;
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifySTime(S s){
    cout << modifySchedulesString[3];
    string hhmm;
    cin >> hhmm;
    int select;
    if( ( select = hhmmVaild(hhmm) ) == 0) {
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
		hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
        int hh = stoi(hhmm.substr(0,2));
        int mm = stoi(hhmm.substr(2,2));
        s.setEndTime(hh*100+mm);
        return 0;
    } 
    return select;
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyETime(S s){
    cout << modifySchedulesString[4];
    string hhmm;
    cin >> hhmm;
    int select;
    if( ( select = hhmmVaild(hhmm) ) == 0) {
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
		hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
        int hh = stoi(hhmm.substr(0,2));
        int mm = stoi(hhmm.substr(2,2));
        s.setStartTime(hh*100+mm);
        return 0;
    }
    return select;
}
template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyContent(S s){
    cout << modifySchedulesString[6];
    string content;
    cin >> content;
    int select;
    if( ( select = contentVaild(content) ) == 0) {
        s.setContent(content);
        return 0;
    }
    return select;
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyLocation(S s) {
    cout << modifySchedulesString[5];
    string location;
    cin >> location;
    int select;
    if( ( select = contentVaild(location) ) == 0) {
        s.setLocation(location);
        return 0;
    }
    return select;
}

/*
오류 체크 함수(???Vaild)의 리턴 값 설명
0 : 정상 종료
1 : q 입력
2~ : 오류 출력
*/
bool isNumber(const string& str) {
    for(char const &c : str) {
        if(std::isdigit(c) == 0) return false;
    }
    return true;
}
bool findCheck(string ss, string s) {
    int it = ss.find(s);
    if(it == string::npos) {
        return false;
    }
    else return true;
}
int titleVaild(string title) {
    if(title.length() > 20 || title.length() < 1) {
        //문자 길이가 다를 때 오류
        cout << err[0];
        return 2;
    }
    else if(title.length() == 1 && title[0] == 'q') {
        //q를 입력했을 때 행동 수행
        return 1;
    }
    else if(title.length() == 1 && title[0] == ' ') {
        //공백을 입력했을 때 오류
        cout << err[0];
        return 3;
    }
    else {
        return 0;
    }
}
int dateVaild(string yymmdd) {
    yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
	yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());

    if(isNumber(yymmdd)) {
        if(yymmdd.length() == 6) {
            if( (1<= stoi(yymmdd.substr(2,2)) && stoi(yymmdd.substr(2,2)) <= 12) && (1<= stoi(yymmdd.substr(4,2)) && stoi(yymmdd.substr(4,2)) <= 31) ) {
                //달이 1월부터 12월까지 날이 1일부터 31일까지..ㅠㅠ
                return 0;
            }
        } else {
            cout << err[0] << endl;
            return 1;
        }
        
    }else if(yymmdd.length() == 1 && yymmdd[0] == 'q') {
        cout << "뒤로가기...이거 바꿔조" << endl;
        return 1;
    } else {
        cout << err[0] << endl;
        return 2;
    }
}
int hhmmVaild(string hhmm) {
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), ':'), hhmm.end());
	hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
    if(isNumber(hhmm)) {
        if(hhmm.length() == 4) {
            if( (0<= stoi(hhmm.substr(0,2)) && stoi(hhmm.substr(0,2)) <= 23) && (0<= stoi(hhmm.substr(2,2)) && stoi(hhmm.substr(2,2)) <= 59) ) {
                cout << "debugging : " << stoi(hhmm.substr(0,1)) <<",,,," << stoi(hhmm.substr(2,3)) << endl;
                // 시침은 00부터 23월까지 분침은 00~59까지..ㅠㅠ
                return 0;
            }
        } else {
            cout << err[0] << endl;
            return 1;
        }
        
    }else if(hhmm.length() == 1 && hhmm[0] == 'q') {
        cout << "뒤로가기...이거 바꿔조2" << endl;
        return 1;
    } else {
        cout << err[0] << endl;
        return 2;
    }
}
int contentVaild(string contents) {
    if(contents.length() > 100 || contents.length() == 0) {
        cout << err[0] << endl;
        return 2;
    }
    else if (contents.length() == 1 && contents[0] == 'q') {
        return 1;
    }
    else return 0;
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::deleteSchedule()
{
    string keyword;
    cin >> keyword;
    // searchSchedule에서 vector에 추가 대신 원래 vector에서 pop해주면 될듯
    // pop 보다는 erase해주면 됩니다
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::searchSchedule()
{
TryAgain:
    cout << searchSchedulesString[0];
    string keyword;
    cin >> keyword;
    cout << searchSchedulesString[1];
    bool state = false;
    for (int i = 0; i < scheduleList.size(); i++)
    {
        string content = scheduleList[i].getTitle();
        if (content.find(keyword) != string::npos)
        {
            state = true;
            Date search = scheduleList[i].getDate();
            int s_yy = search.yy;
            int s_mm = search.mm;
            int s_dd = search.dd;

            cout << ScheduleInfo[0] << scheduleList[i].getTitle() << endl;
            cout << ScheduleInfo[1] << s_yy << ScheduleInfo[2] << s_mm << ScheduleInfo[3] << s_dd << ScheduleInfo[4] << endl;
            cout << ScheduleInfo[5] << scheduleList[i].getStartTime()/100 << ScheduleInfo[6] << scheduleList[i].getStartTime()%100 << ScheduleInfo[7] << endl;
            cout << ScheduleInfo[8] << scheduleList[i].getEndTime()/100 << ScheduleInfo[6] << scheduleList[i].getEndTime()%100 << ScheduleInfo[7] << endl;
            cout << ScheduleInfo[9] << scheduleList[i].getContent() << endl;
            cout << ScheduleInfo[10] << scheduleList[i].getLocation() << endl;
        }
    }
    if(!state) {
        cout << searchSchedulesString[2];
        goto TryAgain;
    }
    select_Schedules_option();
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::showNextMonthSchedules()
{
    if(curr_year == 2069 && curr_month == 12) {
        //마지막 달    
    } 
    else {
        if(curr_month == 12) {
            curr_month = 1;
            curr_year++;
        }
        else {
            curr_month++;
        }
        select_Schedules_option();
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::showPrevMonthSchedules()
{
    if(curr_year == 1970 && curr_month == 1) {
        //첫 달    
    } 
    else {
        if(curr_month == 1) {
            curr_month = 12;
            curr_year--;
        }
        else {
            curr_month--;
        }
        select_Schedules_option();
    }
}
