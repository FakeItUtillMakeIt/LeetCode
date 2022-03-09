

#include<math.h>

class Solution {
public:

	int xArr[8] = { 2,1,-1,-2,-2,-1,1,2 };
	int yArr[8] = { 1,2,2,1,-1,-2,-2,-1 };

	bool update(int row, int column, int n) {
		//八个方向
		if (row >= 0 && row <= n-1 && column >= 0 && column <= n-1)
			return true;
		else
			return false;
	}
	//n为棋盘大小
	//得到当前位置下可让留下的移动方式
	void retCurrentLocNum(int xLoc, int yLoc, int n,int k,int count,int& calNum) {
		

		if (count==0)
		{
			calNum++;
			return ;
		}
		
		for (int i = 0; i < 8; i++)
		{
			int thiscount = count;
			/* code */
			int x = xLoc + xArr[i];
			int y = yLoc + yArr[i];
			auto update_flag = update(x, y, n);
 			if (update_flag) {
				thiscount--;
				
				retCurrentLocNum(x, y, n, thiscount, thiscount, calNum);
				
			}
			else
			{
				continue;
			}
		}

	}


	double knightProbability(int n, int k, int row, int column) {
		double totalProbNum = pow(8, k);
		int totalCorrentNum = 0;
		if (k == 0)
		{
			return 1;
		}
		if (n < 3)
		{
			return 0;
		}

	
		retCurrentLocNum(row, column, n, k, k, totalCorrentNum);
		
	
		return (double)totalCorrentNum / (double)totalProbNum;
	}
};