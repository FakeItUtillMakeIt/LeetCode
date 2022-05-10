#pragma once
#ifndef RECENT_COUNTER_H
#define RECENT_COUNTER_H

#include <vector>
#include <string>

using namespace std;






class RecentCounter {
public:
	RecentCounter() {
		numCNT = 0;
		auto ret=ping(0);
	}

	int numCNT = 0;

	int lowIndex = 0;

	vector<vector<int>> timeSeq = { };

	int ping(int t) {
		vector<int> tmp = { t };
		timeSeq.push_back(tmp);
		int down = t - 3000;
		int high = t;

		for (int i=lowIndex;i<timeSeq.size();i++)
		{
			if (timeSeq[i][0]==0)
			{
				continue;
			}
			if (timeSeq[i][0] >= down )
			{
				break;
			}
		}

		
		numCNT = timeSeq.size()-lowIndex-1;
		
		return numCNT;
	}
};


class Solution
{
public:
	Solution() {
		RecentCounter* RC = new RecentCounter();
		RC->ping(1);
		RC->ping(100);
		RC->ping(3001);
		RC->ping(3002);
	}


private:

};

#endif
