#pragma once
#ifndef BACKSPACE_CAMPARE_H
#define BACKSPACE_CAMPARE_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		auto ret = backspaceCompare("y##fd##f", "y#f#o##f");
	}
	bool backspaceCompare(string s, string t) {
		string ss = "";
		string st = "";
		vector<char> ssV;
		vector<char> stV;
		for (int i=0;i<s.size();i++)
		{
			if (s[i]=='#')
			{
				if (!ssV.empty())
				{
					ssV.pop_back();
					continue;
				}
				
			}
			ssV.push_back(s[i]);
		}

		for (int i=0;i<t.size();i++)
		{
			if (t[i] == '#')
			{
				if (!stV.empty())
				{
					stV.pop_back();
					continue;
				}
				
			}
			stV.push_back(t[i]);
		}

		for (auto c:ssV)
		{
			ss.push_back(c);
		}
		for (auto c : stV)
		{
			st.push_back(c);
		}

		if (
			!strcmp(ss.c_str(),st.c_str()))
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
};

#endif