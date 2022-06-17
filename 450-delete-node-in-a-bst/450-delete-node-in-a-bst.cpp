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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(root->val > key){
                root->left=deleteNode(root->left, key);
            }
            else if(root->val < key){
                root->right=deleteNode(root->right, key);
            }
            else{
                if(root->left==NULL and root->right==NULL){
                    return NULL;
                }
                if(root->left==NULL or root->right==NULL){
                    return root->left?root->left:root->right; //replace the node with its child
                }
                TreeNode* temp = root->left; //replace the deleted note with the max of its left child
                while(temp->right != NULL){ //delete the max from the left
                    temp=temp->right;
                }     
                root->val = temp->val;                            
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
};