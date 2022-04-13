#pragma once

#ifndef UPDATE_BOARD_H
#define UPDATE_BOARD_H

#include <vector>
using namespace std;


/**

    @class   Solution
	@brief   让我们一起来玩扫雷游戏！

	给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：

	'M' 代表一个 未挖出的 地雷，
	'E' 代表一个 未挖出的 空方块，
	'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
	数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
	'X' 则表示一个 已挖出的 地雷。
	给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。

	根据以下规则，返回相应位置被点击后对应的盘面：

	如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
	如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
	如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
	如果在此次点击中，若无更多方块可被揭露，则返回盘面。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/minesweeper
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    @details ~

**/


class Solution {
public:
	//表当前节点的周围八个点的坐标
	int dir_x[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
	int dir_y[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

	void dfs(vector<vector<char>>& board, int x, int y) {
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			int tx = x + dir_x[i];
			int ty = y + dir_y[i];
			if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
				continue;
			}
			// 不用判断 M，因为如果有 M 的话游戏已经结束了
			cnt += board[tx][ty] == 'M';//表示周围有几个炸弹
		}
		if (cnt > 0) {
			// 规则 3
			board[x][y] = cnt + '0';
		}
		else {
			// 规则 2
			board[x][y] = 'B';
			for (int i = 0; i < 8; ++i) {
				int tx = x + dir_x[i];
				int ty = y + dir_y[i];
				// 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
				if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
					continue;
				}
				dfs(board, tx, ty);
			}
		}
	}

	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int x = click[0], y = click[1];
		if (board[x][y] == 'M') {
			// 规则 1
			board[x][y] = 'X';
		}
		else {
			dfs(board, x, y);
		}
		return board;
	}
};


#endif
