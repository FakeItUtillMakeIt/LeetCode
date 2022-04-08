#pragma once

#ifndef COUNT_MAX_OR_SUBSET_H
#define COUNT_MAX_OR_SUBSET_H

#include <vector>
using namespace std;
/**

    @class   Solution
    @brief   Á´½Ó£ºhttps ://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets/solution/tong-ji-an-wei-huo-neng-de-dao-zui-da-zh-r6zd/
    @details ~

**/
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    cur |= nums[j];
                }
            }
            if (cur == maxValue) {
                cnt++;
            }
            else if (cur > maxValue) {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};





#endif