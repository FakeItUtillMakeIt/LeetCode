#pragma once
#ifndef ROTATE_STRING_H
#define ROTATE_STRING_H

#include <iostream>
#include <string>

using namespace std;


/**

    @class   Solution
	@brief   	作者：LeetCode - Solution
		链接：https ://leetcode-cn.com/problems/rotate-string/solution/xuan-zhuan-zi-fu-chuan-by-leetcode-solut-4hlp/
	来源：力扣（LeetCode）
		著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    @details ~

**/
class Solution {
public:
	Solution() {
		auto ret = rotateString("abcdef", "cdefab");
	}

 /**
	 @brief  首先，如果 ss 和 \textit{goal}goal 的长度不一样，那么无论怎么旋转，ss 都不能得到 \textit{goal}goal，返回 \text{false}false。在长度一样（都为 nn）的前提下，假设 ss 旋转 ii 位，则与 \textit{goal}goal 中的某一位字符 \textit{goal}[j]goal[j] 对应的原 ss 中的字符应该为 s[(i+j) \bmod n]s[(i+j)modn]。在固定 ii 的情况下，遍历所有 jj，若对应字符都相同，则返回 \text{true}true。否则，继续遍历其他候选的 ii。若所有的 ii 都不能使 ss 变成 \textit{goal}goal，则返回 \text{false}false。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/rotate-string/solution/xuan-zhuan-zi-fu-chuan-by-leetcode-solut-4hlp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     @param  s    - 
     @param  goal - 
     @retval      - 
 **/
	bool rotateString(string s, string goal) {
		int m = s.size(), n = goal.size();
		if (m != n) {
			return false;
		}
		//循环遍历 直至找到那个点
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < n; j++) {
				if (s[(i + j) % n] != goal[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
		return false;

	}
};


#endif
