class Solution {
public: 
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {                                   TreeNode* res;   //Define res node for storing result
        queue<TreeNode*> q; //and queue of node for storing nodes of the level
        if(cloned)  q.push(cloned); //if node is not null put it into the queue
        //iterate until queue gets empty
        while(!q.empty()){
            int size = q.size(); 
            //iterate over each level of the tree
            for(int i=0; i<size; i++){
                TreeNode* node = q.front(); q.pop();
                //if node value is equal to the target value store it into the res
                if(node->val == target->val)
                    res = node;
                    
                //if left is not null, store it into the queue
                if(node->left) q.push(node->left);
                //if right is not null, store it into the queue
                if(node->right) q.push(node->right);
            }
        }
        return res; 
    }
};