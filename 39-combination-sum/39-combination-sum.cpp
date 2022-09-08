class Solution {
public:
    
    vector<vector<int>> ans;
    
    void btrack(vector<int>& nums, vector<int>& ccombo, int target, int index){
        if(!target){
            ans.push_back(ccombo);
        }
        for(int i=index; i<nums.size(); i++){
            if(nums[i]>target){
                return;
            }
            ccombo.push_back(nums[i]);
            btrack(nums, ccombo, target-nums[i],i);
            ccombo.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        btrack(candidates, temp,target, 0);
        return ans;
    }
};