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
        ������ �����ε��� ���ؼ� ��¥�� ���� �� �ְ� �߽��ϴ�
        �ٵ� > ������ �ۿ� �ȵǼ� ����Ͻ� ���� ���� �ٶ�
    */
    Date operator>(Date date) {
        if (yy > date.yy) { // ������ ��
            return true;
        }
        else if (yy == date.yy && mm > date.mm) { //������ ������ ���� ��
            return true;
        }
        else if (yy == date.yy && mm == date.mm) { //������ ���� �Ȱ�����
            if (dd > date.dd) { //���� ��
                return true;
            }
            else return false;
        }
        return false;
    }
    
    
    bool checkError(Date date) {//���� �����ڸ� ���ؼ� Ŭ���� ���ο��� üũ�Ҽ��ִ� ����. Ʋ������ false�� ������
        if (this > date) {
            return false;
        }
        else return true;
    }
};

#endif