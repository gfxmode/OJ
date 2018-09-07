#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest");

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    vector<int> vecInput;
    vecInput.push_back(2);
    vecInput.push_back(2);
    vecInput.push_back(1);

    CPPUNIT_ASSERT_EQUAL(1, objOJ.singleNumber(vecInput));
}

void OJTest::testCase02()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;

    vector<int> vecInput;
    vecInput.push_back(4);
    vecInput.push_back(1);
    vecInput.push_back(2);
    vecInput.push_back(1);
    vecInput.push_back(2);

    CPPUNIT_ASSERT_EQUAL(4, objOJ.singleNumber(vecInput));
}

