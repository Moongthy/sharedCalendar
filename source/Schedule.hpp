
/*************************일정 파트********************************/
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
                selection = stoi(input);
                if (selection <= 0 || selection > boundary)
                {
                    cout << err[0];
                    cout << calendarSelectionOption[7];
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
    cout << line << endl;
    show_Schedules(2020, 10);
    cout << line << endl;

    for(string s : calendarSelectionOption) cout << s;
    int selection = checkValidSelection(6);

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

    Schedule new_s = Schedule(title, newD, stoi(startTime), stoi(endTime), content, location, 100);
    scheduleList.push_back(new_s);
    system("cls");
    cout << addSchedulesString[7];
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule()
{
    cout << modifySchedulesString[0];
    string input;
    cin >> input;

    int input_id = stoi(input);

    int modify_id;

    for(int i = 0; i<scheduleList.size(); i++) {
        if(scheduleList[i].getID() == input_id) {
            modify_id = i;
            break;
        }
    }
    
    Schedule modSchedule = scheduleList[modify_id];

    for(string s : modifyScheduleOption) cout << s;
    int selection = checkValidSelection(6);

    switch (selection)
    {
    case 1:
        /* 제목수정 */
        modifyTitle(modSchedule);
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
        int hh = stoi(hhmm.substr(0,1));
        int mm = stoi(hhmm.substr(2,3));
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
        int hh = stoi(hhmm.substr(0,1));
        int mm = stoi(hhmm.substr(2,3));
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
    if((findCheck(yymmdd,"/") || findCheck(yymmdd,"-")) || yymmdd.length() >= 6) {
        if(yymmdd.length() >= 6 && yymmdd.length() <=8) {
            return 0;
        }
    }
    else if((yymmdd.length() < 6 && yymmdd.length() > 8)) {
        
        cout << err[0] << endl;;
        return 3;
    }
    else if( yymmdd.length() == 1 && yymmdd[0] == 'q') {
        //q를 입력했을 때 행동 수행
        //cout << "[날짜]에서 뒤로 갑니다.";
        return 1;
    }
    else if(yymmdd.length() ==1 && yymmdd[0] == ' ') {
        //공백을 입력했을 때 오류
        cout << err[0] << endl;
        return 2;
    }
}
int hhmmVaild(string hhmm) {
    if(hhmm.length() == 4) {

    }
    else if(hhmm.length() == 5) {
        if(hhmm[2] == '-' || hhmm[2] == '/' || hhmm[2] == ':') {
        }
        else {

        }
    }
    if(hhmm.length() > 5 || hhmm.length() < 4) {
        cout << err[0] << endl;
        return 2;
    }//string::npos 이면은 못찾은거임
    else if(findCheck(hhmm,"/") || findCheck(hhmm,"-") || hhmm.length() == 4 || hhmm.length() == 5) {
        //10.21 / 9시 20분 마지막 수정 부분
        return 0;
    }
    else if( hhmm.length() == 1 && hhmm[0] == 'q') {
        //q를 입력했을 때 행동 수행
        //cout << "[날짜]에서 뒤로 갑니다.";
        return 1;
    }
    else if(hhmm.length() ==1 && hhmm[0] == ' ') {
        //공백을 입력했을 때 오류
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
    string keyword;
    cin >> keyword;
    for (int i = 0; i < scheduleList.size(); i++)
    {
        string content = scheduleList[i].getTitle();
        if (content.find(keyword) != string::npos)
        {
            Date search = scheduleList[i].getDate();
            int s_yy = search.yy;
            int s_mm = search.mm;
            int s_dd = search.dd;

            cout << "제목 : " << scheduleList[i].getTitle() << endl;
            cout << "날짜 : " << s_yy << "년 " << s_mm << "월 " << s_dd << "일" << endl;
            cout << "시작시간 : " << scheduleList[i].getStartTime()%100 << "시 " << scheduleList[i].getStartTime()/100 << "분 " << endl;
            cout << "종료시간 : " << scheduleList[i].getEndTime()%100 << "시 " << scheduleList[i].getEndTime()/100 << "분 "<< endl;
            cout << "내용 : " << scheduleList[i].getContent() << endl;
            cout << "장소 : " << scheduleList[i].getLocation() << endl;
        }
    }
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
        }
        else {
            curr_month++;
        }
        curr_year++;
        show_Schedules(curr_year, curr_month);
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
        }
        else {
            curr_month--;
        }
        curr_year--;
        show_Schedules(curr_year, curr_month);
    }
}
