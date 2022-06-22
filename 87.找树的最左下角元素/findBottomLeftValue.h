#pragma once

#ifndef FIND_BOTTOM_LEFT_VALUE_H
#define FIND_BOTTOM_LEFT_VALUE_H

#include <iostream>
#include <map>

using namespace std;

 struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class Solution {
public:
	Solution() {
		TreeNode* root = new TreeNode;
		root->val = 1;
		

		auto ret = findBottomLeftValue(root);
	}

	map<int, int> layerBottomLeftValue;

	void getBottomLeftV(TreeNode* root,int currentLayer) {
		int rightLayer=currentLayer;
		int leftLayer=currentLayer;

		if (root==nullptr)
		{
			return;
		}
		layerBottomLeftValue[currentLayer] = root->val;
		if (root->right)
		{
			rightLayer++;
			getBottomLeftV(root->right, rightLayer);
		}
		if (root->left)
		{
			leftLayer++;
			layerBottomLeftValue[leftLayer] = root->left->val;
			getBottomLeftV(root->left, leftLayer);
		}
	}

    int findBottomLeftValue(TreeNode* root) {

		getBottomLeftV(root, 1);
		int maxLayer = 0;
		int ret;
		for (auto a=layerBottomLeftValue.begin();a!=layerBottomLeftValue.end();a++)
		{
			if (a->first>maxLayer)
			{
				ret = a->second;
				maxLayer = a->first;
			}
		}

		return ret;
    }
};

#endif