#pragma once

#ifndef FIND_RESTAURANT_H
#define FIND_RESTAURANT_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
		vector<string> input1 = { "Shogun","Tapioca Express","Buger King","KFC" };
		vector<string> input2 = { "Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun" };
		auto ret = findRestaurant(input1,input2);
	}

	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int index1, index2;
		vector<string> bothLike;
		vector<int> one, two;
		vector<string> retBothLike;
		for (index1=0;index1<list1.size();index1++)
		{
			for (index2=0;index2<list2.size();index2++)
			{
				if (!strcmp(list1[index1].c_str(),list2[index2].c_str()))
				{
					one.push_back(index1);
					two.push_back(index2);
					bothLike.push_back(list1[index1]);
				}
			}
		}
		int minIndexSum = 2000;
		for (int a=0;a<one.size();a++)
		{
			if ((one[a]+two[a])<minIndexSum)
			{
				minIndexSum = (one[a] + two[a]);
				retBothLike.clear();
				retBothLike.push_back(bothLike[a]);
			}
			else if ((one[a] + two[a])==minIndexSum)
			{
				retBothLike.push_back(bothLike[a]);
			}
		}
		return retBothLike;
	}
};
#endif
