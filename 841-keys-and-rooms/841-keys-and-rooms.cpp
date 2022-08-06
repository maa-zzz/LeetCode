class Solution {
public:
    
    void dfs(vector<vector<int>> &graph, int i, vector<bool> &vis){
        vis[i] = true;
        for(int j=0; j<graph[i].size(); j++){
            if(!vis[graph[i][j]]){
                dfs(graph, graph[i][j], vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0,vis);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
        
    }
};