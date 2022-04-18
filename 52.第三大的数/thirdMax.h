#pragma once
#ifndef THIRD_MAX_H
#define THIRD_MAX_H

#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool myFun(int i, int j)
{
	return (i > j);
}
class Solution {
public:
	Solution() {
		vector<int> nums = { 1,22,2,5,33,5,1,22,33 };
		auto ret = thirdMax(nums);
	}

	
	int thirdMax(vector<int>& nums) {
		vector<int> numQue;
		map<int, int> num2Count;
		for (auto num:nums)
		{
			num2Count[num] += 1;
		}
		for (auto mNum:num2Count)
		{
			numQue.push_back(mNum.first);
		}
		std::sort(numQue.begin(), numQue.end(),myFun);

		return 0;
	}
};
#endif