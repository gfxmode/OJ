#ifndef __OJ_TEST_H__
#define __OJ_TEST_H__
#include <cppunit/extensions/HelperMacros.h>
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

#define CHECK_NULL(ptr, ret) \
    { \
        if (NULL == ptr) \
        { \
            printf("ptr is null"); \
            return ret; \
        } \
    }

class OJTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(OJTest);    // 参数为本测试类名
    CPPUNIT_TEST(testCase01);      // 参数为测试函数名，与下面声明的测试函数对应
    CPPUNIT_TEST_SUITE_END();

public:
    OJTest(){};
    ~OJTest(){};
    void setUp()
    {
        // 在这里进行测试的初始化工作
    }

    void tearDown()
    {
        // 在这里进行测试完毕后的清理工作
    }

    void testCase01();  // 测试函数，用来测试目标类的某一个细节

private:
    // 将一维数组转为Vecotr<int>
    vector<int> cvtArrayToVec(int* pArr, int num);
    // 将一维数组按行列数转为Vector<Vecotr<int>>
    vector<vector<int>> cvtDoubleArrayToVec(int* pArr, int numRow, int numCol);

    /* 比较2个vector<vector<int>>是否一致。
     * 返回值: 是:true，否:false
     */
    bool compareVec(const vector<vector<int>>& vecA, const vector<vector<int>>& vecB);
};

#endif // __OJ_TEST_H__

