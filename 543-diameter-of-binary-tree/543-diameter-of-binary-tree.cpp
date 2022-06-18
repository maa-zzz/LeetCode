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
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left), height(root->right))+1;
    }
    
    int diameter(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int h1 = height(root->left)+height(root->right);
        int h2 = diameter(root->left);
        int h3 = diameter(root->right);
        return max(h1, max(h2,h3));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
    }
};