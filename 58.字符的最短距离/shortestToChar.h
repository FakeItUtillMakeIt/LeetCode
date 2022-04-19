#pragma once
#ifndef SHORTEST_TO_CHAR_H
#define SHORTEST_TO_CHAR_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> shortestToChar(string s, char c) {
		vector<int> charLocV;
		vector<int> nearestDis;
		for (int i=0;i<s.size();i++)
		{
			if (s[i]==c)
			{
				charLocV.push_back(i);
			}
		}

		for (int i=0;i<s.size();i++)
		{
			int minAbsD = s.size();
			for (auto d:charLocV)
			{
				if (minAbsD>abs(i-d))
				{
					minAbsD = abs(i - d);
				}
			}
			nearestDis.push_back(minAbsD);
		}

		return nearestDis;
	}
};

#endif
