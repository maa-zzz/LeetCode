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
    ListNode* msort(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        while(l1 and l2){
            if(l1->val > l2->val){
                result->next = l2;
                l2 = l2->next;
            }
            else{
                result->next = l1;
                l1 = l1->next;
            }
            result = result->next;
        }
        if(!l1){
            result->next = l2;
        }
        if(!l2){
            result->next  = l1;
        }
        result = temp->next;
        delete(temp);
        return result;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = slow;
        ListNode* l1;
        ListNode* l2;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        l1 = sortList(head);
        l2 = sortList(slow);
        return msort(l1,l2);
    }
};