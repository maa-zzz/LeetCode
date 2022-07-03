class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        int i =0;
        while(i<=x and i<n){
            x = max(x, i+nums[i]);//x and i move along, x tracks the max we can reach, i tracks pos. x >= i//
            i+=1;
        }
        if(x>=n-1){
            return true;
        }
        return false;
    }
};