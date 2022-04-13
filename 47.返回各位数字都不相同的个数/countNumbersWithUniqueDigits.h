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
     @brief  返回各位数字都不相同的个数
     @param  n - 

		作者：LeetCode - Solution
			链接：https ://leetcode-cn.com/problems/count-numbers-with-unique-digits/solution/tong-ji-ge-wei-shu-zi-du-bu-tong-de-shu-iqbfn/
		来源：力扣（LeetCode）
			著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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

