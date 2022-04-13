#pragma once

#include "countHighestScoreNodes1.h"
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
	Solution() {
		vector<int> a = { -1,2,0,2,0 };
		auto ret = countHighestScoreNodes(a);
	}

	unordered_map<int, int>zuo;//统计每个节点左子树节点个数
	unordered_map<int, int>you;
	int dfs(vector<int>& left, vector<int>& right, int head)
	{
		if (left[head] == -1 && right[head] == -1)
		{
			return 1;//如果没有儿子，直接返回1
		}
		int m = 0, n = 0;
		if (left[head] != -1)
		{
			m = dfs(left, right, left[head]);//有左儿子，才去dfs
		}
		if (right[head] != -1)
		{
			n = dfs(left, right, right[head]);
		}
		zuo[head] = m;//左子树节点个数
		you[head] = n;
		return m + n + 1;
	}
	int countHighestScoreNodes(vector<int>& parents) {
		vector<int>left(parents.size(), -1);//每个节点的左儿子，初始化为-1
		vector<int>right(parents.size(), -1);//每个节点的右儿子，初始化为-1
		int tou = -1;//头节点，初始化为-1；
		for (int i = 0; i < parents.size(); i++)
		{
			if (parents[i] == -1)
			{
				tou = i;//找到头节点了
				continue;
			}
			if (left[parents[i]] == -1)
			{
				left[parents[i]] = i;//i的父亲节点还没有左儿子，先安排i为左儿子。
			}
			else {
				right[parents[i]] = i;
			}
		}
		dfs(left, right, tou);
		long long mxfen = 0;//最大的分数
		int ans = 0;//答案，即最大分数节点的个数
		long long now = 0;//当前节点的分数
		vector<long long>cnt;//每个节点的分数，最后算出mxfen后用来统计ans
		for (int i = 0; i < parents.size(); i++)
		{
			now = 1;
			int m = zuo[i];//i左子树所有节点个数
			int n = you[i];
			int k = parents.size() - m - n - 1;
			if (m)//如果左子树非空，我们才计算，所以你发现now初始化为1
			{
				now *= m;
			}
			if (n)//右子树非空
			{
				now *= n;
			}
			if (k)//父节点非空
			{
				now *= k;
			}
			cnt.push_back(now);
			mxfen = max(mxfen, now);
		}
		for (int i = 0; i < parents.size(); i++)
		{
			if (cnt[i] == mxfen)
			{
				ans++;//统计答案
			}
		}

		return ans;
	}
};


