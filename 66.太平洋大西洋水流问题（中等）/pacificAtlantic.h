#pragma once
#ifndef PACIFIC_ATLANTIC_H
#define PACIFIC_ATLANTIC_H

#include <vector>

using namespace std;


/**

    @class   Solution
	@brief   	作者：LeetCode - Solution
		链接：https ://leetcode-cn.com/problems/pacific-atlantic-water-flow/solution/tai-ping-yang-da-xi-yang-shui-liu-wen-ti-sjk3/
	来源：力扣（LeetCode）
		著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	Solution() {
		vector<vector<int>> heights = {{1, 2, 2, 3, 5}, { 3, 2, 3, 4, 4}, { 2, 4, 5, 3, 1}, { 6, 7, 1, 4, 5}, { 5, 1, 1, 2, 4 }
};
		auto ret = pacificAtlantic(heights);
	}

	vector<vector<int>> heights;
	vector<vector<int>> dirs = { {0,1},{1,0},{0,-1},{-1,0} };

	void dfs(int row, int col, vector<vector<bool>>& ocean) {
		int m = ocean.size();
		int n = ocean[0].size();
		if (ocean[row][col]) {
			return;
		}
		ocean[row][col] = true;
		for (int i = 0; i < 4; i++) {
			int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
			if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
				dfs(newRow, newCol, ocean);
			}
		}
	}

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		this->heights = heights;
		int m = heights.size();
		int n = heights[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));

		for (int i = 0; i < m; i++) {
			dfs(i, 0, pacific);
		}
		for (int j = 1; j < n; j++) {
			dfs(0, j, pacific);
		}
		for (int i = 0; i < m; i++) {
			dfs(i, n - 1, atlantic);
		}
		for (int j = 0; j < n - 1; j++) {
			dfs(m - 1, j, atlantic);
		}
		vector<vector<int>> result;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pacific[i][j] && atlantic[i][j]) {
					vector<int> cell;
					cell.emplace_back(i);
					cell.emplace_back(j);
					result.emplace_back(cell);
				}
			}
		}
		return result;
	}


};

#endif