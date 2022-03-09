

#include <vector>

using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int rest5 = 0;//零钱5
		int rest10 = 0;//10
        bool ret=true;
		for (auto bill:bills)
		{
			if (bill==5)
			{
				rest5 += 1;
			
	
			}
			else if (bill==10)
			{
				rest5 -= 1;
				rest10 += 1;
			}
			else if(bill==20)
			{
				rest5 -= 1;
				if (rest10>0)
				{
					rest10 -= 1;
				}
				else
				{
					rest5 -= 2;
				}
				
			}

            if (rest5>=0 && rest10>=0)
		{
			ret&=true;
		}
		else
		{
			ret&=false;
		}
		}
		return ret;
	}
};

