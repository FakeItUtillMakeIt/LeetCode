#pragma once

#ifndef GENERATE_PARENT_THESIS_H
#define GENERATE_PARENT_THESIS_H

#include <vector>
#include <string>

using namespace std;

/**

    @class   Solution
    @brief   数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
	作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
	bool valid(const string& str) {
		int balance = 0;
		for (char c : str) {
			if (c == '(') {
				++balance;
			}
			else {
				--balance;
			}
			if (balance < 0) {
				return false;
			}
		}
		return balance == 0;
	}

	void generate_all(string& current, int n, vector<string>& result) {
		if (n == current.size()) {
			//长度满足时，判断是否有效
			if (valid(current)) {
				result.push_back(current);
			}
			return;
		}
		current += '(';
		//先全部为左括号
		generate_all(current, n, result);
		current.pop_back();
		//逐渐替换一些左括号
		current += ')';
		generate_all(current, n, result);
		current.pop_back();
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string current;
		generate_all(current, n * 2, result);
		return result;
	}
};


#endif