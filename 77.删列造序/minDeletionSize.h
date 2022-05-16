#pragma once

#ifndef MIN_DELETION_SIZE_H
#define MIN_DELETION_SIZE_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
		vector<string> strs = { "rrjk","furt","guzm" };
		auto ret = minDeletionSize(strs);
	}

	int judgeSort(string s) {
		
		for (int i=0;i<s.size()-1;i++)
		{
			for (int j=i+1;j<s.size();j++)
			{
				if ((s[j] - s[i]) < 0)
				{
					return 1;
				}
			}
			
		}
		return 0;
	}

	int minDeletionSize(vector<string>& strs) {
		vector<string> columnStrs(strs[0].size());
		int strL = strs[0].size();
		int i = 0;

		for (int k=0;k<strL;k++)
		{
			for (auto str : strs)
			{
				columnStrs[i].push_back(str[i]);
			}
			i++;
		}

		int sum = 0;
		for (auto eachS:columnStrs)
		{
			sum+=judgeSort(eachS);
		}
		
		return sum;
	}
};

#endif
