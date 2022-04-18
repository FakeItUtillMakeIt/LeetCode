#pragma once
#ifndef BULB_SWTICH_H
#define BULB_SWTICH_H

#include <algorithm>
/**

    @class   Solution
	@brief   作者：LeetCode - Solution
			链接：https ://leetcode-cn.com/problems/bulb-switcher/solution/deng-pao-kai-guan-by-leetcode-solution-rrgp/
		来源：力扣（LeetCode）
			著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	int bulbSwitch(int n) {

		return sqrt(n + 0.5);

	}
};

#endif