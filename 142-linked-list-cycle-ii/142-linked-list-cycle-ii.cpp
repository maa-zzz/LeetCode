/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next == NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                while(slow!=entry){
                    slow = slow->next; //2(L1+L2) = L1+L2+x+L2,2L1 + 2L2 = L1+2L2+x,=> x = L1
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
// L1 is defined as the distance between the head point and entry point
// L2 is defined as the distance between the entry point and the meeting point