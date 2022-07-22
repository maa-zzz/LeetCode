/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int countListLength(ListNode *head) {
        if(!head) return 0;
        int count = 0;
        ListNode *temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
    
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {       
        int count1 = countListLength(headA);
        int count2 = countListLength(headB);
        ListNode* ptr1 = headA, *ptr2 = headB;
        
        if(count1 > count2) {
            for(int i=0; i<(count1 - count2); i++) {
                   ptr1 = ptr1->next;
            }
        } 
        else if( count1 < count2) {
            for(int i=0; i<(count2 - count1); i++) {
                   ptr2 = ptr2->next;
            }
        }
        
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    }
};