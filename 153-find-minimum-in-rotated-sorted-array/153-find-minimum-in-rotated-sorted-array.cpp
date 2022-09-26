class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, h = nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]>=nums[0]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        if(l==nums.size()){
            return nums[0];
        }
        else{
            return nums[l];
        }
    }
};