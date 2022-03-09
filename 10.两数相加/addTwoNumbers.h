#pragma once

#include <stack>

using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
  };
  class Solution {
  public:
	  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		  ListNode* head = nullptr, * tail = nullptr;
		  int carry = 0;
		  while (l1 || l2) {
			  int n1 = l1 ? l1->val : 0;
			  int n2 = l2 ? l2->val : 0;
			  int sum = n1 + n2 + carry;
			  if (!head) {
				  head = tail = new ListNode(sum % 10);
			  }
			  else {
				  tail->next = new ListNode(sum % 10);
				  tail = tail->next;
			  }
			  carry = sum / 10;
			  if (l1) {
				  l1 = l1->next;
			  }
			  if (l2) {
				  l2 = l2->next;
			  }
		  }
		  if (carry > 0) {
			  tail->next = new ListNode(carry);
		  }
		  return head;
	  }


    ListNode* l1;
    ListNode* l2;

    Solution() {
        l1 = new ListNode;
        l2 = new ListNode;

        ListNode* data1 =new ListNode;
        ListNode* data2 =new ListNode;
        data1->val = 4;
        data2->val = 3;
        data2->next = nullptr;
        data1->next = data2;

        l1->val = 2;
        l1->next = data1;

		ListNode* data3 = new ListNode;
		ListNode* data4 = new ListNode;
		data3->val = 6;
		data4->val = 4;
		data4->next = nullptr;
		data3->next = data4;

		l2->val = 5;
		l2->next = data3;

        addTwoNumbers(l1, l2);
    }
    

};