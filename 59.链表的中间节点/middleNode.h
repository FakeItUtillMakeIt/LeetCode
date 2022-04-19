#pragma once

#ifndef MIDDLE_NODE_H
#define MIDDLE_NODE_H

#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
	 ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    Solution() {
        ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
        middleNode(head);
    }

    ListNode* middleNode(ListNode* head) {
        vector<int> headV;
        while (head!=nullptr)
        {
            headV.push_back(head->val);
            head = head->next;
        }

        ListNode* curHead=new ListNode();
        head = curHead;
        
        for (int i=headV.size()/2;i<headV.size(); i++)
        {
            ListNode* nextNode;
            curHead->val=headV[i];
            if (i!=(headV.size()-1))
            {
                nextNode = new ListNode;
            }
            else
            {
                nextNode = nullptr;
            }
            
            curHead->next = nextNode;
            curHead = curHead->next;
        }

        return head;
    }
};

#endif
