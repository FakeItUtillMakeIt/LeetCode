#pragma once

#ifndef FIND_RIGHT_INTERVAL_H
#define FIND_RIGHT_INTERVAL_H

#include <vector>
#include <algorithm>

using namespace std;


/**

    @class   Solution
    @brief   Ѱ��������
    @details ~

**/
class Solution {
public:
	Solution() {
		vector<vector<int>> intervals = { {2,3},{3,4},{1,2},{4,5} };
		auto ret = findRightInterval1(intervals);
	}

	vector<int> findRightInterval1(vector<vector<int>>& intervals) {
		vector<pair<int, int>> startIntervals;
		int n = intervals.size();
		for (int i = 0; i < n; i++) {
			startIntervals.emplace_back(intervals[i][0], i);
		}
		//����start��������
		sort(startIntervals.begin(), startIntervals.end());

		vector<int> ans(n, -1);
		for (int i = 0; i < n; i++) {
			//Ѱ���������������endi���������
			auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
			if (it != startIntervals.end()) {
				ans[i] = it->second;
			}
		}
		return ans;
	}

	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		vector<pair<int, int>> startIntervals;
		int n = intervals.size();
		vector<int> ans(n, -1);

		//�Ȱ�start��������
		for (int i = 0; i < n; i++)
		{
			startIntervals.push_back(make_pair(intervals[i][0], i));
		}
		sort(startIntervals.begin(), startIntervals.end());

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (startIntervals[j].first >= intervals[i][1])
				{
					ans[i] = startIntervals[j].second;
					break;
				}
			}
			
		}

		return ans;
	}
};




#endif
