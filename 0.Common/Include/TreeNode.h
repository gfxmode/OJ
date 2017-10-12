#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

/*
    类名: 二叉树结构定义，结点值类型为int
    功能: LeetCode OJ使用的类
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