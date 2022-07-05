#pragma once
#ifndef MAX_DEPTH_H
#define MAX_DEPTH_H



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:

	int leftDepth = 0;
    int rightDepth = 0;
    int depth = 0;


	Solution() {
		TreeNode* root = new TreeNode(0);
		auto ret = maxDepth(root);
	}
    int maxDepth(TreeNode* root) {
        TreeNode* left, right;
        left = root->left;
        right = root->right;
		while (true)
		{
            
		}
		
    }
};
#endif