class Solution {
public:
    int minInsertions(string s) {
        int m = s.size(); //hard solved by self
        vector<vector<int>> dp(m+1, vector<int>(m+1,0));
        string t = s;
        reverse(t.begin(), t.end());
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m-dp[m][m];
    }
};