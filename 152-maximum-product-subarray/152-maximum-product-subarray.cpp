class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int minn = 1, maxx = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                minn =1;
                maxx=1;
            }
            int temp1 = maxx*nums[i];
            int temp2 = minn*nums[i];
            minn = min(min(temp2, temp1), nums[i]);
            maxx = max(max(temp2, temp1), nums[i]);
            ans = max(max(ans, minn), maxx);
        }
        return ans;
    }
};