#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

/*
    ����: �������ṹ���壬���ֵ����Ϊint
    ����: LeetCode OJʹ�õ���
*/
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif