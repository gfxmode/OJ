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

        // Step1：字符串分割
        string delim = " ";
        split(s, delim, &vecSplit);

        // Step2：单词颠倒
        for (size_t i = 0; i < vecSplit.size(); ++i)
        {
            strRet += reverseAWord(vecSplit[i]) + " ";
        }
        // Step3：移除最后多余的空格
        strRet.erase(strRet.find_last_not_of(" ") + 1);

        return strRet;
    };

    
    //************************************
    // Method:    reverseAWord：单词倒序
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
    // Method:    split，按字符分割字符串
    // FullName:  OJ::split
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: string & s：待分割的字符串
    // Parameter: string & delim：分割符
    // Parameter: vector<std::string> * ret：分割后的结果
    // 说明：当字符串为空时，也会返回一个空字符串 
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
