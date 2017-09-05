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

    bool canPartition(vector<int>& nums) 
    {
        // calculate sum
        int sum = 0;
        vector<int>::iterator iter;
        for (iter = nums.begin(); iter != nums.end(); ++iter)
        {
            sum += *iter;
        }

        // if sum is odd or zero, return false
        if ((0 ==sum) || (1 == sum % 2))
        {
            return false;
        }

        int arrDp[1000] = {0};
        arrDp[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {  
            for(int j = sum/2; j >= nums[i]; j--)
                arrDp[j] = arrDp[j] || arrDp[j-nums[i]];
        }  
        return arrDp[sum/2];
    }
};
#endif OJ_H
