#pragma once
#ifndef MIN_COST_H
#define MIN_COST_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> neededTime = { 4,9,3,8,8,9 };
		auto ret = minCost("bbbaaa", neededTime);
	}

	int minCost(string colors, vector<int>& neededTime) {
		if (colors.size()==1)
		{
			return 0;
		}
		int curIndex, preIndex;
		int count = 0;
		int totalCost = 0;
		int lianxuCount = 1;
		char preC='1';
		for (int i=0;i<colors.size();i++)
		{
			if (preC!=colors[i])
			{
				preC = colors[i];
				lianxuCount = 1;
			}
			else
			{
				curIndex = count;
				preIndex = count - lianxuCount;
				if (neededTime[curIndex]>neededTime[preIndex])
				{
					totalCost += neededTime[preIndex];
					lianxuCount = 1;
				}
				else
				{
					totalCost += neededTime[curIndex];
					lianxuCount++;
				}

			}
			count++;
		}
		return totalCost;
	}
};

#endif