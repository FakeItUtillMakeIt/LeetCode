#pragma once

#ifndef HAS_ATERNATING_BITS_H
#define HAS_ATERNATING_BITS_H


#include <iostream>
#include <vector>

using namespace std;

/**

    @class   Solution
    @brief   ����һ����������������Ķ����Ʊ�ʾ�Ƿ����� 0��1 ������֣����仰˵�����Ƕ����Ʊ�ʾ��������λ������������ͬ��
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