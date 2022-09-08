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
            if(i==index or nums[i]!=nums[i-1]){
                ccombo.push_back(nums[i]);
                btrack(nums, ccombo, target-nums[i],i+1);
                ccombo.pop_back();
            }
            
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        btrack(candidates, temp,target, 0);
        return ans;
    }
};