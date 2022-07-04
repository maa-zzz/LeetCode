class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, mid = 0, high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid], nums[l]);
                l+=1;
                mid+=1;
            }
            else if(nums[mid]==1){
                mid+=1;
            }
            else{
                swap(nums[mid], nums[high]);
                high-=1;
            }
        }
    }
};