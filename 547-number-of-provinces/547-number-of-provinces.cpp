class Solution {
public:
    
    void dfs(vector<vector<int>>& places, vector<bool>& visited, int i) {
        visited[i] = true;
        for(int j=0; j<visited.size(); j++){
            if(i!=j and places[i][j] and !visited[j]){
                dfs(places, visited, j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        if(n==0){
            return ans;   
        }
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++){
            if(visited[i]==false){
                ans+=1;
                dfs(isConnected, visited, i);
            }
        }
        return ans;
    }
};