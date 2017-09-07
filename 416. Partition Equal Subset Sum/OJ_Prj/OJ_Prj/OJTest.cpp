#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arrInt[4] = {1, 5, 11, 5};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(true, objOJ.canPartition(vecInt));
}

void OJTest::testCase02()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arrInt[4] = {1000, 1000, 1000, 1000};
    vector<int> vecInt(arrInt, arrInt + 4);
    CPPUNIT_ASSERT_EQUAL(true, objOJ.canPartition(vecInt));
}