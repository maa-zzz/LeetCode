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
    
    bool solve(TreeNode*root, int* lower, int* upper){
        if(root==NULL){
            return true;
        }
        if(upper and root->val >= *upper){
            return false;
        }
        if(lower and root->val <= *lower){
            return false;
        }
        return solve(root->left, lower, &root->val) and solve(root->right, &root->val, upper); 
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL); //tried using integers, failed 78th test case
                                        //if negative value in root, it will fail
    }
};