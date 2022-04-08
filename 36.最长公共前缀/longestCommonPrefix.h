#pragma once
#ifndef LONGEST_COMMON_PREFIX_H
#define LONGEST_COMMON_PREFIX_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:

	Solution() {
		vector<string> strs = { "long","longest" };
		auto ret=longestCommonPrefix(strs);
	}
	string longestCommonPrefix(vector<string>& strs) {
		string commonPrefix = strs[0];
		for (auto str1:strs)
		{
			int curCompareL = commonPrefix.size() >= str1.size() ? commonPrefix.size() : str1.size();
			int i = 0;
			string newCommonPrefix = "";
			while (curCompareL>0)
			{
				if (str1[i]==commonPrefix[i])
				{
					newCommonPrefix+=(str1[i]);
					i++;
					curCompareL--;
				}
				else
				{
					break;
				}
			}
			commonPrefix = newCommonPrefix;
		}
		return commonPrefix;
	}
};


#endif // LONGEST_COMMON_PREFIX_H
