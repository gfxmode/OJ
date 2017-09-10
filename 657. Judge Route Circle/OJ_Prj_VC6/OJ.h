#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    bool judgeCircle(string moves) 
    {
        bool result = false;
        int posX = 0;
        int posY = 0;
        for (int i = 0; i < moves.size(); i++)
        {
            switch (moves[i])
            {
            case 'U':
                ++posY;
            	break;
            case 'D':
                --posY;
            	break;
            case 'L':
                --posX;
            	break;
            case 'R':
                ++posX;
            	break;
            default:
                break;
            }
        }

        if ((0 == posX) && (0 == posY))
        {
            result = true;
        } 
        else
        {
            result = false;
        }

        return result;
    }
};
#endif OJ_H
