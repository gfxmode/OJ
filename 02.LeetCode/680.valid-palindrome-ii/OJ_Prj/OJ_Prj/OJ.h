#ifndef __OJ_H__
#define __OJ_H__

#include <iostream>
#include <string>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    bool palindrome(string& s, int idxStart, int idxEnd)
    {
        if (idxStart > idxEnd)
        {
            return false;
        }

        size_t step = (idxEnd - idxStart) / 2;
        // 若只剩下2个字符，或1个字符，均要进行比较
        for (size_t i = 0; i <= step; ++i)
        {
            if (s[idxStart + i] != s[idxEnd - i])
            {
                return false;
            }
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        size_t len = s.size();

        for (size_t i = 0; i < (len / 2); ++i)
        {
            if (s[i] != s[len - 1 - i])
            {
                return (palindrome(s, i + 1, len - 1 - i) || palindrome(s, i, len - 2 - i));
            }
        }

        return true;
    }
};
#endif // __OJ_H__
