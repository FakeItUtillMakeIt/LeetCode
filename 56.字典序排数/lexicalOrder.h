#pragma once
#ifndef LEXICAL_ORDER_H
#define LEXICAL_ORDER_H
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		auto ret = lexicalOrder(13);
	}

	void curNumFirstNum(int n,int maxNum,vector<int>& leicalV) {
		if (n>maxNum)
		{
			return;
		}
		leicalV.push_back(n);
		for (int i = 0; i < 10; i++)
		{
			int a = n * 10 + i;
			curNumFirstNum(a, maxNum, leicalV);
		}

	}

	vector<int> lexicalOrder(int n) {
		vector<int> lexcalV(n);
		for (int i=1;i<10;i++)
		{
			curNumFirstNum(i,n,lexcalV);
		}
		return lexcalV;
	}
};

#endif