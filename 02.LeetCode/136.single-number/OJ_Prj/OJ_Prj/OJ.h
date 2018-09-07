#ifndef __OJ_H__
#define __OJ_H__

#include <vector>
#include <map>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    int singleNumber(vector<int>& nums)
    {
        map<int, int> mapInt;

        vector<int>::iterator iterNums = nums.begin();
        for (; nums.end() != iterNums; ++iterNums)
        {
            if (mapInt.end() == mapInt.find(*iterNums))
            {
                mapInt[*iterNums] = 1;
            }
            else
            {
                ++mapInt[*iterNums];
            }
        }

        map<int, int>::iterator iterMapInt = mapInt.begin();
        for (; mapInt.end() != iterMapInt; ++iterMapInt)
        {
            if (1 == iterMapInt->second)
            {
                return iterMapInt->first;
            }
        }

        // 非空数组，不会存在找不到的情况，故最后不返回仅指定返回-1
        return -1;
    }

};
#endif // __OJ_H__

