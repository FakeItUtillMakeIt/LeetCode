#pragma once
#ifndef PRISON_AFTER_NDAYS_H
#define PRISON_AFTER_NDAYS_H

#include <vector>

using namespace std;


/**

    @class   Solution
	@brief   8 ���η��ų�һ�ţ�ÿ���η���������ס���ǿ��š�

ÿ�죬�����η��Ǳ�ռ�û���ã�����������¹�����и��ģ�

���һ���η����������ڵķ��䶼��ռ�û��ǿյģ���ô���η��ͻᱻռ�á�
�������ͻᱻ���á�
����ע�⣬���ڼ����е��η��ų�һ�У��������еĵ�һ�������һ�������޷����������ڵķ��䡣��

���������·�ʽ���������ĵ�ǰ״̬������� i ���η���ռ�ã��� cell[i]==1������ cell[i]==0��

���ݼ����ĳ�ʼ״̬���� N ��󷵻ؼ�����״���������� N �ֱ仯��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/prison-cells-after-n-days
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
    @details ~

**/
class Solution {
public:
	Solution() {
		vector<int> data = { 0,1,0,1,1,0,0,1 };

		auto ret = prisonAfterNDays(data,7);
	}

	vector<int> prisonAfterNDays(vector<int>& cells, int n) {

		vector<vector<int>> allcells;
		int index = 0;
		for (int i=0;i<15;i++)
		{
			
			auto tmpV = cells;
			
			for (int j=1;j<cells.size()-1;j++)
			{
				tmpV[0] = 0;
				auto f = (cells[j - 1] xor cells[j + 1]);
				if (!f) {
					tmpV[j] = 1;
				}
				else
				{
					tmpV[j] = 0;
				}
			}
			tmpV[tmpV.size() - 1] = 0;
			cells = tmpV;
			allcells.push_back(cells);
			for (auto d:cells)
			{
				cout << d << " ";
			}
			cout <<"   " << index << endl;
			index++;
		}
		
		
		
		return allcells[n%14];
	}
};

#endif

