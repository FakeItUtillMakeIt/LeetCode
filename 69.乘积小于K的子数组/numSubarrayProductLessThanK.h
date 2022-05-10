#pragma once
#ifndef NUM_SUBARRAY_PRODUCT_LESS_THAN_K_H
#define NUM_SUBARRAY_PRODUCT_LESS_THAN_K_H

#include <vector>
#include <algorithm>

using namespace std;
//
//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode-cn.com/problems/subarray-product-less-than-k/solution/cheng-ji-xiao-yu-k-de-zi-shu-zu-by-leetc-92wl/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		//j���ұ߽磬i����߽�
		int n = nums.size(), ret = 0;
		int prod = 1, i = 0;
		for (int j = 0; j < n; j++) {
			prod *= nums[j];
			//ֻ�е��۳������ڸ�����ʱ�Ŷ���˵�����ƶ�
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