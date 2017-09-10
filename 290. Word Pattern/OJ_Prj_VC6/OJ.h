#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>

using namespace std;


#include <map>
class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    bool wordPattern(string pattern, string str) 
	{
        // �ַ����ָ�
        vector<string> vecSplit;
		string strDelim(" ");
        split(str, strDelim, &vecSplit);

		// patter�ͷָ�󳤶Ȳ��ȣ�����false
		if (pattern.size() != vecSplit.size())
		{
			return false;
		}

		// ���pattern��ָ�ֵ��Ӧ��ϵ
        map<char, string> mapPattern;
		map<string, bool> mapValueExsits;
		for (int i = 0; i < pattern.size(); i++)
		{
			char chKey = pattern[i];
			if (0 == mapPattern.count(chKey))
			{
				// abba, dog dog dog dog�����key����Ӧ��ͬvalueֵ����
				if(1 == mapValueExsits.count(vecSplit.at(i)))
				{
					return false;
				}
				mapPattern[chKey] = vecSplit.at(i);
				mapValueExsits[vecSplit.at(i)] = true;
			}
			else
			{
				if (vecSplit.at(i) != mapPattern[chKey])
				{
					return false;
				}
			}
		}
        return true;
    }
    
    /*
        ��������split
        ���ܣ��ַ����ָ�
        ��Σ�s[IN]�����ָ���ַ���
              delim[IN]���ָ��
              ret[OUT]���ָ��Ľ��
        ����ֵ��void
        ˵�������ַ���Ϊ��ʱ��Ҳ�᷵��һ�����ַ���
    */  
    void split(std::string& s, std::string& delim,std::vector< std::string >* ret)  
    {  
        size_t last = 0;  
        size_t index = s.find_first_of(delim, last);  
        while (index != std::string::npos)  
        {  
            ret->push_back(s.substr(last, index-last));  
            last = index+1;  
            index = s.find_first_of(delim, last);  
        }  
        if (index-last>0)  
        {  
            ret->push_back(s.substr(last, index-last));  
        }  
    }  
};
#endif OJ_H
