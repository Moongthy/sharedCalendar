#include"../header/Calendar.h"
#include"../header/SharedCalendar.h"
#include"../header/SharedCalendarManager.h"

#include"../header/type/Schedule.h"
#include"../header/type/User.h"
#include"../header/type/Date.h"

#include<iostream>
#include<string.h>
#include"../header/strings.h"
using namespace std;

int main(){
    string a = "ans", b = "123";

    User user = User(a, b);
    
    // SharedCalendarManager<Schedule, User, Date> scm = SharedCalendarManager<Schedule, User, Date>();

    // MenuInput mi = MenuInput(user, scm);

    // mi.mainMenu();
    // cout << (int)L'가' << endl;

    Calendar cal = Calendar(user);



    return 0;
}
