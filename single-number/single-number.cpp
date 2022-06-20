class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[n-1];
        for(int i=0; i<n-1; i+=2){
            if(nums[i]!=nums[i+1]){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};