class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(),0);
        int temp = 0;
        for(int i=0; i<n; i++){
            if(temp==total-nums[i]){
                return i;
            }
            else{
                temp += nums[i];
                total -= nums[i];
            }
        }
        return -1;
    }
};