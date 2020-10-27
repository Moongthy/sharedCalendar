
#include"../header/SharedCalendarManager.h"

#include"../header/input/menuInput.h"

#include<string>

#include"../header/ReadFile.h"
#include"../header/type/Users.h"

using namespace std;

int main(){
    string name;
    string id;

    User user = User(name, id);
    
    Users users = Users(name,id);
    
    users.firstMenu();
    
    SharedCalendarManager<Schedule, User, Date> scm = SharedCalendarManager<Schedule, User, Date>();

    MenuInput mi = MenuInput(user, scm);

    mi.mainMenu();

    return 0;
}