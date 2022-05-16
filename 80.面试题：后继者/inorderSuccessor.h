#pragma once
#ifndef INORDER_SUCCESSOR_H
#define INORDER_SUCCESSOR_H

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    Solution() {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(6);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->left->left->left = new TreeNode(1);

        TreeNode* p = new TreeNode(2);

        auto ret=inorderSuccessor(root, p);
    }

    TreeNode* retNode = nullptr;
    bool flag = false;
    vector<TreeNode*> sNode;

    void midSort(TreeNode* root,TreeNode* p) {
        if (!root)
        {
            return ;
        }
        //
        midSort(root->left, p);
        sNode.push_back(root);
        if (flag)
        {
            flag = false;
            retNode = root;
            return;
        }
        
        if (root->val==p->val)
        {
            flag = true;
  
        }

        midSort(root->right, p);

    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        midSort(root, p);
        return retNode;

    }
};

#endif