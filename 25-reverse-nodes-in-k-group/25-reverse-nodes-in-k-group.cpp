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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i=0; i<k; i++){
            if(!cursor){
                return head;
            }
            cursor = cursor->next; //cursor is just for the base case, in the recursion function
        }
        ListNode* far = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int ct = 0;
        while(curr and ct<k){
            far = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = far;
            ct+=1;
        }
        if(far){
            head->next = reverseKGroup(far, k);
        }
        return prev;
    }
};