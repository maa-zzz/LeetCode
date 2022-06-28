class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(auto& s:strs){
            int zer = count(begin(s), end(s), '0');
            int one = s.size()-zer;
            for(int i=m; i>=zer; i--){
                for(int j=n; j>=one; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zer][j-one]+1);
                }
            }
        }
        return dp[m][n];
    }
};