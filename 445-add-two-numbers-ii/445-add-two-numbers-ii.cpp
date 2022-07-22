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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        while(l1){
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int m = v1.size(), n = v2.size();
        int sum = 0, carry = 0;
        ListNode *head = NULL, *p = NULL;
        for(int i=m-1, j=n-1; i>=0 or j>=0 or carry>0; i--,j--){
            sum = carry;
            if(i>=0){
                sum+=v1[i];
            }
            if(j>=0){
                sum+=v2[j];
            }
            carry = sum/10;
            p = new ListNode(sum%10);
            p->next = head;
            head = p;
        }
        return head;
    }
};