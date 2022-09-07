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
    void find_the_string(TreeNode* term, TreeNode* root, string& str){
    if(term==NULL){
        str=str+")";
        return;
    }
    
    int num=term->val;
    string c=to_string(num);
    str=str+c+"(";
    
    find_the_string(term->left, root, str);
    
    if(term->left==NULL && term->right==NULL){
        str.pop_back();
        str.pop_back();
    }
    
    str=str+"(";
    
    find_the_string(term->right, root, str);
    
    if(term->right==NULL){
        str.pop_back();
        str.pop_back();
    }
    
    if(term!=root){
        str=str+")";
    }
    
}

    string tree2str(TreeNode* root) {
        string str;
        find_the_string(root, root, str);
        return str;
    }
};