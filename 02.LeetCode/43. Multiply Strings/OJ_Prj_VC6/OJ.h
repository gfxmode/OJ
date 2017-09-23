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

    /*  函数名：multiply
        函数功能：大数相乘算法
        说明：使用多项式相乘的方法计算结果，num1[i] * num2[j] = result[i + j]
        入参：num1[IN]，乘数
                num2[IN]，被乘数
        返回值：string，相乘后的结果
    */
    string multiply(string num1, string num2) 
    {
        // num1、num2长度小于110，结果字符串最大长度110 * 110 = 12100
        const int MAX_RESULT_LENGTH = 110 + 110;
        int arrResult[MAX_RESULT_LENGTH] = {0};
        int iLen1 = num1.size();
        int iLen2 = num2.size();
        /* Step1：多项式相乘
            多项式相乘计算方法num1[i] * num2[j] = result[lenA + lenB - (i + j) - 2]
            因字符串与数字存放顺序相反，从小到大遍历字符串，倒序存放在result数组中
        */
        for (int i = 0; i < iLen1; ++i)
        {
            for (int j = 0; j < iLen2; ++j)
            {
                int idxResult = iLen1 + iLen2 - (i + j) - 2;
                arrResult[idxResult] = arrResult[idxResult] + ((num1[i] - '0') * (num2[j] - '0'));
            }
        }

        /* Step2：结果从低到处理
            多项式相乘计算方法num1[i] * num2[j] = result[i + j]
            因字符串与数字存放顺序相反，从大到小遍历字符串，有进位时进位处理
        */
        int cntLen = 0;                 // 计算结果长度
        int *ptrTmp = arrResult;
        int iCarray = 0;
        int i = 0;
        for (i = 0; i <= (iLen1 + iLen2); ++i)
        {
            int iValue = ((iCarray + (*ptrTmp)) % 10);
            iCarray = (iCarray + (*ptrTmp)) / 10;
            *ptrTmp = iValue;
            ++ptrTmp;
            ++cntLen;
        }

        if (iCarray > 0)
        {
            *ptrTmp = iCarray;
            ++cntLen;
        }
        /* Step3: Int数组转Char数组。
        */
        // 申请内存
        char *ptrRet;
        // 若结果为0，则直接输出0 + '\0'
        if (0 == cntLen)
        {
            ptrRet = (char *)malloc(sizeof(char) * 2);
            ptrRet[0] = '0';
            ptrRet[1] = '\0';
        }
        else
        {
            ptrRet = (char *)malloc(sizeof(char) * cntLen + 1);

            for (i = 0; i < cntLen; ++i)
            {
                // 因字符串与数组倒序存放，这里倒序存放
                ptrRet[cntLen - i - 1] = arrResult[i] + '0';
            }
            ptrRet[cntLen] = '\0';
        }
        // 删除头部多余的0。从首部开始找不等于'0'的字符，ptrRet加了idx索引，以删除多余0
        int idx = 0;
        for (idx = 0; idx < cntLen; ++idx)
        {
            if ('0' != ptrRet[idx])
            {
                break;
            }
        }

        string strRet = ptrRet + idx;
        // 全部为0会被清空，这里再次补0
        if (strRet == "")
        {
            strRet = "0";
        }
        // 释放指针
        free(ptrRet);

        return strRet;
    }
};
#endif OJ_H
