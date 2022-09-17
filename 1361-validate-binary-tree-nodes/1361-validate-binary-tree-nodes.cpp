class Solution {
public:
    
    int countnodes(vector<int>&l, vector<int>&r, int root){
        if(root==-1) return 0;
        return 1+countnodes(l,r,l[root])+countnodes(l,r,r[root]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = -1;
        vector<int> indegree(n,0);
        for(int i=0; i<leftChild.size(); i++){
            if(leftChild[i]!=-1 and indegree[leftChild[i]]++==1) return false;
            else if(rightChild[i]!=-1 and indegree[rightChild[i]]++==1) return false;
        }
        for(int i=0; i<leftChild.size(); i++){
            if(!indegree[i]){
                if(root==-1){
                    root = i;
                }
                else{
                    return false;
                }
            }
        }
        if(root==-1){
            return false;
        }
        else{
            return countnodes(leftChild, rightChild,root)==n;
        }
    }
};