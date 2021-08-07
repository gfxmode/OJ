#include "string"
#include "map"
#include "vector"

using namespace std;

class Solution {
private:
    vector<vector<int>> m_vecAns;
    vector<int> m_vecTmp;
    vector<bool> m_vecAccess;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int maxLen = nums.size();
        m_vecTmp.resize(maxLen, 0);
        m_vecAccess.resize(maxLen, false);

        recursiveCals(nums, 0);

        return m_vecAns;
    }

    void recursiveCals(vector<int>& nums, int idx) {
        int maxLen = nums.size();
        if (idx == maxLen) {
            m_vecAns.emplace_back(m_vecTmp);
            return;
        }

        for (int i = 0; i < maxLen; ++i) {
            if (!m_vecAccess[i]) {
                m_vecAccess[i] = true;
                m_vecTmp[idx] = nums[i];
                recursiveCals(nums, idx + 1);

                m_vecAccess[i] = false;
            }
        }
    }
};
