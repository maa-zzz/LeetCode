class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;
        dp[stones[0]+1] = {1}; //base case
        for(int i=1; i<n; i++){
            int pos = stones[i];
            for(auto it: dp[pos]){ //will only iterate if theres already a away to come to it
                dp[pos+it].insert(it);
                dp[pos+it+1].insert(it+1); //damn beutiful qn
                dp[pos+it-1].insert(it-1);
            }
        }
        return dp[stones[n-1]].size();
    }
};