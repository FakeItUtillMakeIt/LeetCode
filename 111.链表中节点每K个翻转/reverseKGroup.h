/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */

    ListNode* reverse(ListNode* head,int n){
        int length=0;
        ListNode* temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(length<n){
            return head;
        }

        ListNode* res=new ListNode(-1);        

        ListNode* cur=head;
        ListNode* pre=res;
        res->next=head;

        for(int i=1;i<n;i++){
            ListNode* temp=cur->next;
            cur->next=temp->next;
            temp->next=pre->next;
            pre->next=temp;
        }
        cur->next=reverse(cur->next, n);

        return res->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        // write code here
        ListNode* res=new ListNode(-1);
        res->next=reverse(head, k);

        return res->next;
    }
};
