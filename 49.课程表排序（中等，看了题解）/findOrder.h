#pragma once

#ifndef FIND_ORDER_H
#define FIND_ORDER_H

#include <vector>
#include <map>
#include <iostream>

using namespace std;

/**

    @class   Solution
    @brief   https://leetcode-cn.com/problems/course-schedule-ii/
    @details ~

**/
class Solution {
public:
    Solution() {
        vector<int> tmp = { 1,0 };
        vector<int> tmp1 = { 2,0 };
        vector<int> tmp2 = { 3,1 };
        vector<int> tmp3 = { 3,2 };
        vector < vector<int>> preq = { tmp,tmp1,tmp2,tmp3 };
        auto ret = findOrder(4, preq);
    }


		
			// �洢����ͼ
			vector<vector<int>> edges;
			// ���ÿ���ڵ��״̬��0=δ������1=�����У�2=�����
			vector<int> visited;
			// ��������ģ��ջ���±� 0 Ϊջ�ף�n-1 Ϊջ��
			vector<int> result;
			// �ж�����ͼ���Ƿ��л�
			bool valid = true;

		public:
			void dfs(int u) {
				// ���ڵ���Ϊ�������С�
				visited[u] = 1;
				// ���������ڽڵ�
				// ֻҪ�����л�������ֹͣ����
				for (int v : edges[u]) {
					// �����δ��������ô�������ڽڵ�
					if (visited[v] == 0) {
						dfs(v);
						if (!valid) {
							return;
						}
					}
					// ����������С�˵���ҵ��˻�
					else if (visited[v] == 1) {
						valid = false;
						return;
					}
				}
				// ���ڵ���Ϊ������ɡ�
				visited[u] = 2;
				// ���ڵ���ջ
				result.push_back(u);
			}

			vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
				edges.resize(numCourses);
				visited.resize(numCourses);
				for (const auto& info : prerequisites) {
					edges[info[1]].push_back(info[0]);
				}
				// ÿ����ѡһ����δ�������Ľڵ㣬��ʼ���������������
				for (int i = 0; i < numCourses && valid; ++i) {
					if (!visited[i]) {
						dfs(i);
					}
				}
				if (!valid) {
					return {};
				}
				// ���û�л�����ô������������
				// ע���±� 0 Ϊջ�ף������Ҫ�����鷴�����
				reverse(result.begin(), result.end());
				return result;

		
	}
};

#endif
