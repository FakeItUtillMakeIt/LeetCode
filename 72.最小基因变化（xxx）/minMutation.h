#pragma once
#ifndef MIN_MUTATION_H
#define MIN_MUTATION_H

#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

/**

    @class   Solution
	@brief   作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/minimum-genetic-mutation/solution/zui-xiao-ji-yin-bian-hua-by-leetcode-sol-lhwy/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		unordered_set<string> cnt;
		unordered_set<string> visited;
		char keys[4] = { 'A', 'C', 'G', 'T' };
		for (auto& w : bank) {
			cnt.emplace(w);
		}
		if (start == end) {
			return 0;
		}
		if (!cnt.count(end)) {
			return -1;
		}
		queue<string> qu;
		qu.emplace(start);
		visited.emplace(start);
		int step = 1;
		while (!qu.empty()) {
			int sz = qu.size();
			for (int i = 0; i < sz; i++) {
				string curr = qu.front();
				qu.pop();
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 4; k++) {
						if (keys[k] != curr[j]) {
							string next = curr;
							next[j] = keys[k];
							if (!visited.count(next) && cnt.count(next)) {
								if (next == end) {
									return step;
								}
								qu.emplace(next);
								visited.emplace(next);
							}
						}
					}
				}
			}
			step++;
		}
		return -1;
	}
};


#endif
