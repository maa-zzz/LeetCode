class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int med = n/2;
        int ct = 0 ;
        for(int i=0; i<n; i++){
            ct+= abs(nums[med]-nums[i]);
        }
        return ct;
    }
};