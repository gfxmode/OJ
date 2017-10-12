#ifndef OJ_H
#define OJ_H

#include <iostream>
#include <string>
#include "TreeNode.h"

using namespace std;

class OJ
{
public:
    OJ(void){};
    ~OJ(void){};

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL) return NULL;
        if(root->val >= L && root->val <= R) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
        if(root->val < L)  return trimBST(root->right, L, R);
        if(root->val > R)  return trimBST(root->left, L, R);
    }
};
#endif OJ_H
