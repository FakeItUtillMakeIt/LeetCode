#pragma once
#ifndef COUNT_SEGMENT_H
#define COUNT_SEGMENT_H

#include <string>
using namespace std;

class Solution {
public:
	Solution() {
		auto ret = countSegments("Hello, my name is Joh");
	}

	int countSegments(string s) {
		int wordsCount = 0;
		string splitString = " ";
		auto pch = strtok((char*)s.c_str(), splitString.c_str());
		while (pch!=NULL)
		{
			wordsCount++;
			pch = strtok(NULL, splitString.c_str());
		}
		return wordsCount;
	}
};

#endif
