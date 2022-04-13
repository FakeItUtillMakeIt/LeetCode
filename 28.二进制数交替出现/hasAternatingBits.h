#pragma once

#ifndef HAS_ATERNATING_BITS_H
#define HAS_ATERNATING_BITS_H


#include <iostream>
#include <vector>

using namespace std;

/**

    @class   Solution
    @brief   给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
    @details ~

**/
class Solution {
public:
	Solution() {
		auto ret = hasAlternatingBits(4);
	}

	bool hasAlternatingBits(int n) {
		
		int tmp1=-1,tmp2=-1;
		while (n!=0)
		{
			tmp1 = tmp2;
			tmp2 = n % 2;;
			if (tmp1==tmp2)
			{
				return false;
			}
			
			n /= 2;
		}
		return true;

	}
};


#endif