#ifndef __OJ_H__
#define __OJ_H__

#include <iostream>
#include <string>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    bool isMatch(string s, string p)
    {
        int idxStr = 0;
        int idxPattern = 0;

        return matchCore(s, idxStr, p, idxPattern);
    }

    bool matchCore(string& s, int idxStr, string& p, int idxPattern)
    {
        // 如字符串到末尾且模式到末尾，则返回匹配
        if (idxStr == s.length() && idxPattern == p.length())
        {
            return true;
        }

        // 如字符串未到末尾，模式已到末尾，则返回不匹配
        if (idxStr != s.length() && idxPattern == p.length())
        {
            return false;
        }

        // 如果模式的第二个字符是"*"，且字符串第一个与模式第一个匹配，
        // 分3种匹配模式；如不匹配，则模式右移2位
        if (((idxPattern + 1) < (int)(p.length())) && (p.at(idxPattern + 1) == '*'))
        {
            if (((idxStr != s.length()) && (s.at(idxStr) == p.at(idxPattern))) ||
                ((idxStr != s.length()) && ('.' == p.at(idxPattern))))     // 第1个字符为.时，也计为匹配
            {
                return (matchCore(s, idxStr, p, idxPattern + 2) ||         // c*匹配0个字符，模式后移2位
                            matchCore(s, idxStr + 1, p, idxPattern + 2) || // c*匹配1个字符，模式后移2位
                            matchCore(s, idxStr + 1, p, idxPattern)        // *匹配1个字符，再匹配1个
                       );
            }
            else
            {
                return matchCore(s, idxStr, p, idxPattern + 2);           // 不匹配，模式左移2位
            }
        }

        // 如果模式的第二个字符不是"*"，且字符串第1个跟模式第1个匹配，则都后移1位，否则直接返回false
        if (((idxStr != s.length()) && (s.at(idxStr) == p.at(idxPattern))) ||
            ((idxStr != s.length()) && (p.at(idxPattern) == '.'))
           )
        {
            return matchCore(s, idxStr + 1, p, idxPattern + 1);
        }

        return false;
    }
};

#endif // __OJ_H__

