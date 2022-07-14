class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n = nums.size()-1, ans;
        if(n==0){
            return 0;
        }
        if(nums[0]>nums[1]){
                return 0 ;
            }
        if(nums[n]>nums[n-1]){
                return n;
        }
        for(int i = 1; i<n;i++){
            if(nums[i-1]<nums[i] and nums[i+1]<nums[i]){
                ans= i;
                break;
            }  
        }
        return ans;
    }
};