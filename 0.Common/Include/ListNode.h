#ifndef LIST_NODE_H
#define LIST_NODE_H

/*
    类名: 单链表函数，链表值为int型
    功能: LeetCode OJ使用的类
*/
class ListNode
{
public:
    int val;                // 单链表值
    ListNode *next;         // 单链表下一节点
    
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

    // compare 2 ListNode's value. true: same; false: not same
    static bool isValueSame(ListNode* p1, ListNode* p2)
    {
        // if 2 listnode is both null, return true
        if((NULL == p1) && (NULL == p2))
        {
            return true;
        }
        // else if one is null, return false
        if((NULL == p1) || (NULL == p2))
        {
            return false;
        }
        
        ListNode* ptrTmp1 = p1;
        ListNode* ptrTmp2 = p2;
        while((NULL != ptrTmp1) && (NULL != ptrTmp2))
        {
            if(ptrTmp1->val != ptrTmp2->val)
            {
                return false;
            }
            ptrTmp1 = ptrTmp1->next;
            ptrTmp2 = ptrTmp2->next;
        }

        // if 2 listnode length not equal, return false;
        if((NULL != ptrTmp1) || (NULL != ptrTmp2))
        {
            return false;
        }

        return true;
    }
};

#endif
