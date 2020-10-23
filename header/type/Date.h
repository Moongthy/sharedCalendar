#pragma once

#ifndef ___DATE___
#define ___DATE___

class Date{
public:
    int yy;
    int mm;
    int dd;

    Date(int yy, int mm, int dd) : mm(mm), dd(dd){
        if (0 <= yy && yy < 70) yy += 2000;
        else if(70 <= yy && yy < 100) yy += 1900;
    }

    /*
        연산자 오버로딩을 통해서 날짜를 비교할 수 있게 했습니다
        근데 > 연산자 밖에 안되서 사용하실 때는 주의 바람
    */
    Date operator>(Date date) {
        if (yy > date.yy) { // 연도만 비교
            return true;
        }
        else if (yy == date.yy && mm > date.mm) { //연도가 같으면 달을 비교
            return true;
        }
        else if (yy == date.yy && mm == date.mm) { //연도랑 달이 똑같으면
            if (dd > date.dd) { //일을 비교
                return true;
            }
            else return false;
        }
        return false;
    }
    
    
    bool checkError(Date date) {//위에 연산자를 통해서 클래스 내부에서 체크할수있는 만듦. 틀렸으면 false를 리턴함
        if (this > date) {
            return false;
        }
        else return true;
    }
};

#endif