#ifndef __OJ_TEST_H__
#define __OJ_TEST_H__
#include <cppunit/extensions/HelperMacros.h>
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

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
    CPPUNIT_TEST_SUITE(OJTest);    // ����Ϊ����������
    CPPUNIT_TEST(testCase01);      // ����Ϊ���Ժ������������������Ĳ��Ժ�����Ӧ
    CPPUNIT_TEST_SUITE_END();

public:
    OJTest(){};
    ~OJTest(){};
    void setUp()
    {
        // ��������в��Եĳ�ʼ������
    }

    void tearDown()
    {
        // ��������в�����Ϻ��������
    }

    void testCase01();  // ���Ժ�������������Ŀ�����ĳһ��ϸ��

private:
    // ��һά����תΪVecotr<int>
    vector<int> cvtArrayToVec(int* pArr, int num);
    // ��һά���鰴������תΪVector<Vecotr<int>>
    vector<vector<int>> cvtDoubleArrayToVec(int* pArr, int numRow, int numCol);

    /* �Ƚ�2��vector<vector<int>>�Ƿ�һ�¡�
     * ����ֵ: ��:true����:false
     */
    bool compareVec(const vector<vector<int>>& vecA, const vector<vector<int>>& vecB);
};

#endif // __OJ_TEST_H__

