/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h = new ListNode(0,head);
        ListNode* temp = head;
        ListNode* curr = h;
        while(n){
            temp = temp->next;
            n--;
        }
        while(temp!=NULL){
            temp = temp->next;
            curr = curr->next;
        }
        ListNode *hehe=curr->next;
        curr->next = curr->next->next;
        delete hehe;
        return h->next; 
    }
};