#pragma once

#ifndef IS_VALID_H
#define IS_VALID_H
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	Solution() {
		auto ret = isValid("()[]{}");
	}

	bool isValid(string s) {

		stack<char> zuobiankuohan;
		for (auto s1:s)
		{
			if (s1=='{' || s1=='[' || s1=='(')
			{
				zuobiankuohan.push(s1);
			}
			if (s1 == '}')
			{
				if (zuobiankuohan.top() == '{')
				{
					zuobiankuohan.pop();
				}
			}
			if (s1 == ']')
			{
				if (zuobiankuohan.top() == '[')
				{
					zuobiankuohan.pop();
				}
			}
			if (s1 == ')')
			{
				if (zuobiankuohan.top() == '(')
				{
					zuobiankuohan.pop();
				}
			}
		}
		
		if (zuobiankuohan.empty())
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