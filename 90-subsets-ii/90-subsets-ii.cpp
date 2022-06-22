class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int>&temp, vector<int>& nums, int index){
        ans.push_back(temp);
        for(int i=index; i<nums.size(); i++){
            if(i>index and nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(ans, temp, nums, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, nums, 0);
        return ans;
        
    }
};