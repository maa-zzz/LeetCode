class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        int n=nums.size();
        sum/=2;
        vector<bool>dp(sum+1,false);
        dp[0]=true;
        for(int i =0; i<n; i++){
            for(int j=sum; j>0; j--){
                if(j>=nums[i] and dp[j-nums[i]]){
                    dp[j]=true;
                }
            }
        }
        return dp[sum];
    }
};