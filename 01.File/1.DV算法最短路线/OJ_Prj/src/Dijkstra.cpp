#include "Dijkstra.h"

CDijkstra::CDijkstra()
{
    init();
}

CDijkstra::~CDijkstra()
{

}

/*  函数名：init
    功能：初始化，清除数据
*/
void CDijkstra::init()
{
    m_vecS.clear();
    m_vecU.clear();
    memset(m_arrRoute, MAX_ROUTE_DIST, sizeof(int) * MAX_POINT_NUM * MAX_POINT_NUM);
}

/*  函数名：isRouteExist
    函数功能：判断m_arrRoute 2点的路线是否已添加
    入参：
        id1[IN]，点1 ID号
        id2[IN]，点2 ID号
    返回值：bool
            true：路线已存在
            false：路线不存在
*/ 
bool CDijkstra::isRouteExist(int id1, int id2)
{
    // 若不是最大距离，则路线已存在
    if (MAX_ROUTE_DIST != m_arrRoute[id1][id2])
    {
        return true;
    }
    return false;
}

/*  函数名：isPointExist
    函数功能：判断m_vecU中点是否已添加
    入参：
        id[IN]，点ID号
    返回值：bool
            true：点已存在
            false：点不存在
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

/*  函数名：removeVecPoint
    函数功能：根据id删除vector中的元素
    入参：
        id[IN]，点ID号
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

/*  函数名：addPoint2PointDist
    功能：添加2点之间的距离。往返距离一样
    入参：
        idPoint1[IN]，点1 ID号
        idPoint2[IN]，点2 ID号
        cost[IN]，2点之间的距离
    返回：int
        值0：正常
        值-1：路线已存在，添加失败
 */
int CDijkstra::addPoint2PointDist(int idPoint1, int idPoint2, unsigned int dist)
{
    // 校验入参ID有效性
    if ((idPoint1 > MAX_POINT_NUM) || (idPoint2 > MAX_POINT_NUM) || (idPoint2 < 0) || (idPoint1 < 0))
    {
        return -1;
    }
    // 校验路线是否存在
    if (!isRouteExist(idPoint1, idPoint2))
    {
        // 添加往返路线，往返消耗相等
        m_arrRoute[idPoint1][idPoint2] = dist;
        m_arrRoute[idPoint2][idPoint1] = dist;
    }
    else
    {
        return -1;
    }

    // 添加到未遍历源节点列表
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

/*  函数名：calcShortestRoute
    功能：计算最短路径
    入参：
        idFromPoint[IN]，起始点ID号
        idDestPoint[IN]，目的点ID号
    返回：int，2点间的最短距离
 */
int CDijkstra::calcShortestRoute(int idFromPoint, int idDestPoint)
{
    unsigned int arrTmpDist[MAX_POINT_NUM] = {MAX_ROUTE_DIST};

    // 返回计算最短路径时，需要移除的点
    vector<int> vecIdToRemove;
    // 第1步：起始点压入源点vector，更新arrTmpDist的值
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
        // 第2步：从vecU中取距离最小的点k，加入vecS中
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
        
        // 第3步：以点k为考虑点，修改arrTmpDist中的值，若经k到该点的值小于原值，则更新值
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
