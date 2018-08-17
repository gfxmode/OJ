#ifndef __OJ_H__
#define __OJ_H__

#include <iostream>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    bool isPalindrome(int x)
    {
        // 负数不是回文数，因为有-符号
        if (0 > x)
        {
            return false;
        }

        char arrInt[10] = {0};
        int cnt = 0;
        int tmpX = x;
        while (tmpX > 0)
        {
            arrInt[cnt] = tmpX % 10;
            tmpX = tmpX / 10;
            ++cnt;
        }

        int reverse = 0;
        for (int i = 0; i < cnt; ++i)
        {
            // cnt表示总位数，pow时需要减1. 如1000有4位，但pow(10, 3)
            reverse = reverse + arrInt[i] * (int)pow((float)10, (cnt - i - 1));
        }

        return (reverse == x);
    }

};
#endif __OJ_H__
