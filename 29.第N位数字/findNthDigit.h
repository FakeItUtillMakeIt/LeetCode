#pragma once

#include <iostream>
#include <vector>

using namespace std;

/**

    @class   Solution
	@brief   作者：LeetCode - Solution
			链接：https ://leetcode-cn.com/problems/nth-digit/solution/di-n-wei-shu-zi-by-leetcode-solution-mdl2/
		来源：力扣（LeetCode）
			著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			
			规律：
			x 位数的范围是 10^{x - 1}到 10^x - 1

    @details ~

**/
class Solution {
public:
	Solution() {
		auto ret = findNthDigit(333);
	}

	int findNthDigit(int n) {
		
		int d = 1, count = 9;
		//先得到n代表几位数
		while (n > (long)d * count) {
			n -= d * count;
			d++;
			count *= 10;
		}
		//n相对x位数开始的索引位置
		int index = n - 1;
		//x位数的实际的开始
		int start = (int)pow(10, d - 1);
		//得到n代表的具体数
		int num = start + index / d;
		//n代表数的第几位
		int digitIndex = index % d;
		//得到这位
		int digit = (num / (int)(pow(10, d - digitIndex - 1))) % 10;
		return digit;
			
		}

		
	}
};