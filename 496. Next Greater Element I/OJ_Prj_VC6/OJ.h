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

    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        vector<int> vecResult;
        int szFindNum = findNums.size();
        int szNums = nums.size();
        // 遍历子集1
        for (int i = 0; i < szFindNum; i++)
        {
            int iObj = findNums[i];  
            // 遍历全集
            int idxFind = -1;
            int j = 0;
            for(j = 0; j < szNums; j++)
            {
                if (idxFind >= 0)
                {
                    // 若找到相等值（序号大于等于0），则开始找大于子集数的第1个值
                    if (nums[j] > iObj)
                    {
                        vecResult.push_back(nums[j]);
                        break;
                    }
                }
                else
                {      
                    // 在全集中找到相等值，标记相等值序号
                    if (nums[j] == iObj)
                    {
                        idxFind = j;
                    }
                }
            }
            // 在全集中未找到大值，填-1
            if (j == szNums)
            {
                vecResult.push_back(-1);
            }
        }

        return vecResult;
    }

    /*
        函数名：isVecSame
        功能：比较两个vector是否相等
        参数：vec1[IN]，比较对象1
                vec2[IN]，比较对象2
        返回值：bool。
                    true：相等
                    false：不等
    */
    static bool isVecSame(vector<int>& vec1, vector<int>& vec2)
    {
        // vector数量不等，返回false
        if (vec1.size() != vec2.size())
        {
            return false;
        }

        // vector值不等，返回false
        for (int i = 0; i < vec1.size(); i++)
        {
            if(vec1.at(i) != vec2.at(i))
            {
                return false;
            }
        }

        return true;
    }
};
#endif OJ_H
