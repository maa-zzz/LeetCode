class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);  
        while(--n){
            for(int i=3; i>=0; i--){
                dp[i] += dp[i+1]; //last one is always one.. else just add on prev if it were n-1
            }
        }
        return accumulate(dp.begin(), dp.end(),0);
    }
};