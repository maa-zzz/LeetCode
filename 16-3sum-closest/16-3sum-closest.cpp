class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        int closest = nums[0]+nums[1]+nums[2]; //causes in overflow at INT_MAX
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int temp = nums[i]+nums[j]+nums[k];
                if(temp==target){
                    return target;
                }
                if(abs(target-temp)<abs(target-closest)){
                    closest = temp;
                }
                if(temp>target){
                    k-=1;
                }
                else{
                    j+=1;
                }
            }
        }
        return closest;
    }
};