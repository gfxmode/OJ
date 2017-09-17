#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
	// �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
	OJ objOJ;
	CPPUNIT_ASSERT_EQUAL(false, objOJ.wordPattern("abba", "dog dog dog dog"));
	CPPUNIT_ASSERT_EQUAL(true, objOJ.wordPattern("abba", "dog cat cat dog"));
    CPPUNIT_ASSERT_EQUAL(false, objOJ.wordPattern("abba", "dog cat cat fish"));
    CPPUNIT_ASSERT_EQUAL(false, objOJ.wordPattern("aaaa", "dog cat cat dog"));
} 