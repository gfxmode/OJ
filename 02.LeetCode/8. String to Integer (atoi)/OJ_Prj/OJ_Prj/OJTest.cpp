#include "OJTest.h"
#include "OJ.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    OJ objOJ;
    CPPUNIT_ASSERT_EQUAL((int)-2147483648, objOJ.myAtoi(string("-18446744073709551617")));
    CPPUNIT_ASSERT_EQUAL(2147483647, objOJ.myAtoi(string("18446744073709551617")));
    CPPUNIT_ASSERT_EQUAL(0, objOJ.myAtoi(string("    b11228552307")));
    CPPUNIT_ASSERT_EQUAL((int)-2147483648, objOJ.myAtoi(string("      -11919730356x")));
    CPPUNIT_ASSERT_EQUAL(-2147483641, objOJ.myAtoi(string("-2147483641--")));
    CPPUNIT_ASSERT_EQUAL(1000000009, objOJ.myAtoi(string("    1000000009")));
    CPPUNIT_ASSERT_EQUAL(0, objOJ.myAtoi(string("-    2147483641")));
    CPPUNIT_ASSERT_EQUAL(1, objOJ.myAtoi(string("+1")));
    CPPUNIT_ASSERT_EQUAL((int)-2147483648, (int)objOJ.myAtoi(string("-2147483648")));
    CPPUNIT_ASSERT_EQUAL((int)-2147483648, (int)objOJ.myAtoi(string("-2147483649")));
    CPPUNIT_ASSERT_EQUAL(2147483647, objOJ.myAtoi(string("+2147483648")));
}