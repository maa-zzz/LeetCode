class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        // int k = 2; //number of transactions req in the question
        vector<vector<int>> cache(k+1, vector<int>(n,0));
        for(int i=1; i<=k; i++){
            int tempmax = cache[i-1][0]-prices[0];
            for(int j=1; j<n; j++){
                cache[i][j] = max(cache[i][j-1], tempmax+prices[j]);
                tempmax = max(tempmax, cache[i-1][j]-prices[j]);
            }
        }
        return cache[k][n-1];
    }
};