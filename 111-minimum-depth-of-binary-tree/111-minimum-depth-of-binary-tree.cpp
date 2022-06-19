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
    
    int ans = 0;
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left==0 or right==0){
            return left+right+1;
        }
        return min(left,right)+1;
    }
};