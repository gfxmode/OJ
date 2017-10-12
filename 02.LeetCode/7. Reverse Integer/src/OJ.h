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
        int iCnt = 0;           // ����λ������
        while(uiTemp != 0)
        {
            int iRes = (uiTemp % 10);
            stackInt.push(iRes);
            uiTemp /= 10;
            
            ++iCnt;
        }

        uint uiRet = 0;
        --iCnt;             // whileѭ������������1�������������
        while(!stackInt.empty())
        {
            uiRet += stackInt.top() * pow(10, iCnt);
            stackInt.pop();
            
            --iCnt;
        }

        uint uiLimit = (isNegtiveNum) ? abs(INT32_MIN) : abs(INT32_MAX);
        int iRet = 0;
        if(uiRet > uiLimit)
        {
            return 0;
        }
        else
        {
            iRet = uiRet * ((isNegtiveNum) ? (-1) : 1);
        }
        return iRet;
    }

};
#endif
