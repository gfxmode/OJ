#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    //CPPUNIT_ASSERT_EQUAL((string)("aba"), objOJ.longestPalindrome("babad"));
    CPPUNIT_ASSERT_EQUAL((string)("bb"), objOJ.longestPalindrome("cbbd"));
} 