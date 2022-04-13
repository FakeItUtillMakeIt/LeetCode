#pragma once
#ifndef NUMBER_OF_LINES_H
#define NUMBER_OF_LINES_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> widths = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };
		auto ret = numberOfLines(widths,"bbbcccdddaaa");
	}
	vector<int> numberOfLines(vector<int>& widths, string s) {
		
		int lineCost = 0;
		int useVal = 0;

		int lineUse = 1;

		vector<int> retV;
		for (int i=0;i<s.size();i++)
		{
			lineCost += widths[s[i] - 'a'];
			if (lineCost==100 && (i+1)!=s.size())
			{
				lineUse++;
				lineCost = 0;
			}
			else if (lineCost>100)
			{
				lineUse++;
				lineCost = widths[s[i] - 'a'];
			}
		}

		retV.push_back(lineUse);
		retV.push_back(lineCost);
		return retV;

	}
};

#endif
