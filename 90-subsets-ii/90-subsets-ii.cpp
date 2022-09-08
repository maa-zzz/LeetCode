class Solution {
public:
    
    vector<vector<int>> ans;
    
    void btrack(vector<int>& nums, vector<int>& temp, int index){
        ans.push_back(temp);
        for(int i=index; i<nums.size(); i++){
            if(i==index or nums[i]!=nums[i-1]){
                temp.push_back(nums[i]);
                btrack(nums, temp, i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        btrack(nums,temp, 0);
        return ans;
    }
};