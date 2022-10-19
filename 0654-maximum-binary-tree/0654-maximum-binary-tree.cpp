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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s { new TreeNode(nums[0]) };
        for (int i = 1; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            auto it = upper_bound(s.rbegin(), s.rend(), cur,
                [](const TreeNode* a, const TreeNode* b) { return a->val < b->val; });
            if (it != s.rend()) 
                (*it)->right = cur;
            if (it != s.rbegin()) 
                cur->left = *next(it, -1);
            s.resize(distance(it, s.rend()));
            s.push_back(cur);
        }
        return s.front();
    }
};