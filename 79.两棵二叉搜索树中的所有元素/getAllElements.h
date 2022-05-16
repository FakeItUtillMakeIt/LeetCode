#pragma once

#ifndef GET_ALL_ELEMENTS_H
#define GET_ALL_ELEMENTS_H

#include <vector>
#include <algorithm>

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
    Solution() {
        TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        TreeNode* root2= new TreeNode(0, new TreeNode(3), new TreeNode(5));

        auto ret=getAllElements(root1, root2);
    }

private:
    vector<int> allElements;

    void forwartSortGetAllElement(TreeNode* Node) {
        if (!Node)
        {
            return;
        }
        allElements.push_back(Node->val);
        forwartSortGetAllElement(Node->left);
        forwartSortGetAllElement(Node->right);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      

        forwartSortGetAllElement(root1);
        forwartSortGetAllElement(root2);

        sort( allElements.begin(), allElements.end());

        return  allElements;
    }
};


#endif