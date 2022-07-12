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
    vector<vector<int>>ans;
    
    void levelordertraversal(TreeNode* root, int depth){
        if(root==NULL){
            return;
        }
        if(ans.size()==depth){
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(root->val);
        levelordertraversal(root->left, depth+1);
        levelordertraversal(root->right, depth+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelordertraversal(root,0);
        for(int i=1; i<ans.size(); i+=2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};