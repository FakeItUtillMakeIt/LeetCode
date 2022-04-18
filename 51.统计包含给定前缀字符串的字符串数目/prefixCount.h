#pragma once
#ifndef PREFIX_COUNT_H
#define PREFIX_COUNT_H

#include <vector>
#include <string>


using namespace std;


class Solution {
public:
	Solution() {
		vector<string> words = { "abcdefg","abcdgh","abcfe" };
		auto ret = prefixCount(words, "abcd");
	}
	int prefixCount(vector<string>& words, string pref) {
		int count = 0;
		for (auto eachWord:words)
		{
			auto tmp = eachWord.find(pref);
			if (tmp==0)
			{
				count++;
			}
		}
		return count;

	}
};

#endif