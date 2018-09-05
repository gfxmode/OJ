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
        // ���ڽ��ȥ��
        map<string, vector<int>> mapRet;

        // ������������
        sort(nums.begin(), nums.end());

        size_t lenVec = nums.size();
        // ���ݹ��̣��򷵻ؿ�
        if (lenVec < 3)
        {
            return vecRet;
        }

        // ���������ʱ��������Ϊ0����ֱ�ӷ���
        if ((nums[0] == nums[lenVec - 1]) && (nums[0] != 0))
        {
            return vecRet;
        }

        /*
            ����Ԫ�� S[i] �� ���Ĵ𰸿��Է�Ϊ���֣����� S[i] �ģ��Ͳ����� S[i] �ġ������� S[i] ��������ҵ��󣬺����Ϳ��Բ����ڿ��� S[i] ��

            ���� S[i] �� l = i+1, r = len-1 ���� s[i] + S[l] + S[r] == 0�� ��Ϊԭ�����һ���⡣

            �� S[i] + S[l] > -S[r] ʱ���� r--
            �� S[i] + S[l] < -S[r] ʱ���� l++
            �� S[i] + S[i] = -S[r] ʱ�� ��ʾ��ԭ�����һ���⣬�� l++, r--;
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

                    // �Ż�������Ϊ0�����
                    if ((nums[i] == nums[posRight]) && (nums[i] == 0))
                    {
                        break;
                    }

                    --posRight;
                    ++posLeft;
                }
            }
        }

        // mapתΪvector
        map<string, vector<int>>::iterator iter = mapRet.begin();
        for (; mapRet.end() != iter; ++iter)
        {
            vecRet.push_back(iter->second);
        }

        return vecRet;
    }
};
#endif // __OJ_H__

