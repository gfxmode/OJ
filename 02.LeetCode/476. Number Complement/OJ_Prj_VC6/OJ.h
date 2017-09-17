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

    int findComplement(int num)
    {
        bitset<MAX_INT_BIT> bsInput(~num);
        bitset<MAX_INT_BIT> bsResult(0);
        bool isZeroFound = false;
        for (int i = (MAX_INT_BIT - 1); i >= 0 ; --i)
        {
            if (0 == bsInput[i])
            {
                isZeroFound = true;
            }
            if (isZeroFound)
            {
                bsResult[i] = bsInput[i];
            }
        }

        return (int)(bsResult.to_ulong());
    }
};
#endif OJ_H
