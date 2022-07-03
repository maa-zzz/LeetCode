class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int>ref(n+1,0);//take care of limits
        for(int i=0; i<n; i++){
            if(ref[nums[i]]){
                ans.push_back(nums[i]);
            }
            ref[nums[i]]=1;
        }
        return ans;
    }
};
