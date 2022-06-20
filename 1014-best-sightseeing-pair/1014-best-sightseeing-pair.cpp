class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
      int ans = 0;
      int temp = nums[0];
        for(int i = 1; i<nums.size(); i++){
            ans = max(ans, nums[i]-i + temp);
            temp = max(temp, nums[i] + i);///keep track of the maximum and iterate further easy peasy boi
        }
        return ans;
    }
};