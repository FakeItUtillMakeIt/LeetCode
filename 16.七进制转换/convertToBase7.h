#include<stdlib.h>
#include<string>

class Solution {
public:
    string convertToBase7(int num) {
		
		string ret_s = "";
		
		if (num>0)
		{
			ret_s="";
		}
		else if(num<0)
		{
			ret_s="-";
		}
		else if(num==0){
			ret_s = "0";
			return ret_s;
		}
		num = abs(num);
		stack<int> arr;
		int cur_c,cur_y;
		
		while (num > 0)
		{
			
			cur_y = num % 7;
			num = num / 7;
			arr.push(cur_y);
		}
		
		while (!arr.empty())
		{
			char s[4];
			//itoa(arr.top(),s,10);
            sprintf(s,"%d",arr.top());
			ret_s += s;
			arr.pop();
		}
		

		return ret_s;
	}
};