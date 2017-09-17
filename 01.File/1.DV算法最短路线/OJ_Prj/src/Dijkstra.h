/********************************************************************
    created:    2017/09/17
    created:    17:9:2017   12:51
    filename:   Dijkstra.h
    file base:  Dijkstra
    file ext:   h
    author:     gfxmode@live.com
    purpose:    Dijkstra�㷨������DV�㷨��̾���
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
        ���أ�int��2������̾���
     */
    int calcShortestRoute(int idFromPoint, int idDestPoint);

private:
    // �ж�m_arrRoute�����з��Ѵ���·��
    bool isRouteExist(int id1, int id2);
    // �ж�m_vecU�ڵ����Ƿ�����id
    bool isPointExist(int id, vector<int> &vecU);
    // m_vecUԴ�ڵ�vectorɾ��ָ��id��Ԫ��
    void removeVecPoint(int id, vector<int> &vecU);
private:
    // ·�ɱ�
    unsigned int m_arrRoute[MAX_POINT_NUM][MAX_POINT_NUM];
    // vecS��Դ�㣻vecU��δ�����ĵ�
    vector<int> m_vecS, m_vecU;
};
#endif __DIJKSTRA_H_
