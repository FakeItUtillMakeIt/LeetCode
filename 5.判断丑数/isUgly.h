#pragma once
class Solution {
public:
	bool isUgly(int n) {
		if (n==1)
		{
			return true;
		}
		if (n == 2 || n == 3 || n == 5)
		{
			return true;
		}
		else
		{
			bool total = false;
			if (n % 2 == 0)
			{
				total |= isUgly(n / 2);
			}
			if (n % 3 == 0)
			{
				total |= isUgly(n / 3);
			}
			if (n % 5 == 0)
			{
				total |= isUgly(n / 5);
			}
			return total;
		}
		
		
	}
};