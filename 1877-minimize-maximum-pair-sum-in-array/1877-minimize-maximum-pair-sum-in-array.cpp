class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int l=0, r=nums.size()-1;
        while(l<r){
            ans = max(ans, nums[l]+nums[r]);
            l+=1;
            r-=1;
        }
        return ans;
    }
};