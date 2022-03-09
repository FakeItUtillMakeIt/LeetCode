#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	//1,5,10,50,100,500,1000
	vector<char> romanList = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	vector<int> intList;
	//规则是I可出现在V，X左边，X可出现在L，C左边，C可出现在D,M左边
	//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX

	int romanToInt(string s) {
		int sumRoman = 0;
		for (int loc=0;loc<s.size();loc++)
		{
			char current_Roma = s[loc];
			switch (current_Roma)
			{
				
			case  'I':
				intList.push_back(1);
				break;
			case  'V':
				intList.push_back(5);
				break;
			case  'X':
				intList.push_back(10);
				break;
			case  'L':
				intList.push_back(50);
				break;
			case  'C':
				intList.push_back(100);
				break;
			case  'D':
				intList.push_back(500);
				break;
			case  'M':
				intList.push_back(1000);
				break;
			default:
				break;
			}
		}

		
		for (int ind=0;ind<intList.size();ind++)
		{
			if ((ind+1)<intList.size())
			{
				if (intList[ind]<intList[ind+1])
				{
					sumRoman += intList[ind + 1] - intList[ind];
					ind++;
				}
				/*else if ()
				{
				}*/
				else
				{
					sumRoman += intList[ind];
				}
			}
			else

				sumRoman += intList[ind];
			
		}
		return sumRoman;
	}

};