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
    map<int,vector<vector<int>>>mp; //coloumn and value;
    
    void build(TreeNode*root, int col, int depth){
        if(root==NULL){
            return;
        }
        mp[col].push_back({depth, root->val});
        build(root->left, col-1 , depth+1);
        build(root->right, col+1, depth+1);
        
    }
    
    vector<vector<int>> ans;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        build(root, 0,0);
        for(auto& a:mp){
            sort(a.second.begin(), a.second.end());
            vector<int>temp;
            for(int i=0;i<a.second.size(); i++){
                temp.push_back(a.second[i][1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};