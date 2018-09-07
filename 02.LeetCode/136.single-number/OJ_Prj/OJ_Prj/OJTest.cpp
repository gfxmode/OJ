#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    vector<int> vecInput;
    vecInput.push_back(2);
    vecInput.push_back(2);
    vecInput.push_back(1);

    CPPUNIT_ASSERT_EQUAL(1, objOJ.singleNumber(vecInput));
}

void OJTest::testCase02()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    vector<int> vecInput;
    vecInput.push_back(4);
    vecInput.push_back(1);
    vecInput.push_back(2);
    vecInput.push_back(1);
    vecInput.push_back(2);

    CPPUNIT_ASSERT_EQUAL(4, objOJ.singleNumber(vecInput));
}

