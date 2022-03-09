#pragma once
#ifndef PRISON_AFTER_NDAYS_H
#define PRISON_AFTER_NDAYS_H

#include <vector>

using namespace std;


/**

    @class   Solution
	@brief   8 间牢房排成一排，每间牢房不是有人住就是空着。

每天，无论牢房是被占用或空置，都会根据以下规则进行更改：

如果一间牢房的两个相邻的房间都被占用或都是空的，那么该牢房就会被占用。
否则，它就会被空置。
（请注意，由于监狱中的牢房排成一行，所以行中的第一个和最后一个房间无法有两个相邻的房间。）

我们用以下方式描述监狱的当前状态：如果第 i 间牢房被占用，则 cell[i]==1，否则 cell[i]==0。

根据监狱的初始状态，在 N 天后返回监狱的状况（和上述 N 种变化）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prison-cells-after-n-days
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

