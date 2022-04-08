#pragma once
#ifndef REMOVE_ELEMENT_H
#define REMOVE_ELEMENT_H

#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int> tmpNums = nums;
		nums.clear();
		int count = 0;
		for (auto curN:tmpNums)
		{
			if (curN==val)
			{
				continue;
			}
			nums.push_back(curN);
			count++;
		}
		return count;
	}
};

#endif