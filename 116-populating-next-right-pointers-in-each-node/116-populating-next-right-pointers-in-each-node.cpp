/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*> values;
        values.push(root);
        while(!values.empty()){
            int sz = values.size();
            vector<Node*>ans;
            while(sz--){
                Node* temp = values.front();
                values.pop();
                ans.push_back(temp);
                if(temp->left!=NULL){
                    values.push(temp->left);
                }
                if(temp->right!=NULL){
                    values.push(temp->right);
                }
                for(int i =0; i<ans.size(); i++){
                    if(i==ans.size()-1){
                        ans[i]->next = NULL;
                    }
                    else{
                        ans[i]->next = ans[i+1];
                    }
                }
            }
        }
        return root;
    }
};