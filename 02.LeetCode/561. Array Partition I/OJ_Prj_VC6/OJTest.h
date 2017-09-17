#ifndef OJ_TEST_H
#define OJ_TEST_H 
#include <cppunit/extensions/HelperMacros.h>

class OJTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(OJTest);    // 参数为本测试类名
    CPPUNIT_TEST(testCase01);        // 参数为测试函数名，与下面声明的测试函数对应
    CPPUNIT_TEST_SUITE_END();

public:
    OJTest(){};
    ~OJTest(){};
    void setUp() {
        // 在这里进行测试的初始化工作
    }

    void tearDown() {
        // 在这里进行测试完毕后的清理工作
    }

    void testCase01();  // 测试函数，用来测试目标类的某一个细节
}; 

#endif // OJ_TEST_H 