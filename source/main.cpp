
#include"../header/SharedCalendarManager.h"

#include"../header/input/menuInput.h"

#include<string>

#include"../header/ReadFile.h"

using namespace std;

#include"../header/type/Users.h"
#include"../header/Calendar.h"

int main(){

    // string a = "ans", b = "123";

    // User user = User(a, b);
    
    // SharedCalendarManager<Schedule, User, Date> scm = SharedCalendarManager<Schedule, User, Date>();

    // MenuInput mi = MenuInput(user, scm);

    // mi.mainMenu();

    Users users = Users("ansrms", "1234");

    Calendar<Schedule, User, Date> cal = Calendar<Schedule, User, Date> (users);

    cal.select_Schedules_option();
    cal.select_Schedules_option();
    // users.firstMenu();

    // cout << (int)L'가' << endl;

    return 0;
}