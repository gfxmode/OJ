#ifndef OJ_TEST_H
#define OJ_TEST_H 
#include <cppunit/extensions/HelperMacros.h>

class OJTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(OJTest);    // ����Ϊ����������
    CPPUNIT_TEST(testCase01);        // ����Ϊ���Ժ������������������Ĳ��Ժ�����Ӧ
    CPPUNIT_TEST_SUITE_END();

public:
    OJTest(){};
    ~OJTest(){};
    void setUp() {
        // ��������в��Եĳ�ʼ������
    }

    void tearDown() {
        // ��������в�����Ϻ��������
    }

    void testCase01();  // ���Ժ�������������Ŀ�����ĳһ��ϸ��
}; 

#endif // OJ_TEST_H 