#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>
#include <cmath>

#define INT32_MAX 0x7FFFFFFF
#define INT32_MIN (-0x7FFFFFFF-1)
#define MAX_NUM_COUNT 11

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    /*  brief: Ѱ���ַ������ȳ��ֵ����֣���������λ������
        param: strInput[IN]���ַ���
                sign[OUT]������λ
        return: ���ֳ��ֵ�λ������
    */
    int findIdxStart(string strInput, int& sign)
    {
        int idx = -1;
        int sizeStr = strInput.size();
        for (int i = 0; i < sizeStr; ++i)
        {
            char ch = strInput.at(i);
            // �ո�����
            if (' ' == ch)
            {
                continue;
            }

            // �����+ -�ſ�ͷ���������λ
            if (('-' == ch) || ('+' == ch))
            {
                if ((i + 1) < sizeStr)
                {
                    char chNext = strInput.at(i + 1);
                    if (('0' <= chNext) && ('9' >= chNext))
                    {
                        if ('-' == ch)
                        {
                            sign = -1;
                        }
                        idx = i + 1;
                        break;
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }
            }

            // ���ҵ����֣��򷵻�����������
            if (('0' <= ch) && ('9' >= ch))
            {
                idx = i;
                break;
            }
            else
            {
                return -1;
            }
        }

        return idx;
    }

    /*  brief: Ѱ���ַ��������ֵ����֣���������λ������
        param: strInput[IN]���ַ���
                sign[OUT]������λ
        return: ���ֳ��ֵ�λ������
    */
    int findIdxEnd(string strInput, int iStart)
    {
        int sizeStr = strInput.size();
        for (int i = iStart; i < sizeStr; ++i)
        {
            if ((strInput.at(i) > '9') || (strInput.at(i) < '0'))
            {
                return (i - 1);
            }
        }

        return (sizeStr - 1);
    }

    /*  brief: Ѱ���ַ������ȳ��ֵ����֣���������λ������
        param: strInput[IN]���ַ���
                sign[OUT]������λ
        return: ���ֳ��ֵ�λ������
    */
    long long convertStrToLongLong(string strInput, int iStart, int iEnd, int iSign)
    {
        long long llRet = 0;
        if (iStart > iEnd)
        {
            return 0;
        }

        int numChar = iEnd - iStart;

        if (numChar > MAX_NUM_COUNT)
        {
            return (long long)INT32_MAX + 1;
        }

        for (int i = iStart; i <= iEnd; ++i)
        {
            llRet += (long long)pow((float)10, numChar) * (strInput.at(i) - '0');
            long long intMAX = (long long)INT32_MAX + 1;
            if (llRet > intMAX)
            {
                return llRet;
            }
            --numChar;
        }

        return llRet;
    }

    int myAtoi(string str)
    {
        int iSign = 1;

        // ����str��Ѱ�������ַ�����ʼλ��
        int idxStart = findIdxStart(str, iSign);
        if (-1 == idxStart)
        {
            return 0;
        }

        // ����str��Ѱ������ַ�������λ��
        int idxEnd = findIdxEnd(str, idxStart);
        if ((-1 == idxEnd) || (idxEnd < idxStart))
        {
            return 0;
        }

        // ���㴦����
        long long llRet = convertStrToLongLong(str, idxStart, idxEnd, iSign) * iSign;

        // �Ƿ��������
        if (llRet < INT32_MIN)
        {
            return INT32_MIN;
        }

        if (llRet > INT32_MAX)
        {
            return INT32_MAX;
        }

        return (int)llRet;
    }

};
#endif
