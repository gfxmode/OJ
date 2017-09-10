#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define MAX_INT_BIT 32
class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    /*
        函数名：hammingDistance
        功能：对两个字符串进行异或运算，并统计结果为1的个数，返回汉明距离。
        入参：x[IN]，整型
              y[IN]，整型
        返回：int，汉明距离
    */
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        bitset<MAX_INT_BIT> bsZ (z);
        // returns count of bits that are set to 1
        return bsZ.count();
    }
};
#endif OJ_H
