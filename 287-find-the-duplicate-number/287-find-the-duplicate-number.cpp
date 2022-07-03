class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        vector<int>ref(n,0);
        for(int i=0; i<n; i++){
            if(ref[nums[i]]){
                ans = nums[i];
                break;
            }
            ref[nums[i]]=1;
        }
        return ans;
    }
};