#pragma once

#ifndef COUNT_NUMBERS_WITH_UNIQUE_DIGITS_H
#define COUNT_NUMBERS_WITH_UNIQUE_DIGITS_H

#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		auto ret = countNumbersWithUniqueDigits(3);
	}
 /**
     @brief  ���ظ�λ���ֶ�����ͬ�ĸ���
     @param  n - 

		���ߣ�LeetCode - Solution
			���ӣ�https ://leetcode-cn.com/problems/count-numbers-with-unique-digits/solution/tong-ji-ge-wei-shu-zi-du-bu-tong-de-shu-iqbfn/
		��Դ�����ۣ�LeetCode��
			����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
     @retval   - 
 **/
	int countNumbersWithUniqueDigits(int n) {
		
				if (n == 0) {
					return 1;
				}
				if (n == 1) {
					return 10;
				}
				int ans = 10, cur = 9;
				for (int i = 0; i < n - 1; ++i) {
					cur *= 9 - i;
					ans += cur;
				}
				return ans;
			}
		};

#endif

