/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};
*/
class Solution {
 public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int k = 2; //number of transactions req in the question
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