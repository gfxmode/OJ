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
        // 字符串分割
        vector<string> vecSplit;
		string strDelim(" ");
        split(str, strDelim, &vecSplit);

		// patter和分割后长度不等，返回false
		if (pattern.size() != vecSplit.size())
		{
			return false;
		}

		// 存放pattern与分割值对应关系
        map<char, string> mapPattern;
		map<string, bool> mapValueExsits;
		for (int i = 0; i < pattern.size(); i++)
		{
			char chKey = pattern[i];
			if (0 == mapPattern.count(chKey))
			{
				// abba, dog dog dog dog。多个key，对应相同value值处理
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
        函数名：split
        功能：字符串分割
        入参：s[IN]，待分割的字符串
              delim[IN]，分割符
              ret[OUT]，分割后的结果
        返回值：void
        说明：当字符串为空时，也会返回一个空字符串
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
