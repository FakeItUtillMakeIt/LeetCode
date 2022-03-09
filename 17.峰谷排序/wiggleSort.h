#pragma once

#ifndef WIGGLE_SORT_H
#define WIGGLE_SORT_H

#include <vector>
#include <algorithm>
using namespace std;

//��һ�����������У����塱�Ǵ��ڻ��������������Ԫ�أ���Ӧ�أ�
//���ȡ���С�ڻ��������������Ԫ�ء����磬������{5, 8, 4, 2, 3, 4, 6}�У�{8, 6}�Ƿ壬 {5, 2}�ǹȡ����ڸ���һ���������飬�������鰴����ȵĽ���˳������
class Solution {
public:
	Solution() {
		vector<int> data = { 5,8,4,2,3,4,6 };
		wiggleSort(data);
	}

	void wiggleSort(vector<int>& nums) {

		int minV;//��λ��
		vector<int> topV, bottomV;
		
		sort(nums.begin(), nums.end());
		
		for (int i=0;i<nums.size();i++)
		{
			if (i<nums.size()/2)
			{
				bottomV.push_back(nums[i]);
			}
			else
			{
				topV.push_back(nums[i]);
			}
		}
		
		nums.clear();
		bool flag = false;
		while (!topV.empty() || !bottomV.empty())
		{
			if (!flag)
			{
				nums.push_back(topV.back());
				topV.pop_back();
			}
			else
			{
				nums.push_back(bottomV.back());
				bottomV.pop_back();
			}
			flag = !flag;
		}

	}
};

#endif