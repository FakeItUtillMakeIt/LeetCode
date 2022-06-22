#pragma once
#ifndef IS_ALIEN_SORTED_H
#define IS_ALIEN_SORTED_H

#include <vector>
#include <string>
#include <unordered_map>



using namespace std;

class Solution {
public:
	

	Solution() {
		vector<string> words = { "apple","app" };
		bool ret = isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz");
	}

	bool isAlienSorted(vector<string>& words, string order) {
		//order的key和索引对应关系
		unordered_map<char, int> linkG;
		for (int i=0;i<order.size();i++)
		{
			linkG[order[i]] = i;
		}

		int curIndex = 0;
		//应该满足当前索引的值大于前一个索引的值才继续，否则直接返回false
		
		for (int i=0;i<words[0].size();i++)
		{
			int preV = 0;
			int neigborDis = 0;
			int preI=-1;
			int curI=-1;
			for (int k=1;k<words.size();k++)
			{
				if (i>=words[k].size())
				{
					
					curI = -1;
				}
				else
				{
					curI = linkG[words[k][i]];
				}
				if (i>words[preV].size())
				{
					preI = -1;
				}
				else
				{
					preI = linkG[words[preV][i]];
				}
				
				neigborDis =  curI- preI;
				if (neigborDis >= 0)
				{
					preV = k;
				}
				else
				{
					return false;
				}
			}
		}
		return true;

	}
};


class Solution1 {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		vector<int> index(26);
		for (int i = 0; i < order.size(); i++) {
			index[order[i] - 'a'] = i;
		}

		//
		for (int i = 1; i < words.size(); i++) {
			bool valid = false;
			for (int j = 0; j < words[i - 1].size() && j < words[i].size(); j++) {
				int prev = index[words[i - 1][j] - 'a'];
				int curr = index[words[i][j] - 'a'];
				//字符不一样，且前面字符的索引顺序小于后面
				if (prev < curr) {
					valid = true;
					break;
				}
				else if (prev > curr) {
					return false;
				}
			}

			//前面字符串全部相等的情况下才比较字符串长度
			if (!valid) {
				/* 比较两个字符串的长度 */
				if (words[i - 1].size() > words[i].size()) {
					return false;
				}
			}
		}
		return true;
	}
};

#endif