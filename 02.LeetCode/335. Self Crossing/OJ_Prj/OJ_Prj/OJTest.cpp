#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;
    int arrInt[] = {2, 1, 1, 2};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isSelfCrossing(vecInt));
}

void OJTest::testCase02()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;
    int arrInt[] = {1, 2, 3, 4};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(false, objOJ.isSelfCrossing(vecInt));
}

void OJTest::testCase03()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;
    int arrInt[] = {1, 1, 1, 1};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isSelfCrossing(vecInt));
}