#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
	// �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
	OJ objOJ;
	CPPUNIT_ASSERT_EQUAL((string)("s'teL ekat edoCteeL tsetnoc"), objOJ.reverseWords("Let's take LeetCode contest"));
} 