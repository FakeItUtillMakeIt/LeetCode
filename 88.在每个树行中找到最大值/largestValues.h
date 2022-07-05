#pragma once

#ifndef LARGEST_VALUES_H
#define LARGEST_VALUES_H

#include <vector>
#include "map"
#include <unordered_map>

using namespace std;


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

	map<int, int> layerBottomLeftValue;

	void getBottomLeftV(TreeNode* root, int currentLayer) {
		int rightLayer = currentLayer;
		int leftLayer = currentLayer;

		if (root == nullptr)
		{
			return;
		}
		if (layerBottomLeftValue.find(currentLayer)!=layerBottomLeftValue.end())
		{
			if (root->val>layerBottomLeftValue[currentLayer])
			{
				layerBottomLeftValue[currentLayer] = root->val;
			}
		}
		else
		{
			layerBottomLeftValue[currentLayer] = root->val;
		}
		
		if (root->right)
		{
			rightLayer++;
			getBottomLeftV(root->right, rightLayer);
		}
		if (root->left)
		{
			leftLayer++;
			//layerBottomLeftValue[leftLayer] = root->left->val;
			getBottomLeftV(root->left, leftLayer);
		}
	}

    TreeNode* root = new TreeNode(1, new TreeNode(3, new TreeNode(5), new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(9)));


    vector<int> ret = largestValues(root);

    vector<int> largestValues(TreeNode* root) {
		vector<int> ret;
		getBottomLeftV(root,1);
		for (auto each=layerBottomLeftValue.begin();each!=layerBottomLeftValue.end();each++)
		{
			ret.push_back(each->second);
		}
		return ret;
    }
};

#endif

