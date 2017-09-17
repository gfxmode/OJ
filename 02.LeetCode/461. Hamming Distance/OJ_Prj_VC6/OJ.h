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
        ��������hammingDistance
        ���ܣ��������ַ�������������㣬��ͳ�ƽ��Ϊ1�ĸ��������غ������롣
        ��Σ�x[IN]������
              y[IN]������
        ���أ�int����������
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
