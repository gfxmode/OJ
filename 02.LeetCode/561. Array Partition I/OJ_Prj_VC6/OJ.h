#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    int arrayPairSum(vector<int>& nums) 
    {
        // sort nums vector ascending
        sort(nums.begin(), nums.end(), OJ::myfunction);

        // sum each other items in vector
        int sum = 0;
        for (int i = 0; i < (nums.size() / 2); i++)
        {
            sum += nums.at(2 * i);
        }

        return sum;
    }
private:
    static bool myfunction (int i, int j) { return (i < j); } 
};
#endif OJ_H
