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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if (list1 == NULL) {
            return list2 ; 
        }
        else if(list2 == NULL){
            return list1 ; 
        }
        ListNode *p = list1 ; 
        ListNode *q = list2 ;
        ListNode *r = NULL ;         
        ListNode *list3 = NULL ;       
        if(p->val <= q->val){
            list3 = p ; 
            p = p->next ; 
            list3->next = NULL ; 
            r = list3 ; 
        }
        else if ( p->val > q->val){
            list3 = q ; 
            q = q->next ; 
            list3->next = NULL ; 
            r = list3 ;
        }      
        while (p && q){
            if(p->val < q->val) {
                r->next = p ;
                r = p ;
                p = p->next ;
                r->next = NULL ;
            }
            else{
                r->next = q ;
                r = q ;
                q = q->next ; 
                r->next = NULL ;
            }
        }
        if (p) {
            r->next = p ;
        }
        if (q){
            r->next = q ;
        }
        return list3 ;  
    } 
};