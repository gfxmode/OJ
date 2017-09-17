#include "Dijkstra.h"

CDijkstra::CDijkstra()
{
    init();
}

CDijkstra::~CDijkstra()
{

}

/*  ��������init
    ���ܣ���ʼ�����������
*/
void CDijkstra::init()
{
    m_vecS.clear();
    m_vecU.clear();
    memset(m_arrRoute, MAX_ROUTE_DIST, sizeof(int) * MAX_POINT_NUM * MAX_POINT_NUM);
}

/*  ��������isRouteExist
    �������ܣ��ж�m_arrRoute 2���·���Ƿ������
    ��Σ�
        id1[IN]����1 ID��
        id2[IN]����2 ID��
    ����ֵ��bool
            true��·���Ѵ���
            false��·�߲�����
*/ 
bool CDijkstra::isRouteExist(int id1, int id2)
{
    // �����������룬��·���Ѵ���
    if (MAX_ROUTE_DIST != m_arrRoute[id1][id2])
    {
        return true;
    }
    return false;
}

/*  ��������isPointExist
    �������ܣ��ж�m_vecU�е��Ƿ������
    ��Σ�
        id[IN]����ID��
    ����ֵ��bool
            true�����Ѵ���
            false���㲻����
*/
bool CDijkstra::isPointExist(int id, vector<int> &vecU)
{
    int sizeVec = vecU.size();
    for (int i = 0; i < sizeVec; ++i)
    {
        if (id == vecU[i])
        {
            return true;
        }
    }

    return false;
}

/*  ��������removeVecPoint
    �������ܣ�����idɾ��vector�е�Ԫ��
    ��Σ�
        id[IN]����ID��
*/
void CDijkstra::removeVecPoint(int id, vector<int> &vecU)
{
    vector<int>::iterator iter = vecU.begin();
    while (iter != vecU.end())
    {
        if(id == *iter)
        {
            vecU.erase(iter);
            break;
        }
        ++iter;
    }

    return;
}

/*  ��������addPoint2PointDist
    ���ܣ����2��֮��ľ��롣��������һ��
    ��Σ�
        idPoint1[IN]����1 ID��
        idPoint2[IN]����2 ID��
        cost[IN]��2��֮��ľ���
    ���أ�int
        ֵ0������
        ֵ-1��·���Ѵ��ڣ����ʧ��
 */
int CDijkstra::addPoint2PointDist(int idPoint1, int idPoint2, unsigned int dist)
{
    // У�����ID��Ч��
    if ((idPoint1 > MAX_POINT_NUM) || (idPoint2 > MAX_POINT_NUM) || (idPoint2 < 0) || (idPoint1 < 0))
    {
        return -1;
    }
    // У��·���Ƿ����
    if (!isRouteExist(idPoint1, idPoint2))
    {
        // �������·�ߣ������������
        m_arrRoute[idPoint1][idPoint2] = dist;
        m_arrRoute[idPoint2][idPoint1] = dist;
    }
    else
    {
        return -1;
    }

    // ��ӵ�δ����Դ�ڵ��б�
    if (!isPointExist(idPoint1, m_vecU))
    {
        m_vecU.push_back(idPoint1);
    }
    if (!isPointExist(idPoint2, m_vecU))
    {
        m_vecU.push_back(idPoint2);
    }

    return 0;
}

/*  ��������calcShortestRoute
    ���ܣ��������·��
    ��Σ�
        idFromPoint[IN]����ʼ��ID��
        idDestPoint[IN]��Ŀ�ĵ�ID��
    ���أ�int��2������̾���
 */
int CDijkstra::calcShortestRoute(int idFromPoint, int idDestPoint)
{
    unsigned int arrTmpDist[MAX_POINT_NUM] = {MAX_ROUTE_DIST};

    // ���ؼ������·��ʱ����Ҫ�Ƴ��ĵ�
    vector<int> vecIdToRemove;
    // ��1������ʼ��ѹ��Դ��vector������arrTmpDist��ֵ
    m_vecS.push_back(idFromPoint);
    removeVecPoint(idFromPoint, m_vecU);
    arrTmpDist[idFromPoint] = 0;
    vector<int>::iterator iter;
    for (iter = m_vecU.begin(); iter != m_vecU.end(); ++iter)
    {
        arrTmpDist[*iter] = m_arrRoute[idFromPoint][*iter];
    }
    unsigned int minValue = MAX_ROUTE_DIST;
    int idMinPoint = MAX_POINT_NUM;
    while (0 != m_vecU.size())
    {
        // ��2������vecU��ȡ������С�ĵ�k������vecS��
        minValue = MAX_ROUTE_DIST;
        idMinPoint = MAX_POINT_NUM;
        for (iter = m_vecU.begin(); iter != m_vecU.end(); ++iter)
        {
            if (arrTmpDist[*iter] < minValue)
            {
                minValue = arrTmpDist[*iter];
            }
        }
        for (iter = m_vecU.begin(); iter != m_vecU.end(); ++iter)
        {
            if (arrTmpDist[*iter] == minValue)
            {
                idMinPoint = *iter;
                break;
            }
        }
        
        // ��3�����Ե�kΪ���ǵ㣬�޸�arrTmpDist�е�ֵ������k���õ��ֵС��ԭֵ�������ֵ
        m_vecS.push_back(idMinPoint);
        removeVecPoint(idMinPoint, m_vecU);
        for(iter = m_vecU.begin(); iter != m_vecU.end(); ++iter)
        {
            unsigned int uiRouteValue = m_arrRoute[idMinPoint][*iter];
            if ((MAX_ROUTE_DIST != uiRouteValue) &&(minValue + uiRouteValue) < arrTmpDist[*iter])
            {
                arrTmpDist[*iter] = (minValue + uiRouteValue);
            }
            else if(MAX_ROUTE_DIST != uiRouteValue)
            {
                vecIdToRemove.push_back(*iter);
            }
        }
    }
    
    return arrTmpDist[idDestPoint];
}
