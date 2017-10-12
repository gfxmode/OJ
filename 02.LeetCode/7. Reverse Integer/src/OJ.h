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
        
        stack<int> stackInt;    // 存放各位数字，栈
        
        uint uiTemp = uiTmp;
        int iCnt = 0;           // 数字位数计数
        while(uiTemp != 0)
        {
            int iRes = (uiTemp % 10);
            stackInt.push(iRes);
            uiTemp /= 10;
            
            ++iCnt;
        }

        uint uiRet = 0;
        --iCnt;             // while循环运行完后会多加1，这里进行修正
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
