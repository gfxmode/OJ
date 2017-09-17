#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>
#include <ListNode.h>
#include <map>

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (NULL == head)
        {
            return NULL;
        }
        map<int, bool> mapIntOccurance;
        ListNode *ptrTmp = head;
        ListNode *ptrPre = ptrTmp;
        while (NULL != ptrTmp)
        {
            int value = ptrTmp->val;
            if (0 == mapIntOccurance.count(value))
            {
                // if value first appear, set to map
                mapIntOccurance[value] = true;
            }
            else
            {
                // if value appeared, remove current node
                ptrPre->next = ptrTmp->next;
                free(ptrTmp);
                ptrTmp = ptrPre->next;

                continue;
            }
            ptrPre = ptrTmp;
            ptrTmp = ptrTmp->next;
        }
        return head;
    }
};
#endif OJ_H
