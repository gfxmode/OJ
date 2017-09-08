#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    // Inital a list with head value
    ListNode(int x) : val(x), next(NULL) {}
    // Inital a list by array
    ListNode(int* ptrStart, int num)
    {
        if ((NULL == ptrStart) || (num < 1))
        {
            return;
        }
        // ʹ��β�巨
        ListNode *head, *p, *e;
        head = new ListNode(ptrStart[0]);
        e = head;
        char ch;  
        for (int i = 1; i < num; i++)
        {
            p = new ListNode(ptrStart[i]);  
            e->next = p;     //���½ڵ���ӵ���β
            e = p;           //��ָ��ָ���½ڵ�
        }
        e->next = NULL;

        // ���캯��thisָ��ͷ���
        this->val = head->val;
        this->next = head->next;
    }
};

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};
    
    /*
        ���ܣ�������ת
        ʵ��ԭ���������������ListNodeѹջ�ٵ�ջ
    */
    ListNode* reverseList(ListNode* head)
    {
        if (NULL == head)
        {
            return NULL;
        }
        stack<ListNode*> stackListNode;

        stackListNode.push(head);
        ListNode* tmp = head;
        // ����������ѹջ
        while(NULL != tmp->next)
        {
            tmp = tmp->next;
            stackListNode.push(tmp);
        }
        // ��ջ��β�巨���������ӵ�����
        ListNode *ptrOutHead, *p, *e;
        ptrOutHead = stackListNode.top();
        stackListNode.pop();
        e = ptrOutHead;
        while (!stackListNode.empty())
        {
            p = stackListNode.top();
            e->next = p;
            e = p;
            stackListNode.pop();
        }
        e->next = NULL;

        return ptrOutHead;
    }

    /*
        ptrLs��arrTarget�Ƚϣ���������ֵ�Ƿ�������һ��
    */
    bool checkListValue(ListNode *ptrLs, int *ptrArrTarget)
    {
        int i = 0;
        if ((NULL == ptrLs) || (NULL == ptrArrTarget))
        {
            return false;
        }
        ListNode *tmp = ptrLs;
        // will not check the part that ptrArrTarget longer than ptrLs
        while (NULL != tmp)
        {
            if (NULL == ptrArrTarget)
            {
                return false;
            }
            if (tmp->val != *ptrArrTarget)
            {
                return false;
            }
            ++ptrArrTarget;
            tmp = tmp->next;
        }

        return true;
    }
};
#endif OJ_H
