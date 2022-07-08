class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[x]);
                x+=1; //x saves the index to reference non zero end
            }
        }
    }
};