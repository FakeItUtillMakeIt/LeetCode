#pragma once

#ifndef PLATE_BETWEEN_CANDLES_H
#define PLATE_BETWEEN_CANDLES_H

#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;


/*!
 *  Plateses the between candles.
 *  给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。
 *  同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。
 *  对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。
 *
 *      @param [in]     s       
 *      @param [in,out] queries 
 *
 *      @return 
 */
class Solution {
public:
	Solution() {
		vector<vector<int>> testData = { {1,17},{4,5},{14,17},{5,11},{15,16} };
		auto ret = platesBetweenCandles("***|**|*****|**||**|*"
			, testData);
	}

		vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
			int n = s.length();
			//存储前索引0-n的盘子和
			vector<int> preSum(n);
			for (int i = 0, sum = 0; i < n; i++) {
				if (s[i] == '*') {
					sum++;
				}
				preSum[i] = sum;
			}
			//左侧蜡烛位置分配 离当前索引最近的左侧蜡烛
			vector<int> left(n);
			for (int i = 0, l = -1; i < n; i++) {
				if (s[i] == '|') {
					l = i;
				}
				left[i] = l;
			}
			//右侧蜡烛位置分配 离当前索引最近的右侧蜡烛
			vector<int> right(n);
			for (int i = n - 1, r = -1; i >= 0; i--) {
				if (s[i] == '|') {
					r = i;
				}
				right[i] = r;
			}

			vector<int> ans;
			for (auto& query : queries) {
				int x = right[query[0]], y = left[query[1]];//得到当前索引的左右蜡烛索引
				ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);//根据索引得到索引前的盘子数
			}
			return ans;
		}
	
};

#endif
