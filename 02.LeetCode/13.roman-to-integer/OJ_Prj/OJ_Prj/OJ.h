#ifndef __OJ_H__
#define __OJ_H__

#include <iostream>
#include <string>
#include <map>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    typedef map<char, int> RomanCharValueMap;
    typedef RomanCharValueMap::iterator RomanCharValueIter;

    void initRomanCharValueMap()
    {
        m_mapRomanCharValue.clear();
        m_mapRomanCharValue.insert(pair<char, int>('I', 1));
        m_mapRomanCharValue.insert(pair<char, int>('V', 5));
        m_mapRomanCharValue.insert(pair<char, int>('X', 10));
        m_mapRomanCharValue.insert(pair<char, int>('L', 50));
        m_mapRomanCharValue.insert(pair<char, int>('C', 100));
        m_mapRomanCharValue.insert(pair<char, int>('D', 500));
        m_mapRomanCharValue.insert(pair<char, int>('M', 1000));
    }

    int romanToInt(string s)
    {
        // 初始化逻辑字符与数值对应表
        initRomanCharValueMap();

        // 从左往右加，不论数值在左或在右
        int sum = 0;
        size_t strLen = s.size();
        for (size_t i = 0; i < strLen; ++i)
        {
            sum += m_mapRomanCharValue[s.at(i)];
        }

        // 从右往左，若先导字符大于后续字符，则累加，直到小于后续字符
        int minusSum = 0;
        bool isSumUp = false;
        for (size_t i = 0; i < (strLen - 1); ++i)
        {
            int iTmpPrev = m_mapRomanCharValue[s.at(strLen - i - 1)];
            int iTmpNow = m_mapRomanCharValue[s.at(strLen - i - 2)];
            if (iTmpPrev > iTmpNow)
            {
                isSumUp = true;
            }

            if (iTmpPrev < iTmpNow)
            {
                isSumUp = false;
            }

            if (isSumUp)
            {
                minusSum += iTmpNow;
            }
        }

        // 重复计算了左侧值，需要减2倍大小
        int result = sum - 2 * minusSum;

        return result;
    }

private:
    RomanCharValueMap m_mapRomanCharValue;
};
#endif // __OJ_H__

