#ifndef __OJ_TEST_H__
#define __OJ_TEST_H__
#include <cppunit/extensions/HelperMacros.h>

class OJTest: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(OJTest);    // ����Ϊ����������
    CPPUNIT_TEST(testCase01);      // ����Ϊ���Ժ������������������Ĳ��Ժ�����Ӧ
    CPPUNIT_TEST(testCase02);      // ����Ϊ���Ժ������������������Ĳ��Ժ�����Ӧ
    CPPUNIT_TEST(testCase03);      // ����Ϊ���Ժ������������������Ĳ��Ժ�����Ӧ
    CPPUNIT_TEST(testCase04);      // ����Ϊ���Ժ������������������Ĳ��Ժ�����Ӧ
    CPPUNIT_TEST(testCase05);      // ����Ϊ���Ժ������������������Ĳ��Ժ�����Ӧ
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
    void testCase02();  // ���Ժ�������������Ŀ�����ĳһ��ϸ��
    void testCase03();  // ���Ժ�������������Ŀ�����ĳһ��ϸ��
    void testCase04();  // ���Ժ�������������Ŀ�����ĳһ��ϸ��
    void testCase05();  // ���Ժ�������������Ŀ�����ĳһ��ϸ��
};

#endif // __OJ_TEST_H__

