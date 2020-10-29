/*************************일정 파트********************************/
bool isNumber(const string &str);
bool findCheck(string ss, string s);
bool boundaryCheck(string ss, int boundary);
int titleVaild(string title);
int dateVaild(string yymmdd);
int yymm_dateVaild(string yymmdd);
int hhmmVaild(string hhmm);
int hhmm_ahead_Vaild(int startTime, string endTime);
int contentVaild(string contents);
int locationVaild(string location);
void deleteCalendar();
bool admin = false;
int checkValidSelection(bool admin, int boundary)
{
    string input;
    int selection;
    check c = check();
    bool status = false;
    while (1)
    {
        if(status) cout << err[0];
        status = true;
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
                return -2;
            }
            else
            {
                if (input.size() == 1 && c.isOnlyNumber(input))
                {
                    selection = stoi(input);
                    if (admin)
                    {
                        if (selection >= 0 && selection <= boundary)
                        {
                            return selection;
                        }
                    }
                    else
                    {
                        if (selection > 0 && selection <= boundary)
                        {
                            return selection;
                        }
                    }
                    cout << err[0];
                }
            }
        }
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::select_Schedules_option(U user)
{
    if (!isShared)
        cout << myCalendar[0];
    else
        cout << myCalendar[1];
    /*
        시간 설정
    */
    cout << curr_year << ScheduleInfo[2] << curr_month << ScheduleInfo[3] << endl;
    show_Schedules(curr_year, curr_month);

    if (isShared && user.getUserId() == getCalendarAdministrator().getUserId())
    {
        admin = true;
    }

    for (int i = 0; i < 8; i++)
    {
        if (i == 1)
        {
            if (admin)
                cout << calendarSelectionOption[i];
        }
        else
        {
            cout << calendarSelectionOption[i];
        }
    }

    int selection = checkValidSelection(admin, 6);
    if (selection == -2)
    {
        // q기능 수행
        // 캘린더 선택으로 가야함
    }

    system("cls");
    switch (selection)
    {
    case 0:
        /*캘린더 삭제 공유 캘린더 관리자만*/
        if (admin)
        {
            deleteCalendar();
        }
        else
        {
            cout << err[0];
        }
        break;
    case 1:
        /* 일정생성 */
        addSchedule(user);
        break;
    case 2:
        /* 일정수정 */
        modify(user);
        break;
    case 3:
        /* 일정삭제 */
        deleteS(user);
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
                cout << ScheduleInfo[11] << scheduleList[i].getID() << endl;
                cout << ScheduleInfo[0] << scheduleList[i].getTitle() << endl;
                cout << ScheduleInfo[1] << s_yy << ScheduleInfo[2] << s_mm << ScheduleInfo[3] << s_dd << ScheduleInfo[4] << endl;
                cout << ScheduleInfo[5] << scheduleList[i].getStartTime() / 100 << ScheduleInfo[6] << scheduleList[i].getStartTime() % 100 << ScheduleInfo[7] << endl;
                cout << ScheduleInfo[8] << scheduleList[i].getEndTime() / 100 << ScheduleInfo[6] << scheduleList[i].getEndTime() % 100 << ScheduleInfo[7] << endl;
                cout << ScheduleInfo[10] << scheduleList[i].getLocation() << endl;
                cout << ScheduleInfo[9] << scheduleList[i].getContent() << endl;
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
        getline(cin, title);
        if (Check.qCheck(title))
        {
            system("cls");
            select_Schedules_option(user);
            return;
        }
    } while (titleVaild(title) != 0);

Date:
    do
    {
        cout << addSchedulesString[2];
        getline(cin, yymmdd);
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
        getline(cin, startTime);
        if (Check.qCheck(startTime))
        {
            goto Date;
        }
    } while (hhmmVaild(startTime) != 0);

    startTime.erase(std::remove(startTime.begin(), startTime.end(), '-'), startTime.end());
    startTime.erase(std::remove(startTime.begin(), startTime.end(), ':'), startTime.end());
    startTime.erase(std::remove(startTime.begin(), startTime.end(), '/'), startTime.end());

Etime:
    do
    {
        cout << addSchedulesString[4];
        getline(cin, endTime);
        if (Check.qCheck(endTime))
        {
            goto Stime;
        }
    } while (hhmm_ahead_Vaild(stoi(startTime), endTime) != 0);

    endTime.erase(std::remove(endTime.begin(), endTime.end(), '-'), endTime.end());
    endTime.erase(std::remove(endTime.begin(), endTime.end(), ':'), endTime.end());
    endTime.erase(std::remove(endTime.begin(), endTime.end(), '/'), endTime.end());

Location:
    do
    {
        cout << addSchedulesString[5];
        getline(cin, location);
        if (Check.qCheck(location))
        {
            goto Etime;
        }
    } while (contentVaild(location) != 0);

Content:
    do
    {
        cout << addSchedulesString[6];
        getline(cin, content);
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
    system("cls");
    cout << modifyString[0];
    cout << curr_year << ScheduleInfo[2] << curr_month << ScheduleInfo[3] << endl;
    show_Schedules(curr_year, curr_month);
    cout << modifyString[1];
    cout << modifyString[2];
    string input;
    bool status = false;
    do
    {
        if(status) cout << err[0];
        status = true;
        cout << prompt;
        getline(cin, input);
        if (Check.qCheck(input))
        {
            system("cls");
            select_Schedules_option(user);
            return;
        }
    } while (!(input=="1" || input =="2"));

    int input_int = stoi(input);
    if (input_int == 1)
    {
        modifySchedule(user);
        return;
    }
    else if (input_int == 2)
    {
        cout << modifyString[3];
        string yymm;
        do
        {
            cout << prompt;
            getline(cin, yymm);
            if (Check.qCheck(yymm))
            {
                system("cls");
                modify(user);
                return;
            }
        } while (yymm_dateVaild(yymm) != 0);

        yymm.erase(std::remove(yymm.begin(), yymm.end(), '-'), yymm.end());
        yymm.erase(std::remove(yymm.begin(), yymm.end(), '/'), yymm.end());
        int yy = stoi(yymm.substr(0, 2));
        int mm = stoi(yymm.substr(2, 2));
        if (0 <= yy && yy < 70) yy += 2000;
		else if (70 <= yy && yy < 100) yy += 1900;
        curr_year = yy;
        curr_month = mm;
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
            cout << prompt;
            getline(cin, input);
            if (Check.qCheck(input))
            {
                system("cls");
                modify(user);
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

ModifyRetry:
    for (string s : modifyScheduleOption)
        cout << s;

    int selection = checkValidSelection(admin, 6);
    if(selection == -2)
    {
        modifySchedule(user);
        return;
    }
    switch (selection)
    {
    case 1:
        /* 제목수정 */
        modifyTitle(modify_id);
        break;
    case 2:
        /* 날짜수정 */
        modifyDate(modify_id);
        break;
    case 3:
        /* 시작시간 수정 */
        modifySTime(modify_id);
        break;
    case 4:
        /* 종료시간 수정 */
        modifyETime(modify_id);
        break;
    case 5:
        /* 내용 수정 */
        modifyContent(modify_id);
        break;
    case 6:
        /* 장소 수정 */
        modifyLocation(modify_id);
        break;
    default: 
        {
            cout << err[0];
        }
        /* 오류 */
        return;
        break;
    }
RetryYN:
    cout << modifySchedulesString[8];
    string yninput;
    getline(cin, input);
    if (input == "Y" || input == "y")
    {
        goto ModifyRetry;
    }
    else if (input == "N" || input == "n")
    {
        system("cls");
        select_Schedules_option(user);
        return;
    }
    else
    {
        cout << err[0];
        goto RetryYN;
    }
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyTitle(int mod_id)
{
    cout << modifySchedulesString[1];
    string title;
    getline(cin, title);
    int select;
    if ((select = titleVaild(title)) == 0)
    {
        scheduleList[mod_id].setTitle(title);
        return 0;
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyDate(int mod_id)
{
    cout << modifySchedulesString[2];
    string yymmdd;
    getline(cin, yymmdd);
    int select;
    if ((select = dateVaild(yymmdd)) == 0)
    {
        Date new_date = Date(yymmdd);
        scheduleList[mod_id].setDate(new_date);
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifySTime(int mod_id)
{
    cout << modifySchedulesString[3];
    string hhmm;
    getline(cin, hhmm);
    int select;
    if ((select = hhmmVaild(hhmm)) == 0)
    {
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
        int hh = stoi(hhmm.substr(0, 2));
        int mm = stoi(hhmm.substr(2, 2));
        scheduleList[mod_id].setEndTime(hh * 100 + mm);
        return 0;
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyETime(int mod_id)
{
    cout << modifySchedulesString[4];
    string hhmm;
    getline(cin, hhmm);
    int select;
    if ((select = hhmm_ahead_Vaild(scheduleList[mod_id].getEndTime(), hhmm)) == 0)
    {
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
        hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
        int hh = stoi(hhmm.substr(0, 2));
        int mm = stoi(hhmm.substr(2, 2));
        scheduleList[mod_id].setEndTime(hh * 100 + mm);
        return 0;
    }
    return select;
}
template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyContent(int mod_id)
{
    cout << modifySchedulesString[6];
    string content;
    getline(cin, content);
    int select;
    if ((select = contentVaild(content)) == 0)
    {
        scheduleList[mod_id].setContent(content);
        return 0;
    }
    return select;
}

template <typename S, typename U, typename D>
int Calendar<S, U, D>::modifyLocation(int mod_id)
{
    cout << modifySchedulesString[5];
    string location;
    getline(cin, location);
    int select;
    if ((select = contentVaild(location)) == 0)
    {
        scheduleList[mod_id].setLocation(location);
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
    if (findCheck(title, "$"))
    {
        cout << err[0];
        return 2;
    }

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
    if (findCheck(yymmdd, "$") || yymmdd.length() < 6 || yymmdd.length() == 7 || yymmdd.length() > 8)
    {
        cout << err[0];
        return 2;
    }

    if (yymmdd.length() == 8 && !((yymmdd[2] == '-' || yymmdd[2] == '/') && (yymmdd[5] == '-' || yymmdd[5] == '/')))
    {
        cout << err[0];
        return 2;
    }

    check C = check();

    yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
    yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());

    if (!C.isOnlyNumber(yymmdd) || yymmdd.length() != 6)
    {
        cout << err[0];
        return 2;
    }

    int mm = stoi(yymmdd.substr(2, 2));
    int dd = stoi(yymmdd.substr(4, 2));
    if (mm < 1 || mm > 12 || dd < 1 || dd > 31)
    {
        cout << err[0];
        return 1;
    }

    return 0;
}

int yymm_dateVaild(string yymmdd)
{
    if (findCheck(yymmdd, "$"))
    {
        cout << err[0];
        return 2;
    }
    check C = check();

    if (yymmdd.length() >= 4 || yymmdd.length() <= 5)
    {
        if (!(C.isOnlyNumber(yymmdd.substr(0, 1)) || C.isOnlyNumber(yymmdd.substr(yymmdd.length() - 1, 1))))
        {
            cout << err[0] << "!";
            return 2;
        }
        else
        {
            yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '-'), yymmdd.end());
            yymmdd.erase(std::remove(yymmdd.begin(), yymmdd.end(), '/'), yymmdd.end());
            if (yymmdd.length() == 4)
            {
                if ((1 <= stoi(yymmdd.substr(2, 2)) && stoi(yymmdd.substr(2, 2)) <= 12))
                {
                    return 0;
                }
                else
                {
                    cout << err[0] << "@";
                    return 1;
                }
            }
        }
    }
    cout << err[0] << "#";
    return 3;
}
int hhmmVaild(string hhmm)
{
    if (findCheck(hhmm, "$") || hhmm.length() < 4 || hhmm.length() > 5)
    {
        cout << err[0];
        return 2;
    }

    if ( hhmm.length() == 5 && !((hhmm[2] == '-' || hhmm[2] == '/' || hhmm[2] == ':')) )
    {
        cout << err[0];
        return 2;
    }

    check C = check();

    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), ':'), hhmm.end());

    if (!C.isOnlyNumber(hhmm) || hhmm.length() != 4)
    {
        cout << err[0];
        return 2;
    }

    int hh = stoi(hhmm.substr(0, 2));
    int mm = stoi(hhmm.substr(2, 2));
    if (mm < 0 || mm > 59 || hh < 0 || hh > 23)
    {
        cout << err[0];
        return 1;
    }

    return 0;
}

int hhmm_ahead_Vaild(int startTime, string hhmm)
{
    if (findCheck(hhmm, "$") || hhmm.length() < 4 || hhmm.length() > 5)
    {
        cout << err[0];
        return 2;
    }

    if (hhmm.length() == 5 && !((hhmm[2] == '-' || hhmm[2] == '/' || hhmm[2] == ':')))
    {
        cout << err[0];
        return 2;
    }

    check C = check();

    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '-'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), '/'), hhmm.end());
    hhmm.erase(std::remove(hhmm.begin(), hhmm.end(), ':'), hhmm.end());

    if (!C.isOnlyNumber(hhmm) || hhmm.length() != 4)
    {
        cout << err[0];
        return 2;
    }

    int hh = stoi(hhmm.substr(0, 2));
    int mm = stoi(hhmm.substr(2, 2));
    if (mm < 0 || mm > 59 || hh < 0 || hh > 23)
    {
        cout << err[0];
        return 1;
    }
    if ( startTime > hh*100+mm ) {
        cout << err[0];
        return 2;
    }
    return 0;
}

int contentVaild(string contents)
{
    if (findCheck(contents, "$") || contents.length() > 100)
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
void Calendar<S, U, D>::deleteS(U user)
{
    cout << deleteString[0];
    cout << curr_year << ScheduleInfo[2] << curr_month << ScheduleInfo[3] << endl;
    show_Schedules(curr_year, curr_month);
    cout << deleteString[1];
    cout << deleteString[2];
    string input;
    do
    {
        cout << prompt;
        getline(cin, input);
        if (Check.qCheck(input))
        {
            select_Schedules_option(user);
            return;
        }
    } while (!Check.numberCheck(input, 2));
    int selection = checkValidSelection(admin, 6);
    if (selection == -2)
    {
        // q기능 수행
        // 캘린더 선택으로 가야함
    }
    int input_int = stoi(input);
    if (input_int == 1)
    {
        deleteSchedule(user);
        return;
    }
    else if (input_int == 2)
    {
        string yymm;

        do
        {
            cout << prompt;
            getline(cin, yymm);
        } while (yymm_dateVaild(yymm) == 0);

        yymm.erase(std::remove(yymm.begin(), yymm.end(), '-'), yymm.end());
        yymm.erase(std::remove(yymm.begin(), yymm.end(), '/'), yymm.end());
        int yy = stoi(yymm.substr(0, 2));
        int mm = stoi(yymm.substr(2, 2));
        if (0 <= yy && yy < 70) yy += 2000;
		else if (70 <= yy && yy < 100) yy += 1900;
        curr_year = yy;
        curr_month = mm;
        deleteS(user);
        return;
    }
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::deleteSchedule(U user)
{
    int modify_id;
    string input;
    do
    {
        int tmp = 0;
        do
        {
            if (tmp > 0)
                cout << err[0];
            cout << deleteString[0];
            cout << prompt;
            getline(cin, input);
            if (Check.qCheck(input))
            {
                deleteS(user);
                return;
            }
            tmp++;
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

deleteRetryYN:
    cout << deleteString[3];
    getline(cin, input);
    if (input == "Y" || input == "y")
    {
        scheduleList.erase(scheduleList.begin() + modify_id);
        system("cls");
        select_Schedules_option(user);
        return;
    }
    else if (input == "N" || input == "n")
    {
        deleteSchedule(user);
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
    getline(cin, keyword);
    if (Check.qCheck(keyword))
    {
        system("cls");
        select_Schedules_option(user);
        return;
    }
    if (keyword.length() < 2)
    {
        cout << err[0];
        goto SearchTryAgain;
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
            cout << ScheduleInfo[11] << scheduleList[i].getID() << endl;
            cout << ScheduleInfo[0] << scheduleList[i].getTitle() << endl;
            cout << ScheduleInfo[1] << search.yy << ScheduleInfo[2] << search.mm << ScheduleInfo[3] << search.dd << ScheduleInfo[4] << endl;
            cout << ScheduleInfo[5] << scheduleList[i].getStartTime() / 100 << ScheduleInfo[6] << scheduleList[i].getStartTime() % 100 << ScheduleInfo[7] << endl;
            cout << ScheduleInfo[8] << scheduleList[i].getEndTime() / 100 << ScheduleInfo[6] << scheduleList[i].getEndTime() % 100 << ScheduleInfo[7] << endl;
            cout << ScheduleInfo[10] << scheduleList[i].getLocation() << endl;
            cout << ScheduleInfo[9] << scheduleList[i].getContent() << endl;
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
        cout << err[3];
        select_Schedules_option(user);
        return;
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
        cout << err[3];
        select_Schedules_option(user);
        return;
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