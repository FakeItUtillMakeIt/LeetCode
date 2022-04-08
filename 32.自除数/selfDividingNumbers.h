#pragma once

#ifndef SELF_DIVIDING_NUMBERS_H
#define SELF_DIVIDING_NUMBERS_H

#include <vector>

using namespace std;


/**

    @class   Solution
    @brief   返回left-right区间的自除数
    @details ~

**/
class Solution {
public:
    Solution() {
        auto ret = selfDividingNumbers(1, 22);
    }

    bool selfDividingPossiable(int num) {
        int cur_num = num;
        vector<int> divdeV;
        while (num>0)
        {
            divdeV.push_back(num % 10);
            num /= 10;
        }
        for (auto  divd: divdeV)
        {
            if (divd==0)
            {
                return false;
            }
            if (cur_num%divd!=0)
            {
                return false;
            }
        }
        return true;
    }

	vector<int> selfDividingNumbers(int left, int right) {
        vector<int> retArr;
        bool flag;
        for (int value=left;value<=right;value++)
        {
            flag=selfDividingPossiable(value);
            if (flag == true) {
                retArr.push_back(value);
            }
        }
        return retArr;
	}
};

#endif