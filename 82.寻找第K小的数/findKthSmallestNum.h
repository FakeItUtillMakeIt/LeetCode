#pragma once
#ifndef FIND_KTH_NUMBER_H
#define FIND_KTH_NUMBER_H

#include <vector>
#include <algorithm>

using namespace std;

/**

    @class   Solution
	@brief   作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/solution/cheng-fa-biao-zhong-di-kxiao-de-shu-by-l-521a/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~
	二分法，遍历求不出来的第K个数都可以尝试使用二分法
**/
class Solution1 {
public:
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right) {
			//统计小于x的个数
			int x = left + (right - left) / 2;
			int count = x / n * n;
			for (int i = x / n + 1; i <= m; ++i) {
				count += x / i;
			}
			if (count >= k) {
				right = x;
			}
			else {
				left = x + 1;
			}
		}
		return left;
	}
};


/**

    @class   Solution
	@brief   作者：AC_OIer
链接：https ://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/solution/by-ac_oier-7pmt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	Solution() {
		auto ret = findKthNumber(2, 3, 6);
	}

	int _n, _m, _k;

	int getCnt(int mid) {
		int a = 0;
		int b = 0;
		for (int i=1;i<=_n;i++)
		{
			//当前行中小于mid的个数为_m个：这是因为每行为_m的倍数
			if ((i*_m)<mid)
			{
				a+=_m;
			}
			else
			{
				//mid存在于该行,比mid小的数为mid/i-1，等于mid的数b+1
				if (mid%i==0 && ++b>0)
				{
					a += mid / i - 1;
				}
				else//否则mid不存在于该行，直接求得小于mid的个数
				{
					a += mid / i;
				}
			}
		}
		return a + b;
	}

	int findKthNumber(int m, int n, int k) {
		
		_m = min(m, n);
		_n = max(m, n);
		_k = k;

		int l = 1, r = _m*_n;
		while (l<r)
		{
			int mid =( l + r) /2;
			int cnt = getCnt(mid);
			if (cnt>=_k)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		return r;
	}
};

class Solution2 {
public:
	Solution2() {
		auto ret = findKthNumber(3, 3, 5);
	}

	int findKthNumber(int m, int n, int k) {
		vector<int> numV;
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=n;j++)
			{
				numV.push_back(i * j);
			}
		}
		sort(numV.begin(), numV.end());
		return numV[k-1];
	
	}
};
#endif
