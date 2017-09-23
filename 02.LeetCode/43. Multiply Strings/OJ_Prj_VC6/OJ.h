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

    /*  ��������multiply
        �������ܣ���������㷨
        ˵����ʹ�ö���ʽ��˵ķ�����������num1[i] * num2[j] = result[i + j]
        ��Σ�num1[IN]������
                num2[IN]��������
        ����ֵ��string����˺�Ľ��
    */
    string multiply(string num1, string num2) 
    {
        // num1��num2����С��110������ַ�����󳤶�110 * 110 = 12100
        const int MAX_RESULT_LENGTH = 110 + 110;
        int arrResult[MAX_RESULT_LENGTH] = {0};
        int iLen1 = num1.size();
        int iLen2 = num2.size();
        /* Step1������ʽ���
            ����ʽ��˼��㷽��num1[i] * num2[j] = result[lenA + lenB - (i + j) - 2]
            ���ַ��������ִ��˳���෴����С��������ַ�������������result������
        */
        for (int i = 0; i < iLen1; ++i)
        {
            for (int j = 0; j < iLen2; ++j)
            {
                int idxResult = iLen1 + iLen2 - (i + j) - 2;
                arrResult[idxResult] = arrResult[idxResult] + ((num1[i] - '0') * (num2[j] - '0'));
            }
        }

        /* Step2������ӵ͵�����
            ����ʽ��˼��㷽��num1[i] * num2[j] = result[i + j]
            ���ַ��������ִ��˳���෴���Ӵ�С�����ַ������н�λʱ��λ����
        */
        int cntLen = 0;                 // ����������
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
        /* Step3: Int����תChar���顣
        */
        // �����ڴ�
        char *ptrRet;
        // �����Ϊ0����ֱ�����0 + '\0'
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
                // ���ַ��������鵹���ţ����ﵹ����
                ptrRet[cntLen - i - 1] = arrResult[i] + '0';
            }
            ptrRet[cntLen] = '\0';
        }
        // ɾ��ͷ�������0�����ײ���ʼ�Ҳ�����'0'���ַ���ptrRet����idx��������ɾ������0
        int idx = 0;
        for (idx = 0; idx < cntLen; ++idx)
        {
            if ('0' != ptrRet[idx])
            {
                break;
            }
        }

        string strRet = ptrRet + idx;
        // ȫ��Ϊ0�ᱻ��գ������ٴβ�0
        if (strRet == "")
        {
            strRet = "0";
        }
        // �ͷ�ָ��
        free(ptrRet);

        return strRet;
    }
};
#endif OJ_H
