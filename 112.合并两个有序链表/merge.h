/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* newHead=new ListNode(-1);
		ListNode* temp=newHead;
		//newHead->next=pHead1;
		
		while(pHead1 || pHead2){
			if(pHead1 && pHead2){
				if(pHead1->val<pHead2->val){
					ListNode* node=new ListNode(pHead1->val);
					temp->next=node;
					temp=temp->next;
					pHead1=pHead1->next;
				}
				else{
					ListNode* node=new ListNode(pHead2->val);
					temp->next=node;
					temp=temp->next;
					pHead2=pHead2->next;
				}
			}
			else{
				if(pHead1){
					temp->next=pHead1;
					pHead1=nullptr;
				}
				else{
					temp->next=pHead2;
					pHead2=nullptr;
				}
			}
			
		}
		return newHead->next;
    }
};
