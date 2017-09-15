#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arr1[3] = {4, 1, 2};
    int arr2[4] = {1, 3, 4, 2};
    int arrResult[3] = {-1, 3, -1};

    vector<int> vec1(arr1, arr1 + 3);
    vector<int> vec2(arr2, arr2 + 4);
    vector<int> vecResult(arrResult, arrResult + 3);

    bool bResult = OJ::isVecSame(vecResult, objOJ.nextGreaterElement(vec1, vec2));
    CPPUNIT_ASSERT_EQUAL(true, bResult);
} 

void OJTest::testCase02()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arr1[5] = {1,3,5,2,4};
    int arr2[7] = {6,5,4,3,2,1,7};
    int arrResult[5] = {7,7,7,7,7};
    
    vector<int> vec1(arr1, arr1 + 5);
    vector<int> vec2(arr2, arr2 + 7);
    vector<int> vecResult(arrResult, arrResult + 5);
    
    bool bResult = OJ::isVecSame(vecResult, objOJ.nextGreaterElement(vec1, vec2));
    CPPUNIT_ASSERT_EQUAL(true, bResult);
} 