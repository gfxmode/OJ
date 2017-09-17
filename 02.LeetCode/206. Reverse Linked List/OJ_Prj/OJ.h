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
        // 使用尾插法
        ListNode *head, *p, *e;
        head = new ListNode(ptrStart[0]);
        e = head;
        char ch;  
        for (int i = 1; i < num; i++)
        {
            p = new ListNode(ptrStart[i]);  
            e->next = p;     //把新节点添加到表尾
            e = p;           //把指针指向新节点
        }
        e->next = NULL;

        // 构造函数this指向头结点
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
        功能：单链表反转
        实现原理：单链表遍历，将ListNode压栈再弹栈
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
        // 遍历单链表，压栈
        while(NULL != tmp->next)
        {
            tmp = tmp->next;
            stackListNode.push(tmp);
        }
        // 弹栈，尾插法，重新链接单链表
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
        ptrLs与arrTarget比较，看链表数值是否与数组一致
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
