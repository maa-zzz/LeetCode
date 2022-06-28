class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length()){
            return false; 
        }
        if(s3==(s1+s2)){
            return true;
        }
        vector<vector<int>> dp(s1.length()+1, vector<int> (s2.length()+1,-1));
        return interleave(s1,s2,s3,0,0,0,dp);
    }
    bool interleave(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp){
        if((i==s1.length()&&j==s2.length()) && (k==s3.length())){
            return true; //base case
        }
        if(dp[i][j]!=-1){
            return dp[i][j]; //look-up
            }
        if(i==s1.length()&& j< s2.length()){
            if(s3[k]==s2[j])
                return dp[i][j] = interleave(s1,s2,s3,i,j+1,k+1,dp); // if s1 string gets empty
            return false;
        }
        if(i<s1.length() && j==s2.length()){
            if(s3[k]==s1[i])
                return dp[i][j] = interleave(s1,s2,s3,i+1,j,k+1,dp); // if s2 string gets empty
            return false;
        }
        if(s3[k]==s2[j] && s3[k]==s1[i]){
            bool op2 = interleave(s1,s2,s3,i+1,j,k+1,dp); //choose from string s1
            bool op1 = interleave(s1,s2,s3,i,j+1,k+1,dp);  //choose from string s2;
            
            return dp[i][j] = op1||op2;
        }
        else if(s3[k]==s2[j]){
            return dp[i][j] = interleave(s1,s2,s3,i,j+1,k+1,dp); // choose from string s2;
        }
        else if(s3[k]==s1[i]){
            return dp[i][j] = interleave(s1,s2,s3,i+1,j,k+1,dp); // choose from string s1;
        }
        return false;
    }
};