#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(true, objOJ.isMatch("ab", ".*"));
}

void OJTest::testCase02()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(false, objOJ.isMatch("aa", "a"));
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isMatch("aa", "a*"));
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isMatch("aab", "c*a*b"));
    CPPUNIT_ASSERT_EQUAL(false, objOJ.isMatch("mississippi", "mis*is*p*."));
}


