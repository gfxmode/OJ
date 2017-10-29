#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arrInt[] = {2, 1, 1, 2};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isSelfCrossing(vecInt));
}

void OJTest::testCase02()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arrInt[] = {1, 2, 3, 4};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(false, objOJ.isSelfCrossing(vecInt));
}

void OJTest::testCase03()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arrInt[] = {1, 1, 1, 1};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(true, objOJ.isSelfCrossing(vecInt));
}