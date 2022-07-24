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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();
        ListNode* tempo = odd;
        ListNode* tempe = even;
        ListNode* temp = head;
        int x = 0;
        while(temp!=NULL){
            if(x%2==0){
                tempo->next = temp;
                tempo = tempo->next;
            }
            else{
                tempe->next = temp;
                tempe = tempe->next;
            }
            temp = temp->next;
            x+=1;
        }
        tempe->next = NULL;
        tempo->next = even->next;
        return odd->next;
    }
        
};