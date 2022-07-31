class Solution {
public:
    int ans=0;
    int pathSum(TreeNode* root, int sum) {
        if(root){
            dfs(root,sum);
            pathSum(root->left,sum);
            pathSum(root->right,sum);
        }
        return ans;
    }
    void dfs(TreeNode* root, long sum){
        if(!root)return; //dont use root->val>sum for base as target can be negative
        if(root->val==sum)ans+=1;
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
    }
};