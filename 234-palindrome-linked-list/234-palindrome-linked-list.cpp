class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> start;
        queue<int> end;

        ListNode* curr = head;
        
        while(curr != NULL){ start.push(curr->val); end.push(curr->val); curr = curr->next;}
        
        while(!start.empty() && !end.empty()){
            if(start.top() != end.front()) return false;
            start.pop(); end.pop();
        }
        
        return true;
    }
};
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector <int> v;
//         ListNode* temp = head;
//         while(temp!=NULL){
//             v.push_back(temp->val);
//             temp = temp->next;
//         }
//         int x = 0, y = v.size()-1;
//         while(x<=y){
//             if(v[x]!=v[y]){
//                 return false;
//             }
//             x+=1;
//             y-=1;
//         }
//         return true;
//     }
// };
// class Solution {
// public:
//     ListNode* temp;
//     bool isPalindrome(ListNode* head) {
//         temp = head;
//         return check(head);
//     }
    
//     bool check(ListNode* p) {
//         if (NULL == p) return true;
//         bool isPal = check(p->next) & (temp->val == p->val);
//         temp = temp->next;
//         return isPal;
//     }
// };