class Solution {
    bool dfsRec(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited, vector<vector<int>>& graph, vector<bool> &present_cycle){
        visited[node] = true;
        dfsVisited[node] = true;
        
        vector<int>data = graph[node];
        for(auto x: data){
            if(!visited[x]){
                if(dfsRec(x, visited, dfsVisited, graph, present_cycle)){
                    return present_cycle[node] = true;
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return present_cycle[node] = true;
            }
        }
        
        dfsVisited[node] = false;
        return false;
    }
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        
        int n = graph.size();
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        vector<bool> present_cycle(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfsRec(i, visited, dfsVisited,graph, present_cycle);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!present_cycle[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};