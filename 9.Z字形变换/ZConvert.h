#pragma once

#ifndef Z_CONVERT_H
#define Z_CONVERT_H

#include <string>
#include <vector>

using namespace  std;


//��� https://leetcode-cn.com/problems/zigzag-conversion/solution/6-z-zi-xing-bian-huan-c-c-by-bian-bian-xiong/
class Solution {
public:
	string convert(string s, int numRows) {

		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size()))); // ��ֹs�ĳ���С������
		int curRow = 0;
		bool goingDown = false;



		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) {// ��ǰ��curRowΪ0��numRows -1ʱ����ͷ��������ת��
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) {// ���ϵ��±�����
			ret += row;
		}

		return ret;
	}
};




#endif