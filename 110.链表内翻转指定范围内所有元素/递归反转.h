class Solution {
public:

    ListNode* temp=NULL;

    ListNode* reverse(ListNode* node,int n){
        if(n==1){
            temp=node->next;//记录n之后的
            return node;
        }
        ListNode* nnode=reverse(node->next, n-1);
        //翻转
        node->next->next=node;//递归翻转
        node->next=temp;//将n之后的顺序链表添加到尾部
        return nnode;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==1){
            return reverse(head,n);
        }
        ListNode* node=reverseBetween(head->next,m-1,n-1);
        head->next=node;
        return head;
    }
};
