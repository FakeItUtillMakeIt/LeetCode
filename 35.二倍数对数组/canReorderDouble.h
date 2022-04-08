#pragma once

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> arr = { 1,1,2,2,2,1,2,1 };
		auto ret = canReorderDoubled(arr);
	}

	bool canReorderDoubled(vector<int>& A) {
		map<double, double> m;
		for (auto& num : A) {
			m[num]++;
		}
		for (auto& [c, d] : m) {
			if (d < 0) return false;
			if (d == 0) continue;
			if (c > 0) {
				if (!m.count(c * 2)) return false;
				m[c * 2] -= d;
			}
			else {
				if (!m.count(c / 2.0)) return false;
				m[c / 2.0] -= d;
			}
		}
		return true;
	}
};