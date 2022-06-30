class Solution {
public:
    void flood_fill(vector<vector<int>>& grid, int i, int j, vector<pair<int,int>>& fill) {
        int n = grid.size();
        int m = grid[0].size(); 
        if(i<0 || j<0 || i>=m || j>=m || grid[i][j]!=1){
            return;
        }
        grid[i][j] = 2;
        fill.push_back(make_pair(i,j));
        flood_fill(grid, i+1, j, fill);
        flood_fill(grid, i, j+1, fill);
        flood_fill(grid, i-1, j, fill);
        flood_fill(grid, i, j-1, fill);
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>> island1;
        vector<pair<int,int>> island2;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]==1) {
                    count+=1;
                    if(count == 1) {
                        flood_fill(grid, i, j, island1);
                    }
                    else if(count == 2) {
                        flood_fill(grid, i, j, island2);
                    }
                }
            }
        }

        //min distance calculation

        int min_dist = INT_MAX;
        for(auto a : island1)
            for(auto b : island2) {
                int dist = abs(a.first-b.first) + abs(a.second-b.second) - 1;
                min_dist = min(min_dist, dist);
            }
                                                //khoobsurat solution
        return min_dist;
    }
};