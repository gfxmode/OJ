#ifndef __OJ_H__
#define __OJ_H__

#include <vector>

using namespace std;

// ����ö��
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
        int sizeArr = sizeVec * sizeVec;    // ʹ��һά������

        // ����һά���飬�����ڴ�
        /* (x, y)�����������ڼ�¼���Ƿ񱻷��ʹ�
            �������꾭x + y * sizeVecת��Ϊһά������
        */
        int *pArr = (int *)malloc(sizeof(int) * sizeArr);
        if (NULL == pArr)
        {
            printf("pArr malloc failed");

            return false;
        }
        // �����ʼ��
        memset(pArr, 0, sizeof(int) * sizeArr);

        // ����vector������(x, y)�����꣬���ж�һά������x + y * sizeVec�Ƿ���ʹ�
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


        // �ͷ�һά���飬�ͷ��ڴ�
        free(pArr);
        pArr = NULL;

        return true;
    }
};
#endif __OJ_H__
