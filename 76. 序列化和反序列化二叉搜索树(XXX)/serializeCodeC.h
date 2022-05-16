#pragma once

#ifndef SERIALIZE_CODE_C_H
#define SERIALIZE_CODE_C_H

#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 


/**

	  @class   Codec
	  @brief     //  作者：LeetCode - Solution
链接：https://leetcode.cn/problems/serialize-and-deserialize-bst/solution/xu-lie-hua-he-fan-xu-lie-hua-er-cha-sou-5m9r4/
  来源：力扣（LeetCode）
	  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	  @details ~

  **/
  class Solution {
  public:
	  Solution() {
		  TreeNode* a = new TreeNode(1);
		  a->left = new TreeNode(2);
		  a->left->left = new TreeNode(4);
		  a->left->right = new TreeNode(5);
		  a->right = new TreeNode(3);
		  a->right->left = new TreeNode(6);
		  a->right->right = new TreeNode(7);

		  auto ret = serialize(a);

		  auto ret1 = deserialize("4,5,2,6,7,3,1");
	  }
	  string serialize(TreeNode* root) {
		  string res;
		  vector<int> arr;
		  postOrder(root, arr);
		  if (arr.size() == 0) {
			  return res;
		  }
		  for (int i = 0; i < arr.size() - 1; i++) {
			  res.append(to_string(arr[i]) + ",");
		  }
		  res.append(to_string(arr.back()));
		  return res;
	  }

	  vector<string> split(const string& str, char dec) {
		  int pos = 0;
		  int start = 0;
		  vector<string> res;
		  while (pos < str.size()) {
			  while (pos < str.size() && str[pos] == dec) {
				  pos++;
			  }
			  start = pos;
			  while (pos < str.size() && str[pos] != dec) {
				  pos++;
			  }
			  if (start < str.size()) {
				  res.emplace_back(str.substr(start, pos - start));
			  }
		  }
		  return res;
	  }

	  TreeNode* deserialize(string data) {
		  if (data.size() == 0) {
			  return nullptr;
		  }
		  vector<string> arr = split(data, ',');
		  stack<int> st;
		  for (auto& str : arr) {
			  st.emplace(stoi(str));
		  }
		  return construct(INT_MIN, INT_MAX, st);
	  }

	  void postOrder(TreeNode* root, vector<int>& arr) {
		  if (root == nullptr) {
			  return;
		  }
		  postOrder(root->left, arr);
		  postOrder(root->right, arr);
		  arr.emplace_back(root->val);
	  }

	  TreeNode* construct(int lower, int upper, stack<int>& st) {
		  if (st.size() == 0 || st.top() < lower || st.top() > upper) {
			  return nullptr;
		  }
		  int val = st.top();
		  st.pop();
		  TreeNode* root = new TreeNode(val);
		  root->right = construct(val, upper, st);
		  root->left = construct(lower, val, st);
		  return root;
	  }
  };

#endif
