#include "string"
#include "map"
#include "vector"

using namespace std;

class Solution {
private:
    vector<int> m_vecTmp;
    vector<bool> m_vecAccess;
    set<vector<int>> m_setAns;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        m_vecAccess.resize(n, false);
        m_vecTmp.resize(n, 0);

        int maxLength = nums.size();
        recursiveCalc(nums, 0, maxLength);

        // set转vector输出
        vector<vector<int>> m_vecAns(m_setAns.begin(), m_setAns.end());
        return m_vecAns;
    }

    // 递归计算, 输入数组, 遍历到第1个索引了
    void recursiveCalc(vector<int>& nums, int idx, int maxLen) {
        if (idx == maxLen) {
            m_setAns.emplace(m_vecTmp);
            return;
        }

        for (int i = 0; i < maxLen; ++i) {
            if (!m_vecAccess[i]) {
                m_vecAccess[i] = true;
                m_vecTmp[idx] = nums[i];
                recursiveCalc(nums, idx + 1, maxLen);
                m_vecAccess[i] = false;
            }
        }
    }
};