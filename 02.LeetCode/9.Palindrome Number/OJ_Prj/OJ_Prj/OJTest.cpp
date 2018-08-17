#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    CPPUNIT_ASSERT_EQUAL(true, objOJ.isPalindrome(1221));
    CPPUNIT_ASSERT_EQUAL(false, objOJ.isPalindrome(-1221));
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isPalindrome(0));
    CPPUNIT_ASSERT_EQUAL(false, objOJ.isPalindrome(12345));
}
