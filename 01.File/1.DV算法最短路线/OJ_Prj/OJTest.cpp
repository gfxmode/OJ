#include "OJTest.h"
#include "src/Dijkstra.h"  // 这里为要测试的目标类的头文件路径，因为测试时要用到Demo类

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(OJTest, "OJTest"); 

void OJTest::testCase01()
{
    // 这里对Demo类进行测试，可以使用CPPUNIT_ASSERT、CPPUNIT_ASSERT_EQUAL等来断言
    CDijkstra objOJ;

    // 添加计算前，类对象需要初始化
    objOJ.init();

    // 添加路径点
    objOJ.addPoint2PointDist(1, 6, 14);
    objOJ.addPoint2PointDist(1, 3, 9);
    objOJ.addPoint2PointDist(1, 2, 7);
    objOJ.addPoint2PointDist(6, 5, 9);
    objOJ.addPoint2PointDist(6, 3, 2);
    objOJ.addPoint2PointDist(3, 4, 11);
    objOJ.addPoint2PointDist(3, 2, 10);
    objOJ.addPoint2PointDist(2, 4, 15);
    objOJ.addPoint2PointDist(4, 5, 6);

    VecInt vecPath;

    int iDistance = objOJ.calcShortestRoute(1, 5, vecPath);

    printf("Get shortest path distance=%d, path is:\n", iDistance);

    VecInt::iterator iter = vecPath.begin();
    for (; iter != vecPath.end(); ++iter)
    {
        printf("%d->", *iter);
    }
} 