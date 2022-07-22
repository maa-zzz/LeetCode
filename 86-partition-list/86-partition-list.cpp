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
ListNode* partition(ListNode* head, int x) {
    
    ListNode *leftNode=new ListNode(0);
    ListNode *leftHead=leftNode;
    ListNode *rightNode=new ListNode(0);
    ListNode *rightHead=rightNode;
    ListNode *temp=head;
    
    while(temp!=NULL){
        if(temp->val<x){
           leftNode->next=temp;
            leftNode=leftNode->next;
        }
        else{
            rightNode->next=temp;
            rightNode=rightNode->next;  
        }
        temp=temp->next;
    }
    rightNode->next=NULL;
    leftNode->next=rightHead->next;
    
    return leftHead->next;
}
};