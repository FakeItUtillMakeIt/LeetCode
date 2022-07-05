#pragma once

#ifndef GET_TARGET_COPY_H
#define GET_TARGET_COPY_H

#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    

    Solution() {
		TreeNode* original = new TreeNode(7);

		TreeNode* colned = original;
		
        original->left = new TreeNode(4);
        original->right = new TreeNode(3);
        original->right->left = new TreeNode(6);
        original->right->right = new TreeNode(19);
        TreeNode* target = original->right;
        auto ret = getTargetCopy(original, colned, target);
    }
    TreeNode* clonedTarget;

    void getTarget(TreeNode* cloned, int val) {
        if (!cloned)
        {
            return;
        }
        if (cloned->val==val)
        {
            clonedTarget = cloned;
            return ;
        }
        getTarget(cloned->left, val);
        getTarget(cloned->right, val);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       
        getTarget(cloned, target->val);
        return clonedTarget;

    }
};

#endif
