class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ref(n,0);
        for(int i=0; i<edges.size(); i++){
            ref[edges[i][1]]=1;
        }
        vector<int> ans;
        for(int i=0; i<ref.size(); i++){
            if(!ref[i]) ans.push_back(i);
        }
        return ans;
    }
};