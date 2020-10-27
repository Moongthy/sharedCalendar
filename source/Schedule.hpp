
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
        cin >> input;
        if (input.length() != 1)
        {
            cout << "올바른 입력 형식이 아닙니다.\n";
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
                    cout << "올바른 입력 형식이 아닙니다.\n";
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
    cout << "[개인 캘린더]\n";
    show_Schedules(2020, 10);

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
        showNextMonthSchedules();
        break; 
    case 6:
        /* 다음 달 일정 */
        showPrevMonthSchedules();
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
        for (int i = 0; i < scheduleList.length(); i++)
        {
            Date search = scheduleList[i].getDate();
            int s_yy = search.yy;
            int s_mm = search.mm;
            int s_dd = search.dd;

            if(s_yy == curr_year && s_mm == curr_month) {
                cout << "제목 : " << scheduleList[i].getTitle() << endl;
                cout << "날짜 : " << s_yy << "년 " << s_mm << "월 " << s_dd << "일" << endl;
                cout << "시작시간 : " << scheduleList[i].getStartTime() << endl;
                cout << "종료시간 : " << scheduleList[i].getEndTime() << endl;
                cout << "내용 : " << scheduleList[i].getContent() << endl;
                cout << "장소 : " << scheduleList[i].getLocation() << endl;
            }


        }
    }
    else
    {
        cout << "해당 월에 스케줄이 없습니다!" << endl;
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::addSchedule()
{
    cout << "[일정 생성]\n";
    cout << "제목 > ";
    string title;
    do {
        cin >> title;
    } while(titleVaild(title) == 0);

    cout << "날짜 > ";
    string yymmdd;
    do {
        cin >> yymmdd;
    } while(hhmmVaild(yymmdd) == 0);

    //제목, 날짜, 시작시간, 종료시간, 장소, 내용
    cout << "시작시간 > ";
    string startTime;
    do {
        cin >> startTime;
    } while(hhmmVaild(yymmdd) == 0);

    cout << "종료시간 > ";
    string endTime;
    do {
        cin >> endTime;
    } while(hhmmVaild(yymmdd) == 0);    
        
    cout << "장소 > ";
    string location;
    do {
        cin >> location;
    } while(stringVaild(location) == 0);    

    cout << "내용 > ";
    string content;
    do {
        cin >> content;
    } while(stringVaild(content) == 0);

    Schedule(title, , startTime, endTime, content, location);
    //scheduleList.push_back(S(startDate, endDate, content));

    cout << "일정 생성에 성공하였습니다. > ";
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule(S schedule, U users, D date)
{
    cout << "[일정 수정]\n수정할 일정 ID >";
    string input_id;
    cin >> input_id;

    /**
     * 
     * ID 유효한지 검사
     * 
     **/

    for(string s : modifyScheduleOption) cout << s;
    int selection = checkValidSelection(6);

    switch (selection)
    {
    case 1:
        /* 제목수정 */
        //내부적으로 입력받게해야함
        modifyTitle(schedule);
        break;
    case 2:
        /* 날짜수정 */
        modifyDate();
        break;
    case 3:
        /* 시작시간 수정 */
        modifyTime();
        break;
    case 4:
        /* 종료시간 수정 */
        modifyTime();
        break; 
    case 5:
        /* 내용 수정 */
        modifyContent();
        break; 
    case 6:
        /* 장소 수정 */
        modifyLocation();
        break; 
    default:
        /* 오류 */
        break;
    }
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyTitle(S s, string title){
    int select;
    if( ( select = titleVaild(title) ) == 0) {
        s.setTitle(title);
        return 0;
    }
    return select;
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyDate(S s, string yymmdd){
    int select;
    if((select = dateVaild(yymmdd)) == 0) {
        Date new_date = Date(yymmdd);
        s.setDate(new_date);
    }
    return select;
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifySTime(S s, string hhmm){
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
int Calendar<S, U, D>::modifyETime(S s, string hhmm){
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
int Calendar<S, U, D>::modifyContent(S s, string content){
    int select;
    if( ( select = contentVaild(content) ) == 0) {
        s.setContent(content);
        return 0;
    }
    return select;
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyLocation(S s, string location) {
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
    if(title.length() >= 20 && title.length() < 1) {
        //문자 길이가 다를 때 오류
        cout << err[0] << endl;
        return 2;
    }
    else if( title.length() == 1 && title[0] == 'q') {
        //q를 입력했을 때 행동 수행
        //cout << "[제목]에서 뒤로 갑니다.";
        return 1;
    }
    else if(title.length() ==1 && title[0] == ' ') {
        //공백을 입력했을 때 오류
        cout << err[0] << endl;
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
    if(hhmm.length() > 5 && hhmm.length() < 4) {
        cout << err[0] << endl;
        return 2;
    }//string::npos 이면은 못찾은거임
    else if((findCheck(hhmm,"/") || (findCheck(hhmm,"-")) || (hhmm.length() == 4 || hhmm.length() == 5))) {
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
    if( contents.length() > 100 || contents.length() == 0 ) {
        cout << err[0] << endl;
        return 2;
    }
    else if (contents.length() == 1 && contents[0] == 'q') {
        return 1;
    }
    else return 0;
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::deleteSchedule(string keyword)
{
    // searchSchedule에서 vector에 추가 대신 원래 vector에서 pop해주면 될듯
    // pop 보다는 erase해주면 됩니다
}

template <typename S, typename U, typename D>
vector<S> &Calendar<S, U, D>::searchSchedule(string keyword)
{
    vector<S> SearchScheduleList;
    for (int i = 0; i < 1200; i++)
    {
        int len = scheduleList[i].length();
        for (int j = 0; j < len; j++)
        {
            string content = scheduleList[i][j].getTitle();
            if (content.find(keyword) != string::npos)
            {
                SearchScheduleList.push_back(scheduleList[i][j]);
            }
        }
    }
    return SearchScheduleList;
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::showNextMonthSchedules()
{
    if (ym_idx + 1 >= 1200)
    {
        // 다음 달이 없습니다
    }
    else
    {
        ym_idx++;
        show_Schedules(ym_idx);
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::showPrevMonthSchedules()
{
    if (ym_idx - 1 < 0)
    {
        // 이전 달이 없습니다
    }
    else
    {
        ym_idx--;
        show_Schedules(ym_idx);
    }
}
