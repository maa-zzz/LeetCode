class Solution {
public:
    const int MOD = 1e9+7;
    int numTilings(int n) {
        
        vector<long long int>dp(1000,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        dp[4]=11;
        for(int i=4; i<=n; i++){
            dp[i] = (dp[i-1]*2);
            dp[i] += dp[i-3];
            if(dp[i]>MOD){
                dp[i]%=MOD;
            }
            
        }
        return dp[n];
    }
};