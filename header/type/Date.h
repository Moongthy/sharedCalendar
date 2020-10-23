#pragma once

#ifndef ___DATE___
#define ___DATE___

class Date{
public:
    int yy;
    int mm;
    int dd;
    /*
        ������ �����ε��� ���ؼ� ��¥�� ���� �� �ְ� �߽��ϴ�
        �ٵ� > ������ �ۿ� �ȵǼ� ����Ͻ� ���� ���� �ٶ�
    */
    Date operator>(Date date) {
        if ((0 <= yy < 70) && (0 <= date.yy < 70)) { //�Ѵ� 2000�� ���ĸ� ���� ��,
            if (yy < date.yy) {
                return false;
            }
            else if (yy == date.yy && mm < date.mm) { //������ ������ ���� �� Ŭ ��
                return false;
            }
            else if (yy == date.yy && mm == date.mm) { // ������ ���� ���� ��
                if (dd < date.dd) { // �Ϸ� ��
                    return false;
                }
                else return true;
            }
        }
        else if ((70 <= yy <= 99) && (70 <= date.yy <= 99)) { // �Ѵ� 70�� ���� 00�� ���� �� ��,
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
        else if (((70 <= yy <= 99) && (0 <= date.yy < 70))) { //�� �� �ٸ� ��, 1
            return false;
        }
        else if (((0 <= yy < 70) && (70 <= date.yy <= 99))) {// �� �� �ٸ� ��, 2
            return true;
        }
    }
    
    
    bool checkError(Date date) {//���� �����ڸ� ���ؼ� Ŭ���� ���ο��� üũ�Ҽ��ִ� ����. Ʋ������ false�� ������
        if (this > date) {
            return false;
        }
        else return true;
    }
};

#endif