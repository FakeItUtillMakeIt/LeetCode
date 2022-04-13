#pragma once

#ifndef COUNT_HIGHTEST_SCORE_NODES_H
#define COUNT_HIGHTEST_SCORE_NODES_H

#include <vector>

using namespace std;




/**

    @class   Solution
	@brief   ���ߣ�LeetCode - Solution
	���ӣ�https ://leetcode-cn.com/problems/count-nodes-with-the-highest-score/solution/tong-ji-zui-gao-fen-de-jie-dian-shu-mu-b-n810/
	��Դ�����ۣ�LeetCode��
	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
    @details ~

**/
class Solution {
public:
	Solution() {
		vector<int> a = { -1,2,0,2,0 };
		auto ret = countHighestScoreNodes(a);
	}

	long maxScore = 0;
	int cnt = 0;
	int n;
	vector<vector<int>> children;

	int dfs(int node) {
		long score = 1;
		int size = n - 1;
		for (int c : children[node]) {
			int t = dfs(c);
			score *= t;
			size -= t;
		}
		if (node != 0) {
			score *= size;
		}
		if (score == maxScore) {
			cnt++;
		}
		else if (score > maxScore) {
			maxScore = score;
			cnt = 1;
		}
		return n - size;
	}

	int countHighestScoreNodes(vector<int>& parents) {
		this->n = parents.size();
		this->children = vector<vector<int>>(n);
		for (int i = 0; i < n; i++) {
			int p = parents[i];
			if (p != -1) {
				children[p].emplace_back(i);
			}
		}
		dfs(0);
		return cnt;
	}
};



#endif
