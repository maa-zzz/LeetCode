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
/*Use BFS to do a level order traversal,
add childrens to the bfs queue,
until we met the first empty node.

For a complete binary tree,
there should not be any node after we met an empty one.
    */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int i = 0;
        while (i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }
        while (i < bfs.size() && !bfs[i])
            i++;
        return i == bfs.size();
    }
};