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

    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        vector<int> vecResult;
        int szFindNum = findNums.size();
        int szNums = nums.size();
        // �����Ӽ�1
        for (int i = 0; i < szFindNum; i++)
        {
            int iObj = findNums[i];  
            // ����ȫ��
            int idxFind = -1;
            int j = 0;
            for(j = 0; j < szNums; j++)
            {
                if (idxFind >= 0)
                {
                    // ���ҵ����ֵ����Ŵ��ڵ���0������ʼ�Ҵ����Ӽ����ĵ�1��ֵ
                    if (nums[j] > iObj)
                    {
                        vecResult.push_back(nums[j]);
                        break;
                    }
                }
                else
                {      
                    // ��ȫ�����ҵ����ֵ��������ֵ���
                    if (nums[j] == iObj)
                    {
                        idxFind = j;
                    }
                }
            }
            // ��ȫ����δ�ҵ���ֵ����-1
            if (j == szNums)
            {
                vecResult.push_back(-1);
            }
        }

        return vecResult;
    }

    /*
        ��������isVecSame
        ���ܣ��Ƚ�����vector�Ƿ����
        ������vec1[IN]���Ƚ϶���1
                vec2[IN]���Ƚ϶���2
        ����ֵ��bool��
                    true�����
                    false������
    */
    static bool isVecSame(vector<int>& vec1, vector<int>& vec2)
    {
        // vector�������ȣ�����false
        if (vec1.size() != vec2.size())
        {
            return false;
        }

        // vectorֵ���ȣ�����false
        for (int i = 0; i < vec1.size(); i++)
        {
            if(vec1.at(i) != vec2.at(i))
            {
                return false;
            }
        }

        return true;
    }
};
#endif OJ_H
