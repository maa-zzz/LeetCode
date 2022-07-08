class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curr = prices[1];
        for(int i = 1; i<prices.size(); i++){
            int curr = prices[i]-prices[i-1];
            if (curr>0){
                profit+=curr;
            }
        }
        return profit;
    }
};