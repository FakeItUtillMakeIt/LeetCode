class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         //加个表头
        ListNode* res = new ListNode(-1);
        res->next = head;
        //前序节点
        ListNode* pre = res; 
        //当前节点
        ListNode* cur = head; 
        //找到m
        for(int i = 1; i < m; i++){ 
            pre = cur;
            cur = cur->next;
        }
        //从m反转到n
        for(int i = m; i < n; i++){ 
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        //返回去掉表头
        return res->next; 
    }
};
