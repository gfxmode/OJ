#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    int arrInput[] = {1, 2, 3, 4};
    int arrOutput[] = {4, 3, 2, 1};

    ListNode lsInput = ListNode(arrInput, 4);
    ListNode* ptrLsOutput = objOJ.reverseList(&lsInput);

    CPPUNIT_ASSERT_EQUAL(true, objOJ.checkListValue(ptrLsOutput, arrOutput));
} 