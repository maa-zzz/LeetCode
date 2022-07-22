class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode *prev=NULL,*cur=head,*nxt=head;
        while(nxt->next!=NULL){
            nxt=nxt->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        cur->next=prev;
        return cur;
    }
};