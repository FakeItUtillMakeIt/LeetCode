#pragma once
#ifndef DIFFWAYS_TO_COMPUTE_H
#define DIFFWAYS_TO_COMPUTE_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
		auto ret = diffWaysToCompute("2*3-4*5");
	}
	vector<int> totalNum;

	//递归
	int diguiCompute(vector<int> numV,vector<char> formatV) {
		if (numV.size()==2)
		{
			int ret=0;
			if (formatV[0]=='*')
			{
				ret = numV[0] * numV[1];
			}
			if (formatV[0] == '+')
			{
				ret = numV[0] + numV[1];
			}
			if (formatV[0] == '-')
			{
				ret = numV[0] - numV[1];
			}
			return ret;
		}

		int calcNum;
		auto tmpNumV = numV;
		vector<int> diffRet;
		vector<char> calcFormat;
		//为2的整数
		if (numV.size()%2==0)
		{
			vector<int> tempNumV;
			vector<char> tempFormatV;
			
			for (int i=0;i<numV.size()/2;i++)
			{
				int j = 0;
				tempFormatV.push_back(formatV[2*i]);
				for (;j<2;j++)
				{
					tempNumV.push_back(tmpNumV.front());
					tmpNumV.erase(tmpNumV.begin());
				}
			
				diffRet.push_back(diguiCompute(tempNumV, tempFormatV));
				calcFormat.push_back(formatV[i + 1]);
				tempNumV.clear();
				tempFormatV.clear();
			}

			totalNum.push_back( diguiCompute(diffRet, calcFormat));
		}
		else
		{
			//分为1和n-1
			vector<int> tempNumV;
			vector<char> tempFormatV;
			/*tempNumV.push_back(tmpNumV.front());

			totalNum.push_back(diguiCompute()*/
		}
		

		return 0;

	}

	vector<int> diffWaysToCompute(string expression) {
		vector<int> numV;
		vector<char> formatV;

		for (char c:expression)
		{
			if (c=='*'||c=='+'||c=='-')
			{
				formatV.push_back(c);
				continue;
			}
			numV.push_back(c-48);
		}
		
		//递归
		diguiCompute(numV, formatV);

		return numV;
	}
};

#endif
/**

    @class   Solution
	@brief
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/different-ways-to-add-parentheses/solution/wei-yun-suan-biao-da-shi-she-ji-you-xian-lyw6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	const int ADDITION = -1;
	const int SUBTRACTION = -2;
	const int MULTIPLICATION = -3;

	vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int>& ops) {
		if (dp[l][r].empty()) {
			if (l == r) {
				dp[l][r].push_back(ops[l]);
			}
			else {
				for (int i = l; i < r; i += 2) {
					auto left = dfs(dp, l, i, ops);
					auto right = dfs(dp, i + 2, r, ops);
					for (auto& lv : left) {
						for (auto& rv : right) {
							if (ops[i + 1] == ADDITION) {
								dp[l][r].push_back(lv + rv);
							}
							else if (ops[i + 1] == SUBTRACTION) {
								dp[l][r].push_back(lv - rv);
							}
							else {
								dp[l][r].push_back(lv * rv);
							}
						}
					}
				}
			}
		}
		return dp[l][r];
	}

	vector<int> diffWaysToCompute(string expression) {
		vector<int> ops;
		for (int i = 0; i < expression.size();) {
			if (!isdigit(expression[i])) {
				if (expression[i] == '+') {
					ops.push_back(ADDITION);
				}
				else if (expression[i] == '-') {
					ops.push_back(SUBTRACTION);
				}
				else {
					ops.push_back(MULTIPLICATION);
				}
				i++;
			}
			else {
				int t = 0;
				while (i < expression.size() && isdigit(expression[i])) {
					t = t * 10 + expression[i] - '0';
					i++;
				}
				ops.push_back(t);
			}
		}
		vector<vector<vector<int>>> dp((int)ops.size(), vector<vector<int>>((int)ops.size()));
		return dfs(dp, 0, ops.size() - 1, ops);
	}
};
