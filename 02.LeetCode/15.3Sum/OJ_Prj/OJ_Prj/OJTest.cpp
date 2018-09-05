#include "OJTest.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    // ��ʼ����������
    int pArrInt[6] = {-1, 0, 1, 2, -1, -4};
    vector<int>& vecInput = cvtArrayToVec(pArrInt, 6);
    // ��ʼ��Ԥ�ڽ������
    int pArrExpResult[2 * 3] = {-1, -1, 2, -1, 0, 1};
    vector<vector<int>>& vecExpectResult = cvtDoubleArrayToVec(pArrExpResult, 2, 3);

    // ����threeSum���
    vector<vector<int>>& vecResult = objOJ.threeSum(vecInput);

    CPPUNIT_ASSERT_EQUAL(true, compareVec(vecExpectResult, vecResult));
}

// ��һά����תΪVecotr<int>
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

// ��һά���鰴������תΪVector<Vecotr<int>>
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

/* �Ƚ�2��vector<vector<int>>�Ƿ�һ�¡�
 * ����ֵ: ��:true����:false
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
