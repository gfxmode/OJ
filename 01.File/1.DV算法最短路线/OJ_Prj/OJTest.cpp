#include "OJTest.h"
#include "src/Dijkstra.h"  // ����ΪҪ���Ե�Ŀ�����ͷ�ļ�·������Ϊ����ʱҪ�õ�Demo��

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // �����Demo����в��ԣ�����ʹ��CPPUNIT_ASSERT��CPPUNIT_ASSERT_EQUAL��������
    CDijkstra objOJ;
    objOJ.addPoint2PointDist(1, 6, 14);
    objOJ.addPoint2PointDist(1, 3, 9);
    objOJ.addPoint2PointDist(1, 2, 7);
    objOJ.addPoint2PointDist(6, 5, 9);
    objOJ.addPoint2PointDist(6, 3, 2);
    objOJ.addPoint2PointDist(3, 4, 11);
    objOJ.addPoint2PointDist(3, 2, 10);
    objOJ.addPoint2PointDist(2, 4, 15);
    objOJ.addPoint2PointDist(4, 5, 6);

    CPPUNIT_ASSERT_EQUAL(20, objOJ.calcShortestRoute(1, 5));
} 