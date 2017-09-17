/********************************************************************
    created:    2017/09/17
    created:    17:9:2017   12:51
    filename:   Dijkstra.h
    file base:  Dijkstra
    file ext:   h
    author:     gfxmode@live.com
    purpose:    Dijkstra算法，计算DV算法最短距离
*********************************************************************/

#ifndef __DIJKSTRA_H_
#define __DIJKSTRA_H_

#include <string>
#include <vector>

using namespace std;

const int MAX_POINT_NUM = 100;
const int MAX_ROUTE_DIST = 0xFFFFFFFF;

class CDijkstra
{
public:
    CDijkstra(void);
    ~CDijkstra(void);

    /*  函数名：init
        功能：初始化，清除数据
    */
    void init();

    /*  函数名：addPoint2PointDist
        功能：添加2点之间的距离
        入参：
            idPoint1[IN]，点1 ID号
            idPoint2[IN]，点2 ID号
            cost[IN]，2点之间的距离
        返回：int
            值0：正常
            值-1：重复点，添加失败
     */
    int addPoint2PointDist(int idPoint1, int idPoint2, unsigned int dist);

    /*  函数名：calcShortestRoute
        功能：计算最短路径
        入参：
            idFromPoint[IN]，起始点ID号
            idDestPoint[IN]，目的点ID号
        返回：int，2点间的最短距离
     */
    int calcShortestRoute(int idFromPoint, int idDestPoint);

private:
    // 判断m_arrRoute数组中否已存在路线
    bool isRouteExist(int id1, int id2);
    // 判断m_vecU节点中是否已有id
    bool isPointExist(int id, vector<int> &vecU);
    // m_vecU源节点vector删除指定id的元素
    void removeVecPoint(int id, vector<int> &vecU);
private:
    // 路由表
    unsigned int m_arrRoute[MAX_POINT_NUM][MAX_POINT_NUM];
    // vecS，源点；vecU，未遍历的点
    vector<int> m_vecS, m_vecU;
};
#endif __DIJKSTRA_H_
