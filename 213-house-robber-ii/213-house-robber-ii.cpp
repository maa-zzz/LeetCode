class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector <int> dp1(n), dp2(n);
        dp1[1]= nums[0];//considering 1st
        dp2[1]= nums[1];//not considering 1st
        for(int i=2; i<n; i++){
        dp1[i]= max(dp1[i-1], dp1[i-2]+nums[i-1]);
        dp2[i]= max(dp2[i-1], dp2[i-2]+nums[i]);
    }
        return max(dp1[n-1], dp2[n-1]);
    }
};