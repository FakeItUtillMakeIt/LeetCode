#pragma once

#ifndef FIND_MIN_HEIGHT_TREES_H
#define FIND_MIN_HEIGHT_TREES_H

#include <vector>
#include <map>
#include <queue>

using namespace std;

/**

    @class   Solution
	@brief   树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:

	Solution() {
		vector<vector<int>> trees = { {3,0},{3,1},{3,2},{3,4},{4,5},{5,6} };
		auto ret = findMinHeightTrees(7, trees);
	}

		int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj) {
			int n = adj.size();
			queue<int> qu;
			vector<bool> visit(n);
			qu.emplace(u);
			visit[u] = true;
			int node = -1;

			while (!qu.empty()) {
				int curr = qu.front();
				qu.pop();
				node = curr;
				for (auto& v : adj[curr]) {
					if (!visit[v]) {
						visit[v] = true;
						parent[v] = curr;
						qu.emplace(v);
					}
				}
			}
			return node;
		}

		vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
			if (n == 1) {
				return { 0 };
			}
			vector<vector<int>> adj(n);
			for (auto& edge : edges) {
				adj[edge[0]].emplace_back(edge[1]);
				adj[edge[1]].emplace_back(edge[0]);
			}

			vector<int> parent(n, -1);
			/* 找到与节点 0 最远的节点 x */
			int x = findLongestNode(0, parent, adj);
			/* 找到与节点 x 最远的节点 y */
			int y = findLongestNode(x, parent, adj);
			/* 求出节点 x 到节点 y 的路径 */
			vector<int> path;
			parent[x] = -1;
			while (y != -1) {
				path.emplace_back(y);
				y = parent[y];
			}
			int m = path.size();
			if (m % 2 == 0) {
				return { path[m / 2 - 1], path[m / 2] };
			}
			else {
				return { path[m / 2] };
			}
		}
	};



#endif