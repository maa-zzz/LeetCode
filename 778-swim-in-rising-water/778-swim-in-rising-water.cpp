class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1) return grid[0][0];
        int ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n,0));
        visited[0][0] = 1;
        vector<int> dir({-1,0,1,0,-1});
        pq.push({ans,0,0});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            for(int i=0; i<4; i++){
                int r = cur[1]+dir[i];
                int c = cur[2]+dir[i+1];
                if(r>=0 and r<n and c>=0 and c<n and visited[r][c]==0){
                    if(r==n-1 and c==n-1) return ans;
                    pq.push({grid[r][c],r,c});
                    visited[r][c]=1;
                }
            }
        }
        return -1;
    }
};