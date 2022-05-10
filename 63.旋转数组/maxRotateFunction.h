#pragma once
#ifndef MAX_ROTATE_FUNCTION_H
#define MAX_ROTATE_FUNCTION_H

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//爆破
//class Solution {
//public:
//	int maxRotateFunction(vector<int>& nums) {
//		int maxNumSum = 0;
//		for (int i=0;i<nums.size();i++)
//		{
//			maxNumSum += i * nums[i];
//		}
//		for (int start=0;start<nums.size();start++)
//		{
//			int curSum=0;
//			for (int w=0;w<nums.size();w++)
//			{
//				curSum += w * nums[(start + nums.size()+w) % nums.size()];
//			}
//			if (curSum>maxNumSum)
//			{
//				maxNumSum = curSum;
//			}
//		}
//		return maxNumSum;
//	}
//};

//先进行基础排序，小值数组排前面，大值数组排较后
/**

    @class   Solution
	@brief
作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/rotate-function/solution/xuan-zhuan-shu-zu-by-leetcode-solution-s0wd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	int maxRotateFunction(vector<int>& nums) {
		int f = 0, n = nums.size();
		int numSum = accumulate(nums.begin(), nums.end(), 0);
		for (int i = 0; i < n; i++) {
			f += i * nums[i];
		}
		int res = f;
		for (int i = n - 1; i > 0; i--) {
			f += numSum - n * nums[i];
			res = max(res, f);
		}
		return res;
	}
};


#endif