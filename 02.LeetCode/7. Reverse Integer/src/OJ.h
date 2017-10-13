#ifndef OJ_H
#define OJ_H

#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    int reverse(int x)
    {
        bool isNegtiveNum = (x < 0) ? true : false;
        uint uiTmp = abs(x);
        
        stack<int> stackInt;    // ��Ÿ�λ���֣�ջ
        
        uint uiTemp = uiTmp;
        while(uiTemp != 0)
        {
            int iRes = (uiTemp % 10);
            stackInt.push(iRes);
            uiTemp /= 10;
        }

        unsigned long long ullRet = 0;  // ʹ��unsigned long long������м������
        int i = 0;                      // �ַ�λ�ü���
        while(!stackInt.empty())
        {
            ullRet += stackInt.top() * pow(10, i);
            stackInt.pop();
            
            ++i;
        }

        uint uiLimit = (isNegtiveNum) ? abs(INT32_MIN) : abs(INT32_MAX);
        int iRet = 0;
        if(ullRet > uiLimit)
        {
            return 0;
        }
        else
        {
            iRet = ullRet * ((isNegtiveNum) ? (-1) : 1);
        }
        return iRet;
    }

};
#endif
