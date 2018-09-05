#ifndef __OJ_H__
#define __OJ_H__

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> vecRet;
        // 用于结果去重
        map<string, vector<int>> mapRet;

        // 对输入项排序
        sort(nums.begin(), nums.end());

        size_t lenVec = nums.size();
        // 数据过短，则返回空
        if (lenVec < 3)
        {
            return vecRet;
        }

        // 所有数相等时，若都不为0，则直接返回
        if ((nums[0] == nums[lenVec - 1]) && (nums[0] != 0))
        {
            return vecRet;
        }

        /*
            对于元素 S[i] ， 最后的答案可以分为两种，包含 S[i] 的，和不包含 S[i] 的。当包含 S[i] 的情况都找到后，后续就可以不用在考虑 S[i] 。

            对于 S[i] ， l = i+1, r = len-1 。若 s[i] + S[l] + S[r] == 0， 则为原问题的一个解。

            当 S[i] + S[l] > -S[r] 时，则 r--
            当 S[i] + S[l] < -S[r] 时，则 l++
            当 S[i] + S[i] = -S[r] 时， 表示是原问题的一个解，则 l++, r--;
        */
        for (size_t i = 0; i < (lenVec - 1); ++i)
        {
            size_t posLeft = i + 1;
            size_t posRight = lenVec - 1;
            while (posRight > posLeft)
            {
                int sum = (nums[i] + nums[posLeft]) + nums[posRight];
                if (sum > 0)
                {
                    --posRight;
                }
                else if (sum < 0)
                {
                    ++posLeft;
                }
                else
                {
                    vector<int> vecTmp;
                    vecTmp.push_back(nums[i]);
                    vecTmp.push_back(nums[posLeft]);
                    vecTmp.push_back(nums[posRight]);

                    string key = to_string((long long)nums[i]) + "," +
                                            to_string((long long)nums[posLeft]) + "," +
                                            to_string((long long)nums[posRight]);

                    mapRet[key] = vecTmp;

                    // 优化所有数为0的情况
                    if ((nums[i] == nums[posRight]) && (nums[i] == 0))
                    {
                        break;
                    }

                    --posRight;
                    ++posLeft;
                }
            }
        }

        // map转为vector
        map<string, vector<int>>::iterator iter = mapRet.begin();
        for (; mapRet.end() != iter; ++iter)
        {
            vecRet.push_back(iter->second);
        }

        return vecRet;
    }
};
#endif // __OJ_H__

