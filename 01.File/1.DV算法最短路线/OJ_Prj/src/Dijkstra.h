/********************************************************************
    created:    2017/09/17
    created:    17:9:2017   12:51
    filename:   Dijkstra.h
    file base:  Dijkstra
    file ext:   h
    author:     gfxmode@live.com
    purpose:    Dijkstra算法，计算DV算法最短距离
*********************************************************************/

#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <string>
#include <vector>
#include <algorithm>

const int MAX_POINT_NUM = 100;
const int MAX_ROUTE_DIST = 0xFFFFFFFF;

typedef std::vector<int> VecInt;

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
            vecShortPath[OUT]，最短路径点号
        返回：int，2点间的最短距离
     */
    int calcShortestRoute(int idFromPoint, int idDestPoint, VecInt& vecShortPath);

private:
    /*  函数名：calcShortestRoute
        功能：获取最短路径节点，并填充到vecShortPath中
        入参：
            idStart[IN]，起始点ID号
            idEnd[IN]，目的点ID号
            vecShortPath[OUT]，最短路径点号
        返回：无
    */
    void getShortPath(int idStart, int idEnd, VecInt& vecShortPath);

    /*  函数名：isRouteExist
        功能：判断m_arrRoute数组中否已存在路线
        入参：
            id1[IN]
            id2[IN]
        返回：无
    */
    bool isRouteExist(int id1, int id2);

    /*  函数名：isPointExist
        功能：判断m_vecU节点中是否已有id
        入参：
            id[IN]，添加的id号
            vecU[IN]，未被计算的节点集
        返回：bool。=true，已存在；=false，不存在
    */
    bool isPointExist(int id, VecInt& vecU);

    /*  函数名：removeVecPoint
        功能：m_vecU源节点vector删除指定id的元素
        入参：
            id[IN]，添加的id号
            vecU[IN]，未被计算的节点集
        返回：无
    */
    void removeVecPoint(int id, VecInt& vecU);

private:
    // 路由表
    unsigned int m_arrRoute[MAX_POINT_NUM][MAX_POINT_NUM];

    // 记录前驱节点，寻找最短路径时，用于记录前驱节点
    unsigned int m_arrPrev[MAX_POINT_NUM];

    // vecS，源点；vecU，未遍历的点
    VecInt m_vecS, m_vecU;
};
#endif __DIJKSTRA_H__
