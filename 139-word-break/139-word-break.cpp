class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1; i>=0; i--){
            for(auto w:wordDict){
                if(w.size()<=n and w == s.substr(i, w.size())){
                    dp[i] = dp[i+w.size()];
                }
                if(dp[i]){
                    break; //avoid extra runs
                }
            }
        }
        return dp[0];
    }
};