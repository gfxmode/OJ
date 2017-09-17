#include "OJTest.h"
#include "OJ.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类
#include "ListNode.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;
    int arrInput[3] = {1, 1, 2};
    int arrTarget[2] = {1, 2};
    ListNode *ptrHead = new ListNode(arrInput, 3);
    
    ListNode *ptrTarget = new ListNode(arrTarget, 2);
    ListNode *ptrResult = objOJ.deleteDuplicates(ptrHead);

    bool result = ListNode::isValueSame(ptrResult, ptrTarget);

    CPPUNIT_ASSERT_EQUAL(true, result);
} 

void OJTest::testCase02()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    OJ objOJ;
    int arrInput[5] = {1, 1, 2, 3, 3};
    int arrTarget[3] = {1, 2, 3};
    ListNode *ptrHead = new ListNode(arrInput, 5);
    
    ListNode *ptrTarget = new ListNode(arrTarget, 3);
    ListNode *ptrResult = objOJ.deleteDuplicates(ptrHead);
    
    bool result = ListNode::isValueSame(ptrResult, ptrTarget);
    
    CPPUNIT_ASSERT_EQUAL(true, result);
} 