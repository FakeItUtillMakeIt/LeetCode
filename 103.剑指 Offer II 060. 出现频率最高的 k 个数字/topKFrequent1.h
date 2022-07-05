#pragma once

#include <unordered_map>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**

    @class   Solution
	@brief   ���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/g5c51o/solution/chu-xian-pin-lu-zui-gao-de-k-ge-shu-zi-b-a1td/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
    @details ~

**/
class Solution {
public:

	Solution() {
		vector<int> a = { 1,1,1,2,2,3 };
		auto ret = topKFrequent(a, 2);
	}
	//С����
	static bool cmp(pair<int, int>& m, pair<int, int>& n) {
		return m.second > n.second;
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> occurrences;
		for (auto& v : nums) {
			occurrences[v]++;
		}

		// pair �ĵ�һ��Ԫ�ش��������ֵ���ڶ���Ԫ�ش����˸�ֵ���ֵĴ���
		// ��ӵ�Ԫ�ذ��նѽ�������
		//Ĭ�ϲ���compʱΪС����
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
		for (auto& [num, count] : occurrences) {
			if (q.size() == k) {
				if (q.top().second < count) {
					q.pop();
					q.emplace(num, count);
				}
			}
			else {
				q.emplace(num, count);
			}
		}
		vector<int> ret;
		while (!q.empty()) {
			ret.emplace_back(q.top().first);
			q.pop();
		}


		return ret;
	}
};

