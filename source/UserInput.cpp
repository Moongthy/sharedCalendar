#include"../header/input/UserInput.h"

UserInput::UserInput(){
    getline(cin, userInput);
}

bool UserInput::qCheck(){
    if(userInput.size() == 1 && userInput[0] == 'q')
        return true;
}

bool UserInput::encodingCheck(){
    string s = "";
    for(int i = (int)'a'; i <= (int)'z'; ++i) s += (char)i;
    for(int i = (int)'A'; i <= (int)'Z'; ++i) s += (char)i;
    for(int i = (int)'가'; i <= (int)'힣'; ++i) s += (char)i;

    for(char u : userInput){
        if(s.find(u) != string::npos)
            return false;
    return true;
}


string UserInput::lower(const string& s){
    string ret = s;
    std::transform(ret.begin(), ret.end(), ret.begin(), tolower);
    return ret;
}
