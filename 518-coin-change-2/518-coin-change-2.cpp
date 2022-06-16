#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
	fastIO;
        int dp[amount + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for (const auto & c : coins) 
            for (int i = c; i <= amount; ++i) 
                dp[i] += dp[i - c];    
        
        return dp[amount];
    }
};