class Solution {
public:
    
    void fill(vector<vector<int>>& grid, int i, int j) {
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]){
            return;
        }
        grid[i][j]=1;
        fill(grid,i+1,j);
        fill(grid,i,j+1);
        fill(grid,i,j-1);
        fill(grid,i-1,j);
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i*j==0 or i==m-1 or j==n-1){
                    if(!grid[i][j]){
                        fill(grid, i, j);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!grid[i][j]){
                    ans+=1;
                    fill(grid, i, j);
                }
            }
        }
        return ans;
    }
};