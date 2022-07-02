class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size()<3){
            return ans;
        }
        for(int i=0; i<nums.size()-2; i++){
            if(i==0 or i>0 and nums[i]!=nums[i-1]){
                int start = i+1;
                int end = nums.size()-1;
                int sum = 0-nums[i];
                while(start<end){
                    if(nums[start]+nums[end]==sum){
                    ans.push_back({nums[i],nums[start], nums[end]});
    
                    while(start<end and nums[start]==nums[start+1]){
                        start +=1;
                    }
                    while(start<end and nums[end]== nums[end-1]){
                        end -=1;
                    }
                    start+=1;
                    end-=1;
                    }

                else if(nums[start]+nums[end]<sum){
                    start +=1;
                }
                else{
                    end-=1;
                }
            }
            }
        }
    return ans;
}
};