#pragma once

#ifndef MINIMUM_ABS_DIFFERENCE_H
#define MINIMUM_ABS_DIFFERENCE_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	Solution() {
		vector<int> arr = { 3,8,-10,23,19,-4,-14,27 };
		auto ret = minimumAbsDifference(arr);
	}

	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		vector<vector<int>> ret;
		vector<int> minIndex;
		int minDis = pow(10, 7);
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size()-1; i++) {
			if (minDis > (arr[i + 1] - arr[i])) {
				minDis = arr[i + 1] - arr[i];
				minIndex.clear();
				//minIndex.push_back(i);
			}
			if (minDis == (arr[i + 1] - arr[i])) {
				minDis = arr[i + 1] - arr[i];
				minIndex.push_back(i);
			}
		}
		for (int i = 0; i < minIndex.size(); i++) {
			ret.push_back({ arr[minIndex[i]],arr[minIndex[i + 1]] });
		}
		return ret;
	}
};

#endif
