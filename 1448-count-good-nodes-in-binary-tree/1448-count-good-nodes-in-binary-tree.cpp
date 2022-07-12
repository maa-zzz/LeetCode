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
    void counter(TreeNode* root, int maxi) {
        if(root){
            if(root->val >= maxi){
                ans+=1;
            }
            maxi = max(maxi, root->val);
            counter(root->left, maxi);
            counter(root->right, maxi);
        }
    }
    
    int goodNodes(TreeNode* root) {
        counter(root, root->val);
        return ans;
    }
};