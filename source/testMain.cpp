#include"../header/Calendar.h"
#include"../header/SharedCalendar.h"
#include"../header/SharedCalendarManager.h"

#include"../header/type/Schedule.h"
#include"../header/type/User.h"
#include"../header/type/Date.h"

#include<iostream>

#include"../header/input/Input.h"
#include"../header/strings.h"
using namespace std;

#define C               Calendar<Schedule, User, Date>
#define SC              SharedCalendar<Schedule, User, Date>
#define SCManager       SharedCalendarManager<Schedule, User, Date>

#define rep(n) for(int i = 0; i < n; ++i) 


// void stage1_whatCalendarDoYouWant(){
//     // 화면 지우는 것 넣어야 함
    
//     rep(4) cout << choiceCalendarMenu[i];

//     Input input;

//     string choice = input.input();
    
//     if(choice == "q") {
//         // 전단계
//         return;
//     }

//     if(!input.simpleCheck("123", choice)){
//         cout << err[0];
//         stage1_whatCalendarDoYouWant();
//         return;
//     }

//     if(choice == "1"){
//         return;
//     }

//     if(choice == "2"){
//         stage2_choiceSharedCalendarAction();
//         return;
//     }

//     if(choice == "3"){
//         cout << "종료" << endl;
//         exit(0);
//     }
// }

// void stage2_choiceSharedCalendarAction(){

//     rep(4) cout << choiceSharedCalendarAction[i];

//     Input input;

//     string choice = input.input();

//         if(choice == "q") {
//         stage1_whatCalendarDoYouWant();
//         return;
//     }

//     if(!input.simpleCheck("123", choice)){
//         cout << err[0];
//         stage2_choiceSharedCalendarAction();
//         return;
//     }

//     if(choice == "1"){
//         return;
//     }

//     if(choice == "2"){
//         stage2_choiceSharedCalendarAction(0);
//         return;
//     }

//     if(choice == "3"){
//         cout << "종료" << endl;
//         exit(0);
//     }
// }

// void state2_1_inputCreateSharedCalendar(int stage){
    
//     cout << inputCreateSharedCalendar[stage];    
//     if(!stage) state2_1_inputCreateSharedCalendar(stage+1);

//     Input input;

//     string choice = input.input();
//         if(choice == "q") {
//         stage2_choiceSharedCalendarAction();
//         return;
//     }

//     if(!input.simpleCheck("123", choice)){
//         cout << err[0];
//         stage2_choiceSharedCalendarAction();
//         return;
//     }

//     if(choice == "1"){
//         return;
//     }

//     if(choice == "2"){
//         stage2_choiceSharedCalendarAction();
//         return;
//     }

//     if(choice == "3"){
//         cout << "종료" << endl;
//         exit(0);
//     }
// }

int main(){

    
    cout << "zzzz" << endl;
    
    
    return 0;
}