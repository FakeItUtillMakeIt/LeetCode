#pragma once
#ifndef MAX_SUB_ARRAY_H
#define MAX_SUB_ARRAY_H

#include <vector>
using namespace std;

class Solution {
public:
	Solution() {
		vector<int> nums = {-2,1 };
		auto ret = maxSubArray(nums);
	}
	int maxSubArray(vector<int>& nums) {
		if (nums.size()==1)
		{
			return nums[0];
		}
		int maxNums = -pow(2, 32);
		//起始位
		for (int i=0;i<nums.size();i++)
		{
			//起始位到终止位的长度
			for (int j=0;j<(nums.size()-i);j++)
			{
				int curSum = 0;
				for (int k=0;k<=j;k++)
				{
					curSum += nums[i+k];
					
				}
				if (curSum > maxNums)
				{
					maxNums = curSum;
				}
				
			}
			
		}
		return maxNums;
	}
};
#endif