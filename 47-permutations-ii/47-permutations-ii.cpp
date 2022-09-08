class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms;
        permute(nums, 0, perms);
        return perms;
    }
private:
    void permute(vector<int> nums, int start, vector<vector<int>>& perms) {
        if (start == nums.size()) {
            perms.push_back(nums);
        } 
        else {
            for (int i=start; i<nums.size(); i++) {
                if ((i == start) || (nums[i] != nums[start])) {
                    swap(nums[i], nums[start]);
                    permute(nums,start+1,perms);
                }
            }
        }
    }
};