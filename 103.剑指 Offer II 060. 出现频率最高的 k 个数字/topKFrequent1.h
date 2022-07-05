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
	@brief   作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/g5c51o/solution/chu-xian-pin-lu-zui-gao-de-k-ge-shu-zi-b-a1td/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:

	Solution() {
		vector<int> a = { 1,1,1,2,2,3 };
		auto ret = topKFrequent(a, 2);
	}
	//小顶堆
	static bool cmp(pair<int, int>& m, pair<int, int>& n) {
		return m.second > n.second;
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> occurrences;
		for (auto& v : nums) {
			occurrences[v]++;
		}

		// pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
		// 添加的元素按照堆进行排序
		//默认不加comp时为小顶堆
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

