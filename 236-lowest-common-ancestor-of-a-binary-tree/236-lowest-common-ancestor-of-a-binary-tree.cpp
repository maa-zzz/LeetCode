/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //works for n different nodes khi khi'
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL && right == NULL) return NULL; 
        if(left != NULL && right != NULL) return root;  
        return left == NULL ? right : left;
    }
};
// # If looking for me, return myself
//         # else look in left and right child
//         # if both children returned a node, means
//         # both p and q found so parent is LCA
//         # either one of the chidren returned a node, meaning either p or q found on left or right branch.
//         # Example: assuming 'p' found in left child, right child returned 'None'. This means 'q' is
//         # somewhere below node where 'p' was found we dont need to search all the way, 
//         # because in such scenarios, node where 'p' found is LCA