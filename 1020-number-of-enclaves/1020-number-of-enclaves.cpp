class Solution {
public:
    
    void dfs(vector<vector<int>>&g, int i, int j) {
        if(min(i,j)<0 or i>=g.size() or j>=g[0].size() or g[i][j]==0){
            return;
        }
        g[i][j] = 0;
        dfs(g,i-1,j);
        dfs(g,i+1,j);
        dfs(g,i,j-1);
        dfs(g,i,j+1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (i * j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1) dfs(grid, i, j);
                // dfs(grid,i,0);
                // dfs(grid,i,n-1);
                // dfs(grid,0,j);
                // dfs(grid,m,j-1);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};