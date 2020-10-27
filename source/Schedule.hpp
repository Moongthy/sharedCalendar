
/*************************일정 파트********************************/
#define endl '\n'

template <typename S, typename U, typename D>
void Calendar<S, U, D>::select_Schedules_option()
{
    cout << "[개인 캘린더]\n";
    show_Schedules(ym_idx);

    for(string s : calendarSelectionOption) cout << s;
    string selection;
    cin >> selection;

    if(selection.length()!=1) {
        cout << "올바른 입력 형식이 아닙니다.\n";
    }
    else {
        if(selection == "q") {
            // q에 대한 처리
        }
        else {
            selection = stoi(selection);
            if(selection <= 0 || selection > 6) {
                cout << "올바른 입력 형식이 아닙니다.\n";   
            }
        }
    }
    
    /**
     *  selection에 대한 오류처리
     */

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
void Calendar<S, U, D>::show_Schedules(int ym_idx)
{
    if (scheduleList[ym_idx].length() != 0)
    {
        for (int i = 0; i < scheduleList[ym_idx].length(); i++)
        {
            D search = scheduleList[ym_idx][i].getDate();
            int s_yy = D.yy;
            int s_mm = D.mm;
            int s_dd = D.dd;

            cout << "제목 : " << scheduleList[ym_idx][i].getTitle() << endl;
            cout << "날짜 : " << s_yy << "년 " << s_mm << "월 " << s_dd << "일" << endl;
            cout << "시작시간 : " << scheduleList[ym_idx][i].getStartTime() << endl;
            cout << "종료시간 : " << scheduleList[ym_idx][i].getEndtime() << endl;
            cout << "내용 : " << scheduleList[ym_idx][i].getContent() << endl;
            cout << "장소 : " << scheduleList[ym_idx][i].getLocation() << endl;
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
    Schedule new_schedule = new Schedule();

    //제목, 날짜, 시작시간, 종료시간, 장소, 내용

    //scheduleList.push_back(S(startDate, endDate, content));
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule()
{
    cout << "[일정 수정]\n수정할 일정 ID >";
    string input_id;
    cin >> input_id;


    for(string s : modifyScheduleOption) cout << s;
    string selection;
    cin >> selection;


    /**
     *  selection에 대한 오류처리
     */

    switch (selection)
    {
    case 1:
        /* 제목수정 */
        modifyTitle();
        break;
    case 2:
        /* 날짜수정 */
        modifyDate();
        break;
    case 3:
        /* 시작시간 수정 */
        modifySTime();
        break;
    case 4:
        /* 종료시간 수정 */
        modifyETime();
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
    //id로 수정하는건데
    //parameter 수정 필요
    //수정하는 항목 별로 있음 항목별로 함수 만들어야함.
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyTitle(S s, string title){
    if(title.length() >= 20 && title.length() < 1) {
        cout << "1~20자의 제목을 입력해주세요."
        return 3;
    }
    else if( title.length() == 1 && title[0] == 'q') {
        //q를 입력했을 때 행동 수행
        return 2;
    }
    else {
        s.setTitle(title);
        return 1;
    }
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyDate(string hhmm){
    if(title.length() >= 20 && title.length() < 1) {
        cout << "1~20자의 제목을 입력해주세요."
        return 3;
    }
    else if( title.length() == 1 && title[0] == 'q') {
        //q를 입력했을 때 행동 수행
        return 2;
    }
    else {
        s.setTitle(title);
        return 1;
    }
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifySTime(){
    
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyETime(){
    
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyContent(){
    
}

template<typename S, typename U, typename D>
int Calendar<S, U, D>::modifyLocation(){
    
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