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
        // ���ַ�����ĩβ��ģʽ��ĩβ���򷵻�ƥ��
        if (idxStr == s.length() && idxPattern == p.length())
        {
            return true;
        }

        // ���ַ���δ��ĩβ��ģʽ�ѵ�ĩβ���򷵻ز�ƥ��
        if (idxStr != s.length() && idxPattern == p.length())
        {
            return false;
        }

        // ���ģʽ�ĵڶ����ַ���"*"�����ַ�����һ����ģʽ��һ��ƥ�䣬
        // ��3��ƥ��ģʽ���粻ƥ�䣬��ģʽ����2λ
        if (((idxPattern + 1) < (int)(p.length())) && (p.at(idxPattern + 1) == '*'))
        {
            if (((idxStr != s.length()) && (s.at(idxStr) == p.at(idxPattern))) ||
                ((idxStr != s.length()) && ('.' == p.at(idxPattern))))     // ��1���ַ�Ϊ.ʱ��Ҳ��Ϊƥ��
            {
                return (matchCore(s, idxStr, p, idxPattern + 2) ||         // c*ƥ��0���ַ���ģʽ����2λ
                            matchCore(s, idxStr + 1, p, idxPattern + 2) || // c*ƥ��1���ַ���ģʽ����2λ
                            matchCore(s, idxStr + 1, p, idxPattern)        // *ƥ��1���ַ�����ƥ��1��
                       );
            }
            else
            {
                return matchCore(s, idxStr, p, idxPattern + 2);           // ��ƥ�䣬ģʽ����2λ
            }
        }

        // ���ģʽ�ĵڶ����ַ�����"*"�����ַ�����1����ģʽ��1��ƥ�䣬�򶼺���1λ������ֱ�ӷ���false
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

