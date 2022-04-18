#pragma once

#ifndef NESTED_INTEGER_H
#define NESTED_INTEGER_H

#include <vector>
#include <stack>
#include <string>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 class NestedInteger {
public:
	     // Constructor initializes an empty nested list.
	NestedInteger() {

		}
	
		     // Constructor initializes a single integer.
	NestedInteger(int value) {
		
		}
	
		     // Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const {

		}
	
		     // Return the single integer that this NestedInteger holds, if it holds a single integer
		     // The result is undefined if this NestedInteger holds a nested list
	int getInteger() const {

		}
	
		     // Set this NestedInteger to hold a single integer.
	void setInteger(int value) {

		}
	
		     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger& ni) {

		}
	
		     // Return the nested list that this NestedInteger holds, if it holds a nested list
		     // The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger>& getList() const {

		}

 private:
	 string nestString = "";
	
};

 /**

     @class   Solution
	 @brief    作者：LeetCode - Solution
	 链接：https ://leetcode-cn.com/problems/mini-parser/solution/mi-ni-yu-fa-fen-xi-qi-by-leetcode-soluti-l2ma/
 来源：力扣（LeetCode）
	 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     @details ~

 **/
 class Solution {
 public:
	 int index = 0;

	 NestedInteger deserialize(string s) {
		 if (s[index] == '[') {
			 index++;
			 NestedInteger ni;
			 while (s[index] != ']') {
				 ni.add(deserialize(s));
				 if (s[index] == ',') {
					 index++;
				 }
			 }
			 index++;
			 return ni;
		 }
		 else {
			 bool negative = false;
			 if (s[index] == '-') {
				 negative = true;
				 index++;
			 }
			 int num = 0;
			 while (index < s.size() && isdigit(s[index])) {
				 num = num * 10 + s[index] - '0';
				 index++;
			 }
			 if (negative) {
				 num *= -1;
			 }
			 return NestedInteger(num);
		 }
	 }
 };



#endif // !NESTED_INTEGER_H

