#pragma once

#ifndef ___DATE___
#define ___DATE___

class Date{
public:
    int yy;
    int mm;
    int dd;
    /*
        연산자 오버로딩을 통해서 날짜를 비교할 수 있게 했습니다
        근데 > 연산자 밖에 안되서 사용하실 때는 주의 바람
    */
    Date operator>(Date date) {
        if ((0 <= yy < 70) && (0 <= date.yy < 70)) { //둘다 2000년 이후를 뜻할 때,
            if (yy < date.yy) {
                return false;
            }
            else if (yy == date.yy && mm < date.mm) { //연도는 같은데 월이 더 클 때
                return false;
            }
            else if (yy == date.yy && mm == date.mm) { // 연도랑 월이 같을 때
                if (dd < date.dd) { // 일로 비교
                    return false;
                }
                else return true;
            }
        }
        else if ((70 <= yy <= 99) && (70 <= date.yy <= 99)) { // 둘다 70년 부터 00년 범위 일 때,
            if (yy < date.yy) {
                return false;
            }
            else if (yy == date.yy && mm < date.mm) {
                return false;
            }
            else if (yy == date.yy && mm == date.mm) {
                if (dd < date.dd) {
                    return false;
                }
                else return true;
            }
        }
        else if (((70 <= yy <= 99) && (0 <= date.yy < 70))) { //둘 다 다를 때, 1
            return false;
        }
        else if (((0 <= yy < 70) && (70 <= date.yy <= 99))) {// 둘 다 다를 때, 2
            return true;
        }
    }
    
    
    bool checkError(Date date) {//위에 연산자를 통해서 클래스 내부에서 체크할수있는 만듦. 틀렸으면 false를 리턴함
        if (this > date) {
            return false;
        }
        else return true;
    }
};

#endif