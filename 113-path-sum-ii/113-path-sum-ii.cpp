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
    
    void summer(TreeNode *root, int target, vector<vector<int>> &ans, vector<int> temp) {
        if(root == NULL){
            return;
        }
        if(!root->right and !root->left){
            if(root->val==target){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);
        summer(root->left, target-root->val, ans, temp);
        summer(root->right, target-root->val, ans, temp);
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        summer(root, targetSum, ans, temp);
        return ans;
    }
};