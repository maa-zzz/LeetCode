class Solution {
public:
    
    static bool comp(vector<int>&a, vector<int>&b) {
        return a[0]-a[1]<b[0]-b[1];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        int n = costs.size();
        sort(costs.begin(), costs.end(), comp);
        for(int i=0; i<n/2; i++){
            ans+=costs[i][0];
            ans+=costs[n-i-1][1];
        }
        return ans;
        
    }
};