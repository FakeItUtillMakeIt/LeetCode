#pragma once

#ifndef CAN_REORDER_DOUBLE_H
#define CAN_REORDER_DOUBLE_H

#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

/**

    @class   Solution
    @brief   二倍数对数组
    @details ~

**/
class Solution {
public:
    Solution() {
        vector<int> arr = { 2,1,2,1,1,1,2,2 };
        auto ret = canReorderDoubled(arr);
    }

	bool canReorderDoubled(vector<int>& arr) {


        sort(arr.begin(), arr.end());
		int sum10e6 = 0;

        for (int i=0;i<arr.size();i++)
        {
            int currentNum1 = arr[i];
            
			for (int j = i + 1; j < arr.size(); j++)
			{
				if ((currentNum1 >= -pow(10, 5) && currentNum1 <= pow(10, 5)) && (arr[j]>=-pow(10,5) && arr[j]<=pow(10,5)))
				{
					if ((currentNum1<0 && 2 * arr[j] > currentNum1) || (currentNum1 > 0) && arr[j] / 2 > currentNum1)
					{
						return false;
					}
					if (currentNum1 >= 0)
					{
						if ((currentNum1 * 2) == arr[j])
						{
							sum10e6++;
							arr[j] = pow(10, 6);
							break;
						}
					}
					else
					{
						if (currentNum1 == arr[j] * 2)
						{
							sum10e6++;
							arr[j] = pow(10, 6);
							break;
						}
					}
				}
				else
				{
					continue;
				}
			
            }

           
        }
		
		
		return sum10e6 == arr.size() / 2 ? true : false;
        
	}
};

#endif