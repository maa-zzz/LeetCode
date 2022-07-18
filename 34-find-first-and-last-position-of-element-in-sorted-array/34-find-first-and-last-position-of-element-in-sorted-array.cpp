class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans;
        int n = nums.size(), low = 0 , high = n-1, x = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                x = mid;
            }
            nums[mid]>=target ? high = mid-1 : low = mid +1;
        }
        ans.push_back(x);
        low = max(0,x); high  = n-1; x = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                x = mid;
            }
            nums[mid]>target ? high = mid-1: low = mid+1;
        }
        ans.push_back(x);
        return ans;
    }    
};
         