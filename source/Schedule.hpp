
/*************************일정 파트********************************/

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
void Calendar<S, U, D>::addSchedule(D startDate, D endDate, string content)
{
    scheduleList.push_back(S(startDate, endDate, content));
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::modifySchedule()
{
    //id로 수정하는건데
    //parameter 수정 필요
}

template <typename S, typename U, typename D>
void Calendar<S, U, D>::deleteSchedule(string keyword)
{
    // searchSchedule에서 vector에 추가 대신 원래 vector에서 pop해주면 될듯
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