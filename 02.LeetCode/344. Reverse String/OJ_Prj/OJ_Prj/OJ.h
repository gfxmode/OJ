#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    string reverseString(string s)
    {
        int sizeInput = s.size();
        // ������ʱ�м����飬�����ַ�����
        char *ptrTmp = (char *)malloc(sizeof(char) * (sizeInput + 1));
        int i = 0;
        for (i = 0; i < sizeInput; ++i)
        {
            *(ptrTmp + i) = s[sizeInput - i - 1];
        }
        *(ptrTmp + i) = '\0';
        string strRet = ptrTmp;
        delete ptrTmp;

        return strRet;
    }
};
#endif OJ_H
