/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool solve(TreeNode* p, TreeNode* q){
        if(p==NULL or q==NULL){
            return p==q;
        }
        return(p->val == q->val and solve(p->left, q->left) and solve(p->right,q->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL){                              //read which function is called at the last stage
            return true;
        }
        if(root==NULL){
            return false;
        }
        if (solve(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
    
};