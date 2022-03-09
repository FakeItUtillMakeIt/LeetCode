#pragma once

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

	//使用map存储位置信息和值信息
	map<int, int> alldata;
	

	vector<int> findLonely(vector<int>& nums) {
		if (nums.size()==1)
		{
			return nums;
		}

		vector<int> outdata;
		for (int i=0;i<nums.size();i++)
		{
			alldata[nums[i]] += 1;
		}

		//给nums排序
		sort(nums.begin(),nums.end());

		for (int i=0;i<nums.size();i++)
		{
			//只出现了一次
			if (alldata[nums[i]]==1)
			{
				//查左右是否连续
				
				if (i!=0 && i !=nums.size()-1)
				{
					if (abs((nums[i-1])-nums[i])==1 || abs(nums[i+1]-nums[i])==1)
					{
						continue;
					}
					else
					{
						outdata.push_back(nums[i]);
					}
				}
				//左边界
				else if (i==0)
				{
					if (abs(nums[i+1]-nums[i])==1)
					{
						continue;
					}
					else
					{
						outdata.push_back(nums[i]);
					}
				}
				//右边界
				else if (i == nums.size()-1)
				{
					if (abs(nums[i - 1]  - nums[i])==1)
					{
						continue;
					}
					else
					{
						outdata.push_back(nums[i]);
					}
				}
			}
		}
		return outdata;
	}
};

