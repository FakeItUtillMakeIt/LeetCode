#pragma once

#ifndef WIGGLE_SORT_H
#define WIGGLE_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

//在一个整数数组中，“峰”是大于或等于相邻整数的元素，相应地，
//“谷”是小于或等于相邻整数的元素。例如，在数组{5, 8, 4, 2, 3, 4, 6}中，{8, 6}是峰， {5, 2}是谷。现在给定一个整数数组，将该数组按峰与谷的交替顺序排序。
class Solution {
public:
	Solution() {
		vector<int> data = { 5,8,4,2,3,4,6 };
		wiggleSort(data);
	}

	void wiggleSort(vector<int>& nums) {

		int minV;//中位数
		vector<int> topV, bottomV;
		
		sort(nums.begin(), nums.end());
		
		for (int i=0;i<nums.size();i++)
		{
			if (i<nums.size()/2)
			{
				bottomV.push_back(nums[i]);
			}
			else
			{
				topV.push_back(nums[i]);
			}
		}
		
		nums.clear();
		bool flag = false;
		while (!topV.empty() || !bottomV.empty())
		{
			if (!flag)
			{
				nums.push_back(topV.back());
				topV.pop_back();
			}
			else
			{
				nums.push_back(bottomV.back());
				bottomV.pop_back();
			}
			flag = !flag;
		}

	}
};

#endif