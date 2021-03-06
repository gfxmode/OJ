#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;
    vector<string> vecWords;
    vecWords.push_back("Hello");
    vecWords.push_back("Alaska");
    vecWords.push_back("Dad");
    vecWords.push_back("Peace");
    int size = objOJ.findWords(vecWords).size();
    CPPUNIT_ASSERT_EQUAL(2, size);
} 