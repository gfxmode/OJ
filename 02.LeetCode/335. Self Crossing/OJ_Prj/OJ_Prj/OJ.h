#ifndef __OJ_H__
#define __OJ_H__

#include <vector>

using namespace std;

// 方向枚举
enum ENUM_DIRECTION
{
    DIRECTION_NORTH = 0,
    DIRECTION_WEST,
    DIRECTION_SOUTH,
    DIRECTION_EAST,
};

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    bool isSelfCrossing(vector<int>& x)
    {
        int sizeVec = x.size();
        int sizeArr = sizeVec * sizeVec;    // 使用一维数组存放

        // 声明一维数组，分配内存
        /* (x, y)横纵坐标用于记录点是否被访问过
            横纵坐标经x + y * sizeVec转换为一维数组存放
        */
        int *pArr = (int *)malloc(sizeof(int) * sizeArr);
        if (NULL == pArr)
        {
            printf("pArr malloc failed");

            return false;
        }
        // 数组初始化
        memset(pArr, 0, sizeof(int) * sizeArr);

        // 遍历vector，生成(x, y)点坐标，并判断一维数组中x + y * sizeVec是否访问过
        int posX = 0, posY = 0;
        int cntItem = 0;

        vector<int>::iterator iter = x.begin();
        for (; x.end() != iter; ++iter)
        {
            switch (cntItem % 4)
            {
                DIRECTION_NORTH:
                    break;
                DIRECTION_WEST:
                    break;
                DIRECTION_SOUTH:
                    break;
                DIRECTION_EAST:
                    break;
                default:
                    break;
            }
            ++cntItem;
        }


        // 释放一维数组，释放内存
        free(pArr);
        pArr = NULL;

        return true;
    }
};
#endif __OJ_H__
