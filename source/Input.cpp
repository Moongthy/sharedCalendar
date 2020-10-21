#include"../header/input/Input.h"

void Input::userInput2Lower(string& s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void Input::removeSpace(string& s){
    string tmp = "";
    for(int i = 0; i < s.size(); ++i)
        if(s[i] != ' ')
            tmp += s[i];
    s = tmp;    
}

string Input::input(){
    string ret;
    getline(cin, ret);
    return ret;
}

int Input::colanderEncodingErr(const string& s) const{
    for(char c : s)
        for(char e : encoding) if(c == e) return 1;
    return 0;   
}

int Input::colanderLenErr(const string& s, std::pair<int, int> len) const{
    if(s.size() < len.first || s.size() > len.second) return 0;
    return 1;
}

int Input::checkSharedCalendarName(const string& s) const{

    // q누름
    if(s.size() == 1 && s[0] == 'q') return 2;

    // 길이 에러   
    if(!colanderLenErr(s, {2, 10})) return 0;

    // 인코딩 에러
    if(!colanderEncodingErr(s)) return -1;

    // 에러 없음
    return 1;
}

int Input:: checkSharedCalendarPassWord(const string& s)const{
    
    // q누름
    if(s.size() == 1 && s[0] == 'q') return 2;
    
    // 길이 에러   
    if(!colanderLenErr(s, {1, 15})) return 0;

    // 인코딩 에러
    if(!colanderEncodingErr(s)) return -1;

    // 에러 없음
    return 1;
}

bool Input::simpleCheck(const string& check, string& s) const{
    if(s.size() != 1) return false;
    for(char c : check) if(c == s[0]) return true;
    return false;
}

int Input::checkSharedCalenderAcceptable(const string& s) const{

        // q누름
    if(s.size() == 1 && s[0] == 'q') return 2;

    if(s.size() != 1) return 0;

    if(s[0] - '0' > 5 || s[0]-'0' < 2) return -1;

    return 1;
}

int Input::checkSharedCalendrDate(const string& s) const{
    
        // q누름
    if(s.size() == 1 && s[0] == 'q') return 2;
    
    if(s.size() != 6) return 0;

    for(char c : s)
        if(c < '0' || c > '9')
            return -1;
    return 1;
}






