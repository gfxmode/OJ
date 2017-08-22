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

    string longestPalindrome(string s)
    {
        char arrResult[1000] = {0};
        char* arrInput = (char*)s.data();
        int strLen = strlen(arrInput);

        // 奇数回文数
        int maxOddThis = 0;
        for (int i = 0; i < strLen; i++)
        {
            int maxLen = min(i, strLen - i -1);
            int cnt = 0;                        // 回文字符计数
            // 奇数回文数
            for (int j = 1; j <= maxLen; j++)
            {
                if (arrInput[i - j] != arrInput[i + j])
                {
                    break;
                }
                else
                {
                    cnt++;
                }
            }

            if ((cnt > 0) && (cnt >= maxOddThis))
            {
                maxOddThis = cnt;
                memcpy(arrResult, arrInput + i - cnt, 2*cnt+1);
                arrResult[2*(cnt + 1)] = '\0';
            }
        }

        // 偶数回文数
        int maxEvenThis = 0;
        for (int i = 0; i < strLen - 1; i++)
        {
            int maxLen = min(i, strLen - i - 1);
            int cnt = 0;                    // 回文数计数
            // 计算偶数回文数

        }

        return arrResult;
    }
};
#endif OJ_H
