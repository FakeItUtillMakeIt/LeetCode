#pragma once
#ifndef ROTATE_STRING_H
#define ROTATE_STRING_H

#include <iostream>
#include <string>

using namespace std;


/**

    @class   Solution
	@brief   	���ߣ�LeetCode - Solution
		���ӣ�https ://leetcode-cn.com/problems/rotate-string/solution/xuan-zhuan-zi-fu-chuan-by-leetcode-solut-4hlp/
	��Դ�����ۣ�LeetCode��
		����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
    @details ~

**/
class Solution {
public:
	Solution() {
		auto ret = rotateString("abcdef", "cdefab");
	}

 /**
	 @brief  ���ȣ���� ss �� \textit{goal}goal �ĳ��Ȳ�һ������ô������ô��ת��ss �����ܵõ� \textit{goal}goal������ \text{false}false���ڳ���һ������Ϊ nn����ǰ���£����� ss ��ת ii λ������ \textit{goal}goal �е�ĳһλ�ַ� \textit{goal}[j]goal[j] ��Ӧ��ԭ ss �е��ַ�Ӧ��Ϊ s[(i+j) \bmod n]s[(i+j)modn]���ڹ̶� ii ������£��������� jj������Ӧ�ַ�����ͬ���򷵻� \text{true}true�����򣬼�������������ѡ�� ii�������е� ii ������ʹ ss ��� \textit{goal}goal���򷵻� \text{false}false��

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/rotate-string/solution/xuan-zhuan-zi-fu-chuan-by-leetcode-solut-4hlp/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
     @param  s    - 
     @param  goal - 
     @retval      - 
 **/
	bool rotateString(string s, string goal) {
		int m = s.size(), n = goal.size();
		if (m != n) {
			return false;
		}
		//ѭ������ ֱ���ҵ��Ǹ���
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
