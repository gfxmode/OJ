#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(true, objOJ.isMatch("ab", ".*"));
}

void OJTest::testCase02()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(false, objOJ.isMatch("aa", "a"));
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isMatch("aa", "a*"));
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isMatch("aab", "c*a*b"));
    CPPUNIT_ASSERT_EQUAL(false, objOJ.isMatch("mississippi", "mis*is*p*."));
}


