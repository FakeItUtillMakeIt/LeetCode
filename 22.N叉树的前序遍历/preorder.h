#pragma once

#ifndef PRE_ORDER_H
#define PRE_ORDER_H

#include <vector>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
public:
	Solution() {
		vector<Node*> subNode = {new Node(3),new Node(2),new Node(4)};
		Node* rootNode = new Node(1, subNode);
		auto ret = preorder(rootNode);
	}

	vector<int> preorder(Node* root) {

		vector<int> preOrder;
		if (!root)
		{
			return preOrder;
		}
		preOrder.push_back(root->val);
		
		for (int i=0;i<root->children.size();i++)
		{
			auto ret=preorder(root->children[i]);
			for (auto retdata:ret)
			{
				preOrder.push_back(retdata);
			}
		}

		return preOrder;

	}
};


#endif
