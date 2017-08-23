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

    int maxSubArray(vector<int>& nums) {
        int thisSum = nums[0];
        int maxSum = nums[0];
        // dp[n] = max(0, dp[n - 1]) + nums[n]
        for (unsigned int i = 1; i < nums.size(); i++)
        {
            if (thisSum < 0)
            {
                thisSum = nums[i];
            }
            else
            {
                thisSum += nums[i];
            }

            if (thisSum > maxSum)
            {
                maxSum = thisSum;
            }
        }

        return maxSum;
    }
};
#endif OJ_H
