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
    // �����ַ�����Ӧ���̵ڼ���
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
        // ���������string vector
        for(iter = words.begin(); iter != words.end(); ++iter)
        {
            string strTmp = (string)(*iter);
            int iTmp = 0;
            int i = 0;
            // ��ͷ��β����string
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
            // �ж��Ƿ��ڼ���һ���ϣ���������vector
            if ((i > 0) && (i == strTmp.length()))
            {
                vecResult.push_back(strTmp);
            }
        }

        return vecResult;
    }
};
#endif OJ_H
