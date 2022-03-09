#pragma once

#include <vector>
#include <map>
using namespace std;

class Solution {
	map<int, vector<int>> memo;
public:
	//·ÖÖÎ
	vector<int> beautifulArray(int n) {
		if (memo.count(n)) {
			return memo[n];
		}

		vector<int> res(n);
		if (n == 1)  res[0] = 1;
		else {
			int t = 0;
			for (int& x : beautifulArray((n + 1) / 2)) {
				res[t++] = 2 * x - 1;
			}
			for (int& x : beautifulArray(n / 2)) {
				res[t++] = 2 * x;
			}
		}
		memo[n] = res;
		return res;
	}
};

