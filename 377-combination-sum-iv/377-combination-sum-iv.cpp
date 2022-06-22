class Solution {
public:
      int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> ans(target + 1);
        ans[0]=1;
        for (int i=0; i <= target; i++) {
            for (int x:nums) {
                if (i>=x){
                    ans[i] += ans[i-x]; //calculate no. of combinations for every sum
                } 
            }
        }
        return ans[target];
    }
};