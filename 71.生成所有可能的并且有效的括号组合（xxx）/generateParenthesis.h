#pragma once

#ifndef GENERATE_PARENT_THESIS_H
#define GENERATE_PARENT_THESIS_H

#include <vector>
#include <string>

using namespace std;

/**

    @class   Solution
    @brief   ���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
	���ߣ�LeetCode - Solution
���ӣ�https ://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
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
			//��������ʱ���ж��Ƿ���Ч
			if (valid(current)) {
				result.push_back(current);
			}
			return;
		}
		current += '(';
		//��ȫ��Ϊ������
		generate_all(current, n, result);
		current.pop_back();
		//���滻һЩ������
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