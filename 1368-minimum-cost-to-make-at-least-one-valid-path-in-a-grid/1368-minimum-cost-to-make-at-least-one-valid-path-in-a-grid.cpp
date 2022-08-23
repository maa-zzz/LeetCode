class Solution {
public:
    
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp, int cost, queue<pair<int, int>>& q){
        int m = grid.size(), n=grid[0].size();
        if(min(r,c)<0 or r>=m or c>=n or dp[r][c]!=INT_MAX) return;
        dp[r][c] = cost;
        q.push(make_pair(r,c));
        int nextDir = grid[r][c]-1;
        dfs(grid, r + dir[nextDir][0], c + dir[nextDir][1], dp, cost, q);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cost = 0;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        dfs(grid, 0,0,dp,cost,q);
        while(!q.empty()){
            cost+=1;
            int s = q.size();
            for(int i=0; i<s; i++){
                pair<int,int> p = q.front();
                int r = p.first, c = p.second;
                q.pop();
                for(int j=0; j<4; j++){
                    dfs(grid, r+dir[j][0], c+dir[j][1], dp, cost, q);
                }
            }
        }
        return dp[m-1][n-1];
    }
};