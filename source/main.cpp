
#include"../header/SharedCalendarManager.h"

#include"../header/input/menuInput.h"

#include<string>
//

#include"../header/ReadFile.h"

using namespace std;

#include"../header/type/Users.h"

int main(){

    string name;
    string id;

    User user = User(name, id);

    Users users = Users(name, id);
    cout << "===========================START==============================" << endl;
    users.firstMenu();

    // Users users = Users("ansrms", "1234");
    // Users another = Users("test", "2345");

    // Calendar<Schedule, User, Date> cal = Calendar<Schedule, User, Date> (users);

    // cal.select_Schedules_option(users);

    return 0;
}