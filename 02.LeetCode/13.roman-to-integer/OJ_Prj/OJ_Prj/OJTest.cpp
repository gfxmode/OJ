#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(3, objOJ.romanToInt("III"));
}

void OJTest::testCase02()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(4, objOJ.romanToInt("IV"));
}

void OJTest::testCase03()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(9, objOJ.romanToInt("IX"));
}

void OJTest::testCase04()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(58, objOJ.romanToInt("LVIII"));
}

void OJTest::testCase05()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(1994, objOJ.romanToInt("MCMXCIV"));
}

