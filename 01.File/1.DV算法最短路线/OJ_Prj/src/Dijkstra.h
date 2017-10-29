/********************************************************************
    created:    2017/09/17
    created:    17:9:2017   12:51
    filename:   Dijkstra.h
    file base:  Dijkstra
    file ext:   h
    author:     gfxmode@live.com
    purpose:    Dijkstra�㷨������DV�㷨��̾���
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

    /*  ��������init
        ���ܣ���ʼ�����������
    */
    void init();

    /*  ��������addPoint2PointDist
        ���ܣ����2��֮��ľ���
        ��Σ�
            idPoint1[IN]����1 ID��
            idPoint2[IN]����2 ID��
            cost[IN]��2��֮��ľ���
        ���أ�int
            ֵ0������
            ֵ-1���ظ��㣬���ʧ��
     */
    int addPoint2PointDist(int idPoint1, int idPoint2, unsigned int dist);

    /*  ��������calcShortestRoute
        ���ܣ��������·��
        ��Σ�
            idFromPoint[IN]����ʼ��ID��
            idDestPoint[IN]��Ŀ�ĵ�ID��
            vecShortPath[OUT]�����·�����
        ���أ�int��2������̾���
     */
    int calcShortestRoute(int idFromPoint, int idDestPoint, VecInt& vecShortPath);

private:
    /*  ��������calcShortestRoute
        ���ܣ���ȡ���·���ڵ㣬����䵽vecShortPath��
        ��Σ�
            idStart[IN]����ʼ��ID��
            idEnd[IN]��Ŀ�ĵ�ID��
            vecShortPath[OUT]�����·�����
        ���أ���
    */
    void getShortPath(int idStart, int idEnd, VecInt& vecShortPath);

    /*  ��������isRouteExist
        ���ܣ��ж�m_arrRoute�����з��Ѵ���·��
        ��Σ�
            id1[IN]
            id2[IN]
        ���أ���
    */
    bool isRouteExist(int id1, int id2);

    /*  ��������isPointExist
        ���ܣ��ж�m_vecU�ڵ����Ƿ�����id
        ��Σ�
            id[IN]����ӵ�id��
            vecU[IN]��δ������Ľڵ㼯
        ���أ�bool��=true���Ѵ��ڣ�=false��������
    */
    bool isPointExist(int id, VecInt& vecU);

    /*  ��������removeVecPoint
        ���ܣ�m_vecUԴ�ڵ�vectorɾ��ָ��id��Ԫ��
        ��Σ�
            id[IN]����ӵ�id��
            vecU[IN]��δ������Ľڵ㼯
        ���أ���
    */
    void removeVecPoint(int id, VecInt& vecU);

private:
    // ·�ɱ�
    unsigned int m_arrRoute[MAX_POINT_NUM][MAX_POINT_NUM];

    // ��¼ǰ���ڵ㣬Ѱ�����·��ʱ�����ڼ�¼ǰ���ڵ�
    unsigned int m_arrPrev[MAX_POINT_NUM];

    // vecS��Դ�㣻vecU��δ�����ĵ�
    VecInt m_vecS, m_vecU;
};
#endif __DIJKSTRA_H__
