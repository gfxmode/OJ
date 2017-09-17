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
        char arrResult[1005] = {0};             // ���鳤�������1000��<=1000ʱ�������Խ��
        char* arrInput = (char*)s.data();
        int strLen = strlen(arrInput);
        if (1 == strLen)
        {
            return s;
        }

        // ����������
        int maxOddThis = 0;
        for (int i = 0; i < strLen; i++)
        {
            int maxLen = min(i, strLen - i -1);
            int cnt = 0;                        // �����ַ�����
            // ����������
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

        // ż��������
        int maxEvenThis = 0;
        for (int i = 0; i < strLen - 1; i++)
        {
            int maxLen = min(i, strLen - i - 1);
            int cnt = 0;                    // ����������
            // ����ż��������
            for (int j = 0; j <= maxLen; j++)
            {
                if (arrInput[i - j] != arrInput[i + j + 1])
                {
                    break;
                }
                else
                {
                    cnt++;
                }
            }

            if ((cnt > 0) && (cnt >= maxEvenThis) && (cnt > maxOddThis))
            {
                maxEvenThis = cnt;
                memcpy(arrResult, arrInput + i - cnt + 1, 2*cnt);
                arrResult[2* cnt + 1] = '\0';
            }
        }

        // δ�ҵ����ȴ��ڵ���2�Ļ���ʱ���������ַ������ַ�����Ϊ�ǻ���
        if((0 == maxOddThis) && (0 == maxEvenThis))
        {
            arrResult[0] = arrInput[0];
            arrResult[1] = '\0';
        }

        return arrResult;
    }
};
#endif OJ_H
