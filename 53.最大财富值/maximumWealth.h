#pragma once
#ifndef MAXIMUM_WEALTH_H
#define MAXIMUM_WEALTH_H

#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		vector<vector<int>> account = { {1,2,3},{3,4,5} };
		auto ret = maximumWealth(account);
	}
	int maximumWealth(vector<vector<int>>& accounts) {
		int maxSum = 0;
		for (auto eachC:accounts)
		{
			int eachSum = 0;
			for (auto eachO:eachC)
			{
				eachSum += eachO;
			}
			if (eachSum>maxSum)
			{
				maxSum = eachSum;
			}
		}
		return maxSum;
	}
};

#endif