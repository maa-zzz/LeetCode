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
#define null nullptr
class Solution {
public:
    int i = 0;
    TreeNode* help(vector<int>& pre, vector<int>& post,int start,int end){
        //BAse Case
        if(start>end) return null;
        if(i>=pre.size()) return null;
        int j =-1;
        for(int k = start;k<=end;k++)
            if(pre[i]==post[k]){
                j=k;
                break;
            }
        if(j==-1) return null;
        i++;
        TreeNode* root = new TreeNode(post[j]);
        TreeNode* l = help(pre,post,start,j-1);
        root->left=l;
        TreeNode* r = help(pre,post,start,j-1);
        root->right=r;
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return help(pre,post,0,post.size()-1);
    }
};