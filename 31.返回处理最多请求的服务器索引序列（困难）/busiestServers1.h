#pragma once

#ifndef BUSIEST_SERVERS_H
#define BUSIEST_SERVERS_H

#include <vector>
#include <set>
#include <queue>
//#include <priority_queue>

using namespace std;

/**

    @class   Solution
	@brief   		作者：LeetCode - Solution
			链接：https ://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests/solution/zhao-dao-chu-li-zui-duo-qing-qiu-de-fu-w-e0a5/
		来源：力扣（LeetCode）
			著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	Solution() {
		vector<int> arraial = { 1,3,4,5,6,11,12,13,15,19,20,21,23,25,31,32 };
		vector<int> load = { 9,16,14,1,5,15,6,10,1,1,7,5,11,4,4,6 };
		auto ret = busiestServers(7, arraial, load);
	}

	//k为服务器数量  arrival为请求到达时间  load为请求处理时长  返回处理最多请求的服务器索引
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {


			vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
				set<int> available;
				for (int i = 0; i < k; i++) {
					available.insert(i);
				}
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
				vector<int> requests(k);
				for (int i = 0; i < arrival.size(); i++) {
					while (!busy.empty() && busy.top().first <= arrival[i]) {
						available.insert(busy.top().second);
						busy.pop();
					}
					if (available.empty()) {
						continue;
					}
					auto p = available.lower_bound(i % k);
					if (p == available.end()) {
						p = available.begin();
					}
					requests[*p]++;
					busy.emplace(arrival[i] + load[i], *p);
					available.erase(p);
				}
				int maxRequest = *max_element(requests.begin(), requests.end());
				vector<int> ret;
				for (int i = 0; i < k; i++) {
					if (requests[i] == maxRequest) {
						ret.push_back(i);
					}
				}
				return ret;
			}
	



	}
};

#endif
