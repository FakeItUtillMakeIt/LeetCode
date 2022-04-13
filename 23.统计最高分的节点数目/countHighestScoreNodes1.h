#pragma once

#include "countHighestScoreNodes1.h"
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
	Solution() {
		vector<int> a = { -1,2,0,2,0 };
		auto ret = countHighestScoreNodes(a);
	}

	unordered_map<int, int>zuo;//ͳ��ÿ���ڵ��������ڵ����
	unordered_map<int, int>you;
	int dfs(vector<int>& left, vector<int>& right, int head)
	{
		if (left[head] == -1 && right[head] == -1)
		{
			return 1;//���û�ж��ӣ�ֱ�ӷ���1
		}
		int m = 0, n = 0;
		if (left[head] != -1)
		{
			m = dfs(left, right, left[head]);//������ӣ���ȥdfs
		}
		if (right[head] != -1)
		{
			n = dfs(left, right, right[head]);
		}
		zuo[head] = m;//�������ڵ����
		you[head] = n;
		return m + n + 1;
	}
	int countHighestScoreNodes(vector<int>& parents) {
		vector<int>left(parents.size(), -1);//ÿ���ڵ������ӣ���ʼ��Ϊ-1
		vector<int>right(parents.size(), -1);//ÿ���ڵ���Ҷ��ӣ���ʼ��Ϊ-1
		int tou = -1;//ͷ�ڵ㣬��ʼ��Ϊ-1��
		for (int i = 0; i < parents.size(); i++)
		{
			if (parents[i] == -1)
			{
				tou = i;//�ҵ�ͷ�ڵ���
				continue;
			}
			if (left[parents[i]] == -1)
			{
				left[parents[i]] = i;//i�ĸ��׽ڵ㻹û������ӣ��Ȱ���iΪ����ӡ�
			}
			else {
				right[parents[i]] = i;
			}
		}
		dfs(left, right, tou);
		long long mxfen = 0;//���ķ���
		int ans = 0;//�𰸣����������ڵ�ĸ���
		long long now = 0;//��ǰ�ڵ�ķ���
		vector<long long>cnt;//ÿ���ڵ�ķ�����������mxfen������ͳ��ans
		for (int i = 0; i < parents.size(); i++)
		{
			now = 1;
			int m = zuo[i];//i���������нڵ����
			int n = you[i];
			int k = parents.size() - m - n - 1;
			if (m)//����������ǿգ����ǲż��㣬�����㷢��now��ʼ��Ϊ1
			{
				now *= m;
			}
			if (n)//�������ǿ�
			{
				now *= n;
			}
			if (k)//���ڵ�ǿ�
			{
				now *= k;
			}
			cnt.push_back(now);
			mxfen = max(mxfen, now);
		}
		for (int i = 0; i < parents.size(); i++)
		{
			if (cnt[i] == mxfen)
			{
				ans++;//ͳ�ƴ�
			}
		}

		return ans;
	}
};


