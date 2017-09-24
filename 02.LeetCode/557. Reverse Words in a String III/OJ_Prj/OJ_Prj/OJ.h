#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    string reverseWords(string s)
    {
        string strRet = "";
        vector<string> vecSplit;

        // Step1���ַ����ָ�
        string delim = " ";
        split(s, delim, &vecSplit);

        // Step2�����ʵߵ�
        for (size_t i = 0; i < vecSplit.size(); ++i)
        {
            strRet += reverseAWord(vecSplit[i]) + " ";
        }
        // Step3���Ƴ�������Ŀո�
        strRet.erase(strRet.find_last_not_of(" ") + 1);

        return strRet;
    };

    
    //************************************
    // Method:    reverseAWord�����ʵ���
    // FullName:  OJ::reverseAWord
    // Access:    public 
    // Returns:   std::string
    // Qualifier:
    // Parameter: string strInput
    //************************************
    string reverseAWord(string strInput)
    {
        char *ptrTmp = (char *)malloc(sizeof(char) * (strInput.size() + 1));
        size_t i = 0;
        for (i = 0; i < strInput.size(); ++i)
        {
            *(ptrTmp + i) = strInput[strInput.size() - i - 1];
        }
        *(ptrTmp + i) = '\0';
        string strRet = ptrTmp;
        delete ptrTmp;

        return strRet;
    }

    //************************************
    // Method:    split�����ַ��ָ��ַ���
    // FullName:  OJ::split
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: string & s�����ָ���ַ���
    // Parameter: string & delim���ָ��
    // Parameter: vector<std::string> * ret���ָ��Ľ��
    // ˵�������ַ���Ϊ��ʱ��Ҳ�᷵��һ�����ַ��� 
    //************************************
    void split(string& s, string& delim, vector<string>* ret)
    {  
        size_t last = 0;
        size_t index = s.find_first_of(delim,last);
        while (index != string::npos)  
        {  
            ret->push_back(s.substr(last, index-last));
            last = index+1;
            index = s.find_first_of(delim, last);
        }

        if (index-last > 0)
        {
            ret->push_back(s.substr(last, index-last));
        }
    }
};
#endif OJ_H
