class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(abs(nums[i]-i)>1) return false;
            
        }
        return true;
    }
};
// The original order should be [0, 1, 2, 3, 4...], the number i should be on the position i. We just check the offset of each number, if the absolute value is larger than 1, means the number of global inversion must be bigger than local inversion, because a local inversion is a global inversion, but a global one may not be local.