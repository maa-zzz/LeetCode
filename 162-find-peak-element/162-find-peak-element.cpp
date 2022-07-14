/*
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
*/
class Solution {
    public:
    int findPeakElement(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        while(low<high){
            int mid1 = low + (high-low)/2;
            int mid2 = mid1+1;
            if(nums[mid1]<nums[mid2]){
                low = mid2;
            }
            else{
                high = mid1;
            }
        }
        return low;
    }
};