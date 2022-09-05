/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> ans;
    
    void levelordertraversal(Node* root, int level){ //its node not treenode idiot
        if(root==NULL) return;
        if(ans.size()==level){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        for(Node* child : root->children){
            levelordertraversal(child,level+1);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        levelordertraversal(root,0);
        return ans;
    }
};