#pragma once

#ifndef MAX_CONSE_CUTIVE_ANSWERS_H
#define MAX_CONSE_CUTIVE_ANSWERS_H

#include <string>
#include <vector>

using namespace std;

/**

    @class   Solution
	@brief   一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。

给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：

每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:

	Solution() {

		auto ret=maxConsecutiveAnswers("FFTTTFFFTTTFFFF", 3);
	}
	int maxConsecutiveAnswers(string answerKey, int k) {
		int maxT = 0;
		int maxF = 0;

		vector<int> vecT,vecF;
		vector<int> maxVecT, maxVecF;

		char currentC=answerKey[0], nextC=answerKey[1];
		for (int i=0;i<answerKey.size()-1;i++)
		{
			currentC = answerKey[i];
			nextC = answerKey[(int)(i + 1)];
			if (currentC==nextC)
			{
				if (currentC=='T')
				{
					maxT++;
				}
				else
				{
					maxF++;
				}
			}
			else
			{
				
				//存储断掉的索引处
				if (maxT>maxF)
				{
					vecT.push_back(i);
					maxVecT.push_back(maxT+1);//存储从索引处断掉的F的长度
				}
				else
				{
					maxVecF.push_back(maxF+1); //存储从索引处断掉的T的长度
					vecF.push_back(i);
				}
				maxF = 0;
				maxT = 0;
				
			}
		}
		//存储断掉的索引处
		if (maxT > maxF)
		{
			maxVecT.push_back(maxT + 1);//存储T的长度
			vecT.push_back(answerKey.size() - 1);
		}
		else
		{
			maxVecF.push_back(maxF + 1); //存储F的长度
			vecF.push_back(answerKey.size() - 1);
		}
		
		int maxLen = 0;
		int lenC = 0;
		int tmpk = k;
		int start = 1;
		int minSize;
		vecT.size() > vecF.size() ? minSize = vecF.size() : minSize = vecT.size();
		


		return maxLen;
	}
};

#endif
