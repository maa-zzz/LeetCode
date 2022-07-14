class Solution {
public:
    

    int ans = 0;
    int dfs(vector<vector<int>>& g, int i, int j) {
          if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] <= 0)  return 0;
          g[i][j] = -g[i][j];
          auto res = max({dfs(g,i+1,j),dfs(g,i,j+1),dfs(g,i-1,j),dfs(g,i,j-1)});
          g[i][j] = -g[i][j];
          return g[i][j] + res;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans,dfs(grid, i, j));
            }
        }
        return ans;
    }
};