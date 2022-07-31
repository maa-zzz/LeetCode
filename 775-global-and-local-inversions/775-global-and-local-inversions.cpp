class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==i or (i>=1 and i==nums[i-1]) or (i<n-1 and i==nums[i+1])) continue;
            else return false;
            
        }
        return true;
    }
};