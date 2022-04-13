#pragma once
#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> nums = { 0,0,1,1,2,2 };
		auto ret = removeDuplicates(nums);
	}

	int removeDuplicates(vector<int>& nums) {
		auto tmpNum = nums;
		nums.clear();
		int tmp=1000000;
		int count = 0;
		for (auto curNum:tmpNum)
		{
			if (tmp==curNum)
			{
				continue;
			}
			else
			{
				tmp = curNum;
				nums.push_back(tmp);
				count++;
			}

		}
		return count;
	}
};

#endif