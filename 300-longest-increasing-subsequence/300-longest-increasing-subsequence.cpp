class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i]<nums[j]){
                    ans[i]=max(ans[i], ans[j]+1);
                }
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};
// Time Complexity : O(N2)
// Space Complexity : O(N)