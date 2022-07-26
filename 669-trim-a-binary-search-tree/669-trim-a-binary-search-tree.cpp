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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return root;
        if(root->val > high) return trimBST(root->left, low, high);
        if(root->val < low) return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
//When \text{node.val > high}node.val > high, we know that the trimmed binary tree must occur to the left of the node. Similarly, when \text{node.val < low}node.val < low, the trimmed binary tree occurs to the right of the node. Otherwise, we will trim both sides of the tree.