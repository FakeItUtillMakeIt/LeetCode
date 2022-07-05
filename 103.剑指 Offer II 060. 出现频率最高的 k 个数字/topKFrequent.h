#pragma once
#ifndef TOPK_FREQUENT_H
#define TOPK_FREQUENT_H

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> a = { 1,1,2,2,3 };
		auto ret = topKFrequent(a, 2);
	}
	
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> numK;
		
		/*int* topK = new int[];
		int* topKCount = new int[];*/
		vector<int> topK(k);
		vector<int> topKCount(k);
		for (int num:nums)
		{
			numK[num]+=1;
		}
		for (int i=0;i<k;i++)
		{
			topK[i] = 0;
			topKCount[i] = 0;
		}

		int numKCount = 0;
		for (auto i=numK.begin();i!=numK.end();i++)
		{
			int z=0;
			for (int j=0;j<k;j++)
			{
				if (i->second>topKCount[j])
				{
					z = j;
					for (int j = k - 1; j > z; j--)
					{
						topKCount[j] = topKCount[j - 1];
						topK[j] = topK[j - 1];
					}
					topKCount[z] = i->second;
					topK[z] = i->first;
					break;
				}
			}
			
		}
		
		return topK;

	}
};

#endif