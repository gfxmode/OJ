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
    // 返回字符串对应键盘第几行
    int getCharRow(char ch)
    {
        int ret = -1;
        switch(toupper(ch))
        {
            case 'Q':
            case 'W':
            case 'E':
            case 'R':
            case 'T':
            case 'Y':
            case 'U':
            case 'I':
            case 'O':
            case 'P':
                {
                    ret = 1;
                    break;
                }
            case 'A':
            case 'S':
            case 'D':
            case 'F':
            case 'G':
            case 'H':
            case 'J':
            case 'K':
            case 'L':
                {
                    ret = 2;
                    break;
                }
            case 'Z':
            case 'X':
            case 'C':
            case 'V':
            case 'B':
            case 'N':
            case 'M':
                {
                    ret = 3;
                    break;
                }
            default:
                break;
        }

        return ret;
    }

    vector<string> findWords(vector<string>& words)
    {
        vector<string> vecResult;

        vector<string>::iterator iter;
        // 遍历输出的string vector
        for(iter = words.begin(); iter != words.end(); ++iter)
        {
            string strTmp = (string)(*iter);
            int iTmp = 0;
            int i = 0;
            // 从头到尾遍历string
            for (i = 0; i < strTmp.length(); ++i)
            {
                if (0 == iTmp)
                {
                    iTmp = getCharRow(strTmp.at(i));
                    continue;
                }

                if((iTmp > 0) && (iTmp != getCharRow(strTmp.at(i))))
                {
                    break;
                }
            }
            // 判断是否在键盘一行上，并保存至vector
            if ((i > 0) && (i == strTmp.length()))
            {
                vecResult.push_back(strTmp);
            }
        }

        return vecResult;
    }
};
#endif OJ_H
