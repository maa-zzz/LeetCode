// // Recursion
// // Time Complexity - O(2^N)
// // Space Complexity - O(N)
// class Solution {
// public:
    
//     int solve(vector<int>& prices, int i, int n, int k, bool buy) { // i is index
//         if(i == n || !k){
//             return 0;
//         }
//         if(!buy){ //can buy or not buy
//             return max(solve(prices, i+1, n, k, false), solve(prices, i+1, n, k, true)-prices[i]);
//         }
//         else{  //can sell or not sell, selling completes transaction
//             return max(solve(prices,i+1, n, k, true), solve(prices, i+1, n, k-1, false)+prices[i]);
//         }
//     }
//     int maxProfit(int k, vector<int>& prices) {
//      //1 means buy 0 means sell;
//         return solve(prices, 0, prices.size(), k, false);
//     }
    
// };


// Time complexity - O(n*n*k)
// Space complexity- O(n*k)
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
                cout<<cache[i][j]<<" ";
                tempmax = max(tempmax, cache[i-1][j]-prices[j]);
            }
            cout<<endl;
        }
        return cache[k][n-1];
    }
};