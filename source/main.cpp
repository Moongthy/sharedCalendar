
#include"../header/SharedCalendarManager.h"

#include"../header/input/menuInput.h"

#include<string>

#include"../header/ReadFile.h"

using namespace std;

#include"../header/type/Users.h"

int main() {
    string name;
    string id;

    User user = User(name, id);
    Users users = Users(name, id);

    users.firstMenu();
    return 0;
}