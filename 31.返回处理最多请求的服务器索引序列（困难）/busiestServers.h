#pragma once

#ifndef BUSIEST_SERVERS_H
#define BUSIEST_SERVERS_H

#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> arraial = { 1,3,4,5,6,11,12,13,15,19,20,21,23,25,31,32 };
		vector<int> load = { 9,16,14,1,5,15,6,10,1,1,7,5,11,4,4,6 };
		auto ret = busiestServers(7, arraial, load);
	}

	//k为服务器数量  arrival为请求到达时间  load为请求处理时长  返回处理最多请求的服务器索引
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

		vector<vector<int>> serverCurrentStatus;//存储服务器运行过的任务和运行时长
	
		for (int i=0;i<k;i++)
		{
			vector<int> tasks;
			tasks.push_back(1);//存储请求任务结束时间
			serverCurrentStatus.push_back(tasks);
		}


		for (int i=0;i<arrival.size();i++)
		{
			int index = 0;
			int request = arrival[i];//请求任务开始时间
			int requestLoad = load[i];//请求任务持续时间
			//如果第 (i % k) 个服务器空闲，那么对应服务器会处理该请求。
			if (serverCurrentStatus[i % k][serverCurrentStatus[i % k].size()-1]<=request)
			{
				serverCurrentStatus[i % k].push_back(request + requestLoad);
			}
			//否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。比方说，如果第 i 个服务器在忙，那么会查看第 (i+1) 个服务器，第 (i+2) 个服务器等等。
			else
			{
				bool flag = false;
				for (int j=((i%k)+1) ;j<k;j++)
				{
					auto server = serverCurrentStatus[j];
					if (server[server.size() - 1] <= request)
					{
						serverCurrentStatus[j].push_back(request + requestLoad);//第index个服务器的空闲时间
						flag = true;
						break;
					}
					
				}
				if (!flag)
				{
					for (int j = 0; j < (i%k); j++)
					{
						auto server = serverCurrentStatus[j];
						if (server[server.size() - 1] <= request)
						{
							serverCurrentStatus[j].push_back(request + requestLoad);//第index个服务器的空闲时间
							break;
						}
						
					}
				}
			}
			
		}

		vector<int> allBusyestServer;
		int maxSum = 0;
		for (int i=0;i<serverCurrentStatus.size();i++)
		{
			if (serverCurrentStatus[i].size()>maxSum)
			{
				maxSum = serverCurrentStatus[i].size();
			}
		}
		for (int i=0;i<serverCurrentStatus.size();i++)
		{
			if (serverCurrentStatus[i].size()==maxSum)
			{
				allBusyestServer.push_back(i);
			}
		}
		return allBusyestServer;

	}
};

#endif
