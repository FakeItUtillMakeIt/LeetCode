#pragma once

#ifndef NUM_PRIME_ARRANGEMENT_H
#define NUM_PRIME_ARRANGEMENT_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
 /**
	 @brief  请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。

让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。

由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/prime-arrangements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
     @param  n - 
     @retval   - 
 **/
	Solution() {
		auto ret=numPrimeArrangements(5);
	}

	bool isZhiShu(int num) {
		int topNum = 10 > num ? num : 10;
		bool ret=true;
		for (int i=2;i<topNum;i++)
		{
			num% i == 0 ? ret = false : ret=true;
			if (!ret)
			{
				return ret;
			}
		}
		return ret;
	}



	int numPrimeArrangements(int n) {
		vector<int> zhishu1;
		int zhishuCount = 0;
		int notZhishuCount = 0;
		for (int i=2;i<=n;i++)
		{
			if (isZhiShu(i))
			{
				zhishuCount++;
				zhishu1.push_back(i);
				continue;
			}
			notZhishuCount++;
			
		}
		notZhishuCount++;
		long long zhishuArr = 1;
		long long notzhishuArr = 1;
	
		for (int i=1;i<= zhishuCount;i++)
		{
			zhishuArr *= i;
			zhishuArr %= (int)(pow(10, 9) + 7);
		}
	
		for (int i = 1; i <= notZhishuCount; i++)
		{
			notzhishuArr*= i;
			notzhishuArr %= (int)(pow(10, 9) + 7);
		}

		return (zhishuArr*notzhishuArr) % (int)(pow(10, 9) + 7);
	}
};

#endif