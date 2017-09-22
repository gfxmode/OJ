#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    vector<string> vecWords;
    vecWords.push_back("Hello");
    vecWords.push_back("Alaska");
    vecWords.push_back("Dad");
    vecWords.push_back("Peace");
    int size = objOJ.findWords(vecWords).size();
    CPPUNIT_ASSERT_EQUAL(2, size);
} 