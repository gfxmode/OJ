#include "OJTest.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    // 初始化测试数据
    int pArrInt[6] = {-1, 0, 1, 2, -1, -4};
    vector<int>& vecInput = cvtArrayToVec(pArrInt, 6);
    // 初始化预期结果数据
    int pArrExpResult[2 * 3] = {-1, -1, 2, -1, 0, 1};
    vector<vector<int>>& vecExpectResult = cvtDoubleArrayToVec(pArrExpResult, 2, 3);

    // 计算threeSum结果
    vector<vector<int>>& vecResult = objOJ.threeSum(vecInput);

    CPPUNIT_ASSERT_EQUAL(true, compareVec(vecExpectResult, vecResult));
}

// 将一维数组转为Vecotr<int>
vector<int> OJTest::cvtArrayToVec(int* pArr, int num)
{
    vector<int> vecRet;
    CHECK_NULL(pArr, vecRet);

    for (int i = 0; i < num; ++i)
    {
        if (NULL != pArr)
        {
            vecRet.push_back(*pArr);
            ++pArr;
        }
    }

    return vecRet;
}

// 将一维数组按行列数转为Vector<Vecotr<int>>
vector<vector<int>> OJTest::cvtDoubleArrayToVec(int* pArr, int numRow, int numCol)
{
    vector<vector<int>> vecRet;
    CHECK_NULL(pArr, vecRet);

    for (int i = 0; i < numRow; ++i)
    {
        vector<int> vecRow;
        for (int j = 0; j < numCol; ++j)
        {
            if (NULL != pArr)
            {
                vecRow.push_back(*pArr);
                ++pArr;
            }
        }

        vecRet.push_back(vecRow);
    }

    return vecRet;
}

/* 比较2个vector<vector<int>>是否一致。
 * 返回值: 是:true，否:false
 */
bool OJTest::compareVec(const vector<vector<int>>& vecA, const vector<vector<int>>& vecB)
{
    if (vecA.size() != vecB.size())
    {
        return false;
    }

    size_t lenVec = vecA.size();
    for (size_t i = 0; i < lenVec; ++i)
    {
        const vector<int>& vecASub = vecA[i];
        const vector<int>& vecBSub = vecB[i];
        if (vecASub.size() != vecBSub.size())
        {
            return false;
        }

        size_t lenSubVec = vecA.size();
        for (size_t j = 0; j < lenSubVec; ++j)
        {
            if (vecASub[j] != vecBSub[j])
            {
                return false;
            }
        }
    }

    return true;
}
