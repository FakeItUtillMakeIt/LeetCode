#pragma once

#ifndef SCARESCROW_NUM_SORT_H
#define SCARESCROW_NUM_SORT_H

#include <vector>


using namespace std;

class Solution {
public:
	vector<vector<int>> scareLoc = { {1,5},{2,3} ,{3,5},{4,3} };

	Solution() {
		scarecrowNumSort(3,scareLoc);
	}

	//字节跳动面试题
	//稻草人编号
	//如果现在N=3也就是整个大的正方形是3*3，按照3切分的话每个次大正方形（总共有9个）再继续被切成9份，这样每个小正方形的边长都是1，
	// 题目给出稻草人位置，每个稻草人恰好占据1个小正方形。判断哪个次大正方形里的稻草人最多。
	//解决方法：很直观，直接对每个次大正方形编号，再判断稻草人在哪个次大正方形里面，最后排序即可。

	vector<int> scarecrowNumSort(int N,vector<vector<int>>& scareLoc) {

		int** dataMat = new int* ;  //n~2*n~2
		for (int i=0;i<N*N;i++)
		{
			dataMat[i] = new int[N*N];
			
			for (int j=0;j<N*N;j++)
			{
				dataMat[i][j] =3* ((i)/N)+(j)/N+1;//存储大正方形编号
			}
			
		}

		vector<int> scareV,noScareV;
		//row  =  k/N  column = k%N;

		for (auto locArr:scareLoc)
		{
			for (int i=0;i<(N*N);i++)
			{
				for (int j=0;j<(N*N);j++)
				{
					if (locArr[0] == (j+1) && (9-locArr[1])==(i))
					{
						scareV.push_back(dataMat[i][j]);
					}
					
				}
			}
		}

		
		return scareV;

	}
};


#endif

