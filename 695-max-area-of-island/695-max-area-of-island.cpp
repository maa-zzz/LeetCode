class Solution {
public:
    
    int dfs(vector<vector<int>>&grid, int i, int j) {
        if(i>=0 and i<grid.size() and j>=0 and j<grid[0].size() and grid[i][j]==1){
            grid[i][j] = 0;
            return 1+dfs(grid, i+1,j)+dfs(grid, i, j+1)+dfs(grid,i-1, j)+dfs(grid,i,j-1);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int temp = dfs(grid,i,j);
                    area = max(area, temp);
                }
            }
        }
        return area;
    }
};