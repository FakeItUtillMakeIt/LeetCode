#pragma once

#ifndef SUB_ARRAY_RANGE_H
#define SUB_ARRAY_RANGE_H

#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> test = { 4,-2,-3,4,1 };
		auto ret = subArrayRanges(test);
	}

	long long subArrayRanges(vector<int>& nums) {
		int totalSum = 0;
		for (int i=0;i<nums.size();i++)
		{
			
			
			int maxV = nums[i], minV = nums[i];
			for (int j = i; j < nums.size(); j++)
			{

				if (maxV < nums[j])
				{
					maxV = nums[j];
				}
				if (minV > nums[j])
				{
					minV = nums[j];
				}
				totalSum += (maxV - minV);
			}
			
			
		}
		return totalSum;
	}
};


#endif