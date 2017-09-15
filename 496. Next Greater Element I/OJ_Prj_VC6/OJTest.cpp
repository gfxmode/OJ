#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
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
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
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