#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;
    int arrInput[] = {1, 2, 3, 4};
    int arrOutput[] = {4, 3, 2, 1};

    ListNode lsInput = ListNode(arrInput, 4);
    ListNode* ptrLsOutput = objOJ.reverseList(&lsInput);

    CPPUNIT_ASSERT_EQUAL(true, objOJ.checkListValue(ptrLsOutput, arrOutput));
} 