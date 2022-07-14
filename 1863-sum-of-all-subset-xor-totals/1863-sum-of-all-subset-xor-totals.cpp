class Solution {
public:
    int ans = 0;
    
    void btrack(vector<int>& nums, int sum, int i){
        if(i<nums.size()-1){
            btrack(nums, sum, i+1);
            btrack(nums, sum^nums[i], i+1);
            
        }
        else{
            ans+= sum+ (sum^nums[i]);
        }
    }
    
    int subsetXORSum(vector<int>& nums, int i=0) {
        btrack(nums,0,0);
        return ans;
    }
};