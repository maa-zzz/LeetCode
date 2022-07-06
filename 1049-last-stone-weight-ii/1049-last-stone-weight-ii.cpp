class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //1.Mark true for all the possible subset sum
        //2.Check for the minimum difference out of all the marked 
        //elements
        int n = stones.size();
        int sum = 0; 
        for (int i = 0; i < n; i++)
            sum += stones[i];
     
        // Create an array to store results of subproblems
        bool t[n + 1][sum + 1];
     
        // Initialize first column as true. 0 sum is possible 
        // with all elements.
        for (int i = 0; i <= n; i++)
            t[i][0] = true;
     
        // Initialize top row, except dp[0][0], as false. With
        // 0 elements, no other sum except 0 is possible
        for (int i = 1; i <= sum; i++)
            t[0][i] = false;
     
        // Fill the partition table in bottom up manner
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= sum; j++){
                if (stones[i - 1] <= j)
                    t[i][j] = t[i - 1][j - stones[i - 1]] || t[i- 1][j];
                else
                     t[i][j] = t[i - 1][j];
             }
        }
      
        // Initialize difference of two sums. 
        int diff = INT_MAX;
         
        // Find the largest j such that dp[n][j]
        // is true where j loops from sum/2 t0 0
        for (int j = sum/2; j >= 0; j--){
            //Find the minimum difference
            if (t[n][j] == true)
              diff = min(diff, sum - 2*j);
        }
        
        return diff;
        
    }
};