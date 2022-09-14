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
    unordered_map<int, int> mp;
    int ans;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        mp[root->val]+=1;
        if(!root->left and !root->right){
            int odd = 0;
            for(auto a:mp){
                if(a.second%2)odd+=1;
            }
            if(odd<2) ans+=1;
        }
        dfs(root->left);
        dfs(root->right);
        mp[root->val]-=1;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};