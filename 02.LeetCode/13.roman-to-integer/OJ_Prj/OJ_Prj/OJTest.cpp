#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(3, objOJ.romanToInt("III"));
}

void OJTest::testCase02()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(4, objOJ.romanToInt("IV"));
}

void OJTest::testCase03()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(9, objOJ.romanToInt("IX"));
}

void OJTest::testCase04()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(58, objOJ.romanToInt("LVIII"));
}

void OJTest::testCase05()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(1994, objOJ.romanToInt("MCMXCIV"));
}

