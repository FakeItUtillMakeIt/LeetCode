#pragma once

#ifndef LEVEL_ORDER_H
#define LEVEL_ORDER_H

#include <vector>

using namespace  std;


// Definition for a Node.
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

/**

    @class   Solution
    @brief   ≤„–Ú±È¿˙
    @details ~

**/
class Solution {
public:
    Solution() {
        Node* root = new Node(1);
        Node* child1 = new Node(3);
        Node* child2 = new Node(2);
        Node* child3 = new Node(4);
        vector<Node*> subchild = { child1,child2,child3 };
        root->children = subchild;
        Node* child11 = new Node(5);
        Node* child12 = new Node(6);
        vector<Node*> ssubchild = { child11,child12 };
        
        auto ret = levelOrder(root);
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<Node*> curLayerNode;
        vector<Node*> nextLayerNode;
        vector<vector<int>> orderV;
        vector<int> eachLayerOrder;
        if (root==nullptr)
        {
            return orderV;
        }
        
        curLayerNode.push_back(root);
        while (!curLayerNode.empty())
        {
			for (auto curNode : curLayerNode)
			{
				eachLayerOrder.push_back(curNode->val);
				for (auto tmpnode:curNode->children)
				{
                    nextLayerNode.push_back(tmpnode);
				}
			}
            orderV.push_back(eachLayerOrder);
            eachLayerOrder.clear();
			curLayerNode = nextLayerNode;
			nextLayerNode.clear();
        }
        return orderV;
    }
};

#endif