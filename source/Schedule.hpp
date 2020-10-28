/*************************일정 파트********************************/
bool isNumber(const string &str);
bool findCheck(string ss, string s);
bool boundaryCheck(string ss, int boundary);
int titleVaild(string title);
int dateVaild(string yymmdd);
int yymm_dateVaild(string yymmdd);
int hhmmVaild(string hhmm);
int hhmm_ahead_Vaild(string startTime, string endTime);
int contentVaild(string contents);
int locationVaild(string location);
void deleteCalendar();
bool admin = false;
int checkValidSelection(bool admin, int boundary)
{
    string input;
    int selection;
    check c = check();
    while (1)
    {
        cout << prompt;
        getline(cin, input);
        if (input.length() != 1)
        {
            cout << err[0];
        }
        else
        {
            if (c.qCheck(input))
            {
                // cout << "########q입력받음##########";
                return -2;
            }
            else
            {
                // cout << "!!!!!!!!!!여기까지됨!!!!!!!";
                if (input.size() == 1 && c.isOnlyNumber(input))
                {
                    // cout << "#########숫자인지 확인함#########";
                    selection = stoi(input);
                }
                else
                {
                    selection = -1;
                    return selection;
                }
                // 내가 관리자면
                if (admin)
                {
                    if (selection < 0 || selection > boundary)
                    {
                        cout << err[0];
                    }
                    // 내가 관리자가아니면
                }
                else if (!admin)
                {
                    if (selection <= 0 || selection > boundary)
                    {
                        cout << err[0];
                    }
                }

                return selection;
            }
        }
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::select_Schedules_option(U user)
{
    cout << myCalendar[0];
    cout << curr_year << ScheduleInfo[2] << curr_month << ScheduleInfo[3] << endl;
    show_Schedules(curr_year, curr_month);

    if (user.getUserId() == getCalendarAdministrator().getUserId())
    {
        cout << choiceSpecifiedSharedCalendarAction[1];
        admin = true;
    }

    for (string s : calendarSelectionOption)
        cout << s;

    int selection = checkValidSelection(admin, 6);

    if (selection < 0)
        return;

    system("cls");
    switch (selection)
    {
    case 0:
        /*캘린더 삭제 공유 캘린더 관리자만*/
        deleteCalendar();
        //deleteSharedCalendar(user, scIdx);
    case 1:
        /* 일정생성 */
        addSchedule(user);
        break;
    case 2:
        /* 일정수정 */
        modifySchedule(user);
        break;
    case 3:
        /* 일정삭제 */
        deleteSchedule();
        break;
    case 4:
        /* 일정검색 */
        searchSchedule(user);
        break;
    case 5:
        /* 이전 달 일정 */
        showPrevMonthSchedules(user);
        break;
    case 6:
        /* 다음 달 일정 */
        showNextMonthSchedules(user);
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
    if (scheduleList.size() != 0)
    {
        bool check = false;
        for (int i = 0; i < scheduleList.size(); i++)
        {
            Date search = scheduleList[i].getDate();
            int s_yy = search.yy;
            int s_mm = search.mm;
            int s_dd = search.dd;

            if (s_yy == curr_year && s_mm == curr_month)
            {
                check = true;
                cout << line << endl;
                cout << ScheduleInfo[0] << scheduleList[i].getTitle() << endl;
                cout << ScheduleInfo[1] << s_yy << ScheduleInfo[2] << s_mm << ScheduleInfo[3] << s_dd << ScheduleInfo[4] << endl;
                cout << ScheduleInfo[5] << scheduleList[i].getStartTime() / 100 << ScheduleInfo[6] << scheduleList[i].getStartTime() % 100 << ScheduleInfo[7] << endl;
                cout << ScheduleInfo[8] << scheduleList[i].getEndTime() / 100 << ScheduleInfo[6] << scheduleList[i].getEndTime() % 100 << ScheduleInfo[7] << endl;
                cout << ScheduleInfo[9] << scheduleList[i].getContent() << endl;
                cout << ScheduleInfo[10] << scheduleList[i].getLocation() << endl;
                cout << line << endl;
            }
        }
        if (!check)
        {
            cout << line << endl;
            cout << showSchedulesString[0];
            cout << line << endl;
        }
    }
    else
    {
        cout << line << endl;
        cout << showSchedulesString[0];
        cout << line << endl;
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::addSchedule(U user)
{
    cout << addSchedulesString[0];
    string title, yymmdd, startTime, endTime, location, content;
Title:
    do
    {
        cout << addSchedulesString[1];
        cin >> title;
        if (Check.qCheck(title))
        {
            select_Schedules_option(user);
            return;
        }
    } while (titleVaild(title) != 0);

Date:
    do
    {
        cout << addSchedulesString[2];
        cin >> yymmdd;
        if (Check.qCheck(yymmdd))
        {
            goto Title;
        }
    } while (dateVaild(yymmdd) != 0);
    Date newD = Date(yymmdd);

Stime:
    do
    {
        cout << addSchedulesString[3];
        cin >> startTime;
        if (Check.qCheck(startTime))
        {
            goto Date;
        }
    } while (hhmmVaild(startTime) != 0);

Etime:
    do
    {
        cout << addSchedulesString[4];
        cin >> endTime;
        if (Check.qCheck(endTime))
        {
            goto Stime;
        }
    } while (hhmm_ahead_Vaild(startTime, endTime) != 0);
Location:
    do
    {
        cout << addSchedulesString[5];
        cin >> location;
        if (Check.qCheck(location))
        {
            goto Etime;
        }
    } while (contentVaild(location) != 0);

Content:
    do
    {
        cout << addSchedulesString[6];
        cin >> content;
        if (Check.qCheck(content))
        {
            goto Location;
        }
    } while (contentVaild(content) != 0);

    Schedule new_s = Schedule(title, newD, stoi(startTime), stoi(endTime), content, location, maximum_id);
    maximum_id++;
    scheduleList.push_back(new_s);
    system("cls");
    cout << addSchedulesString[7];
    select_Schedules_option(user);
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::modify(U user)
{
    cout << modifyString[0];
    cout << curr_year << ScheduleInfo[2] << curr_month << ScheduleInfo[3] << endl;
    show_Schedules(curr_year, curr_month);
    cout << endl;
    cout << modifyString[1];
    cout << modifyString[2];
    string input;
    do
    {
        cout << prompt;
        cin >> input;
    } while (!Check.numberCheck(input, 2));
    int input_int = stoi(input);
    if (input_int == 1)
    {
        modifySchedule(user);
        return;
    }
    else if (input_int == 2)
    {
        string yymmdd;
        //여기 yy 네글자? 두글자?기획서 보자
        //yyyymm 받아서
        do
        {
            cout << prompt;
            cin >> yymmdd;
        } while (yymm_dateVaild(yymmdd) == 0)
            //기획서는 yymm 으로 받는데,
            //따로 vaild 체크해주기위해서는 함수가 필요함.
            //지금 그 함수 만들러 갑니다.
            yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
            yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());
            int yy = stoi(yymmdd.substr(0, 2));
            int mm = stoi(yymmdd.substr(2, 2));
            //curr_year, month 변경 후
            //여기 해야됨
            modify(user);
        return;
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule(U user)
{
    int modify_id;
    string input;
    do
    {
        do
        {
            cout << modifySchedulesString[0];
            cin >> input;
            if (Check.qCheck(input))
            {
                // q 동작 수행
                modify();
                return;
            }
        } while (!Check.isOnlyNumber(input));

        int input_id = stoi(input);
        modify_id = -1;

        for (int i = 0; i < scheduleList.size(); i++)
        {
            if (scheduleList[i].getID() == input_id)
            {
                modify_id = i;
                break;
            }
        }

        if (modify_id == -1)
        {
            cout << noID;
        }

    } while (modify_id == -1);

    // 포인터로 가져와야되지않나?

    Schedule modSchedule = &scheduleList[modify_id];

    for (string s : modifyScheduleOption)
        cout << s;
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
RetryYN:
    cout << modifySchedulesString[8];
    string yninput;
    cin >> input;
    if (input == "Y" || input == "y")
    {
        modifySchedule();
        return;
    }
    else if (input == "N" || input == "n")
    {
        select_Schedules_option();
        return;
    }
    else
    {
        cout << err[0];
        goto RetryYN;
    }
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyTitle(S &s)
{
    cout << modifySchedulesString[1];
    string title;
    cin >> title;
    int select;
    if ((select = titleVaild(title)) == 0)
    {
        s.setTitle(&title);
        return 0;
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyDate(S s)
{
    cout << modifySchedulesString[2];
    string yymmdd;
    cin >> yymmdd;
    int select;
    if ((select = dateVaild(yymmdd)) == 0)
    {
        Date new_date = Date(yymmdd);
        s.setDate(new_date);
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifySTime(S s)
{
    cout << modifySchedulesString[3];
    string hhmm;
    cin >> hhmm;
    int select;
    if ((select = hhmmVaild(hhmm)) == 0)
    {
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
        int hh = stoi(hhmm.substr(0, 2));
        int mm = stoi(hhmm.substr(2, 2));
        s.setEndTime(hh * 100 + mm);
        return 0;
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyETime(S s)
{
    cout << modifySchedulesString[4];
    string hhmm;
    cin >> hhmm;
    int select;
    if ((select = hhmmVaild(hhmm)) == 0)
    {
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
        int hh = stoi(hhmm.substr(0, 2));
        int mm = stoi(hhmm.substr(2, 2));
        s.setStartTime(hh * 100 + mm);
        return 0;
    }
    return select;
}
template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyContent(S s)
{
    cout << modifySchedulesString[6];
    string content;
    cin >> content;
    int select;
    if ((select = contentVaild(content)) == 0)
    {
        s.setContent(content);
        return 0;
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyLocation(S s)
{
    cout << modifySchedulesString[5];
    string location;
    cin >> location;
    int select;
    if ((select = contentVaild(location)) == 0)
    {
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
bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

bool findCheck(string ss, string s)
{
    int it = ss.find(s);
    if (it == string::npos)
    {
        return false;
    }
    else
        return true;
}

bool boundaryCheck(string ss, int boundary)
{
    int num;
    check c = check();
    if (c.isOnlyNumber(ss))
    {
        num = stoi(ss);
    }
    else
    {
        cout << err[0];
        return false;
    }

    if (0 < num && num < boundary)
    {
        return true;
    }
    else
    {
        cout << err[0];
        return false;
    }
}

int titleVaild(string title)
{
    if (title.length() > 20 || title.length() < 1)
    {
        //문자 길이가 다를 때 오류
        cout << err[0];
        return 2;
    }
    else if (title.length() == 1 && title[0] == 'q')
    {
        //q를 입력했을 때 행동 수행
        return 1;
    }
    else if (title.length() == 1 && title[0] == ' ')
    {
        //공백을 입력했을 때 오류
        cout << err[0];
        return 3;
    }
    else
    {
        return 0;
    }
}

int dateVaild(string yymmdd)
{
    yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
    yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());

    check C = check();

    if (C.isOnlyNumber(yymmdd))
    {
        if (yymmdd.length() == 6)
        {
            if ((1 <= stoi(yymmdd.substr(2, 2)) && stoi(yymmdd.substr(2, 2)) <= 12) && (1 <= stoi(yymmdd.substr(4, 2)) && stoi(yymmdd.substr(4, 2)) <= 31))
            {
                //달이 1월부터 12월까지 날이 1일부터 31일까지..ㅠㅠ
                return 0;
            }
        }
        else
        {
            cout << err[0];
            return 1;
        }
    }
    else if (C.qCheck(yymmdd))
    {
        cout << "뒤로가기...이거 바꿔조" << endl;
        return 1;
    }
    else
    {
        cout << err[0];
        return 2;
    }
}

int yymm_dateVaild(string yymmdd)
{
    yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
    yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());
    check C = check();
    if (yymmdd.length() == 4)
    {
        if ((1 <= stoi(yymmdd.substr(2, 2)) && stoi(yymmdd.substr(2, 2)) <= 12))
        {
            return 0;
        }
        else
        {
            cout << err[0];
            return 1;
        }
    }
    else if (C.qCheck(yymmdd))
    {
        //cout << "뒤로가기...이거 바꿔조" << endl;
        return 1;
    }
    else
    {
        cout << err[0];
        return 2;
    }
}
int hhmmVaild(string hhmm)
{
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), ':'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
    check C = check();
    if (C.isOnlyNumber(hhmm))
    {
        if (hhmm.length() == 4)
        {
            if ((0 <= stoi(hhmm.substr(0, 2)) && stoi(hhmm.substr(0, 2)) <= 23) && (0 <= stoi(hhmm.substr(2, 2)) && stoi(hhmm.substr(2, 2)) <= 59))
            {
                cout << "debugging : " << stoi(hhmm.substr(0, 1)) << ",,,," << stoi(hhmm.substr(2, 3)) << endl;
                // 시침은 00부터 23월까지 분침은 00~59까지..ㅠㅠ
                return 0;
            }
        }
        else
        {
            cout << err[0];
            return 1;
        }
    }
    else if (hhmm.length() == 1 && hhmm[0] == 'q')
    {
        cout << "뒤로가기...이거 바꿔조2" << endl;
        return 1;
    }
    else
    {
        cout << err[0];
        return 2;
    }
}

int hhmm_ahead_Vaild(string startTime, string hhmm)
{
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), ':'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());

    startTime.erase(std::remove(startTime.begin(), startTime.end(), '-'), startTime.end());
    startTime.erase(std::remove(startTime.begin(), startTime.end(), ':'), startTime.end());
    startTime.erase(std::remove(startTime.begin(), startTime.end(), '/'), startTime.end());
    check C = check();
    if (C.isOnlyNumber(hhmm))
    {
        if (hhmm.length() == 4)
        {
            if ((0 <= stoi(hhmm.substr(0, 2)) && stoi(hhmm.substr(0, 2)) <= 23) && (0 <= stoi(hhmm.substr(2, 2)) && stoi(hhmm.substr(2, 2)) <= 59))
            {
                //cout << "debugging : " << stoi(hhmm.substr(0,2)) <<",,,," << stoi(hhmm.substr(2,3)) << endl;
                // 시침은 00부터 23월까지 분침은 00~59까지..ㅠㅠ
                if (startTime > hhmm)
                {
                    cout << err[0];
                    return 3;
                }
                return 0;
            }
        }
        else
        {
            cout << err[0];
            return 1;
        }
    }
    else if (C.qCheck(hhmm))
    {
        //cout << "뒤로가기...이거 바꿔조2" << endl;
        return 1;
    }
    else
    {
        cout << err[0];
        return 2;
    }
}

int contentVaild(string contents)
{
    if (contents.length() > 100 || contents.length() == 0)
    {
        cout << err[0];
        return 2;
    }
    else if (contents.length() == 1 && contents[0] == 'q')
    {
        return 1;
    }
    else
        return 0;
}

void deleteCalendar()
{
    //SharedCalendarManager scm;
    //scm.deleteSharedCalendar(user,scIdx);
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::deleteS()
{
    cout << modifyString[0];
    cout << curr_year << ScheduleInfo[2] << curr_month << ScheduleInfo[3] << endl;
    show_Schedules(curr_year, curr_month);
    cout << endl;
    cout << modifyString[1];
    cout << modifyString[2];
    string input;
    
    do
    {
        cout << prompt;
        cin >> input;
    } while (!Check.numberCheck(input, 2));
    
    int input_int = stoi(input);
    if (input_int == 1)
    {
        deleteSchedule();
        return;
    }
    else if (input_int == 2)
    {
        string yymmdd;
        //여기 yy 네글자? 두글자?기획서 보자
        //yyyymm 받아서
        do
        {
            cout << promt;
            cin >> yymmdd;
        } while (yymm_dateVaild(yymmdd) == 0)
            //기획서는 yymm 으로 받는데,
            //따로 vaild 체크해주기위해서는 함수가 필요함.
            //지금 그 함수 만들러 갑니다.
            int yy = stoi(yymmdd.substr(0, 2));
            int mm = stoi(yymm)
            //curr_year, month 변경 후
            //여기 해야됨
            deleteS(user);
        return;
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::deleteSchedule()
{
    int modify_id;
    string input;
    do
    {
        do
        {
            cout << modifySchedulesString[0];
            cin >> input;
            if (Check.qCheck(input))
            {
                // q 동작 수행
                deleteS();
                return;
            }
        } while (!Check.isOnlyNumber(input));

        int input_id = stoi(input);
        modify_id = -1;

        for (int i = 0; i < scheduleList.size(); i++)
        {
            if (scheduleList[i].getID() == input_id)
            {
                modify_id = i;
                break;
            }
        }

        if (modify_id == -1)
        {
            cout << noID;
        }

    } while (modify_id == -1);

    // 포인터로 가져와야되지않나?

    Schedule modSchedule = scheduleList[modify_id];

deleteRetryYN:
    cout << modifySchedulesString[8];
    cin >> input;
    if (input == "Y" || input == "y")
    {
        modifySchedule();
        return;
    }
    else if (input == "N" || input == "n")
    {
        select_Schedules_option();
        return;
    }
    else
    {
        cout << err[0];
        goto deleteRetryYN;
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::searchSchedule(U user)
{
    cout << searchSchedulesString[0];
SearchTryAgain:
    cout << searchSchedulesString[3];
    string keyword;
    cin >> keyword;
    if (Check.qCheck(keyword))
    {
        select_Schedules_option(user);
        return;
    }
    if (keyword.length() < 2)
    {
        cout << err[0];
        goto TryAgain;
    }
    cout << searchSchedulesString[1];
    bool state = false;
    for (int i = 0; i < scheduleList.size(); i++)
    {
        string content = scheduleList[i].getTitle();
        if (content.find(keyword) != string::npos)
        {
            state = true;
            Date search = scheduleList[i].getDate();
            cout << line << endl;
            cout << ScheduleInfo[0] << scheduleList[i].getTitle() << endl;
            cout << ScheduleInfo[1] << search.yy << ScheduleInfo[2] << search.mm << ScheduleInfo[3] << search.dd << ScheduleInfo[4] << endl;
            cout << ScheduleInfo[5] << scheduleList[i].getStartTime() / 100 << ScheduleInfo[6] << scheduleList[i].getStartTime() % 100 << ScheduleInfo[7] << endl;
            cout << ScheduleInfo[8] << scheduleList[i].getEndTime() / 100 << ScheduleInfo[6] << scheduleList[i].getEndTime() % 100 << ScheduleInfo[7] << endl;
            cout << ScheduleInfo[9] << scheduleList[i].getContent() << endl;
            cout << ScheduleInfo[10] << scheduleList[i].getLocation() << endl;
            cout << line << endl;
        }
    }
    if (!state)
    {
        cout << line << endl;
        cout << searchSchedulesString[2];
        cout << line << endl;
        goto SearchTryAgain;
    }
    select_Schedules_option(user);
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::showNextMonthSchedules(U user)
{
    if (curr_year == 2069 && curr_month == 12)
    {
        //마지막 달
    }
    else
    {
        if (curr_month == 12)
        {
            curr_month = 1;
            curr_year++;
        }
        else
        {
            curr_month++;
        }
        select_Schedules_option(user);
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::showPrevMonthSchedules(U user)
{
    if (curr_year == 1970 && curr_month == 1)
    {
        //첫 달
    }
    else
    {
        if (curr_month == 1)
        {
            curr_month = 12;
            curr_year--;
        }
        else
        {
            curr_month--;
        }
        select_Schedules_option(user);
    }
}