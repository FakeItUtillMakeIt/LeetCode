#pragma once

#ifndef IS_PALIN_DROME_H
#define IS_PALIN_DROME_H

#include <stack>
#include <vector>

using namespace std;


class Solution {
public:

	Solution() {
		auto ret = isPalindrome(1551551);
	}

	bool isPalindrome(int x) {
		vector<int> arrX;

		while (x>0)
		{
			
			arrX.push_back(x % 10);
			x /= 10;
		}
		for (int left=0;left<arrX.size()/2;left++)
		{
			int leftV = arrX[left];
			int rightV = arrX[arrX.size() - left - 1];
			if (leftV!=rightV)
			{
				return false;
			}
		}
		return true;

	}
};


#endif