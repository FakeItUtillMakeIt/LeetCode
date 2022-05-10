#pragma once
#ifndef NUM_SUBARRAY_PRODUCT_LESS_THAN_K_H
#define NUM_SUBARRAY_PRODUCT_LESS_THAN_K_H

#include <vector>
#include <algorithm>

using namespace std;
//
//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/subarray-product-less-than-k/solution/cheng-ji-xiao-yu-k-de-zi-shu-zu-by-leetc-92wl/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		//j是右边界，i是左边界
		int n = nums.size(), ret = 0;
		int prod = 1, i = 0;
		for (int j = 0; j < n; j++) {
			prod *= nums[j];
			//只有当累乘数大于给定数时才对左端点进行移动
			while (i <= j && prod >= k) {
				prod /= nums[i];
				i++;
			}
			ret += j - i + 1;
		}
		return ret;

	}
};



#endif