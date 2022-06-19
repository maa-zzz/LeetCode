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
    //global variable ans vector
    vector<vector<int>> ans; 
    
    void levelordertraversal(TreeNode *root, int height){
        //base case
        if(root==NULL){
            return;
        }
        if(ans.size()==height){
            ans.push_back(vector<int>());
        }
        ans[height].push_back(root->val);
        levelordertraversal(root->left, height+1);
        levelordertraversal(root->right, height+1);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelordertraversal(root,0);
        return ans;
    }
};