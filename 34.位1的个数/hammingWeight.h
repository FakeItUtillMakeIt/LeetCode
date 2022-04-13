#pragma once
#ifndef HAMMING_WEIGHT_H
#define HAMMING_WEIGHT_H

#include <iostream>

using namespace std;

class Solution {
public:
	Solution() {
		auto ret = hammingWeight(255);
	}

	int hammingWeight(uint32_t n) {
		int sum1 = 0;
		while (n!=0)
		{
			sum1 += n & 0x1;
			n >>= 1;
		}
		return sum1;
	}
};

#endif

