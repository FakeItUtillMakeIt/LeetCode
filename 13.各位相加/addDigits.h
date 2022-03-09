#pragma once

#ifndef ADD_DIGITS_H
#define ADD_DIGITS_H

#include <vector>

using namespace std;

class Solution {

public:
	Solution() {
		auto ret = addDigits(38383838);
	}
public:
	int addDigits(int num) {
		int finalV = 0;
		vector<int> restV;

		while ((num/10)!=0)
		{
			restV.push_back(num % 10);
			num /= 10;
		}
		restV.push_back(num);
		int sumV = 0;
		for (auto v:restV)
		{
			sumV += v;
		}
		if (sumV>10)
		{
			sumV=addDigits(sumV);
		}
		

		finalV = sumV;
		return finalV;
	}
};

#endif
