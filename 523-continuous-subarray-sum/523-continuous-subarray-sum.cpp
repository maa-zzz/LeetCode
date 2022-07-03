class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2){
            return false;
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        int runningsum=0;
        for(int i=0; i<nums.size(); i++){
            runningsum+=nums[i];
            if(k!=0){
                runningsum = runningsum%k;
            }
            if(mp.find(runningsum)!=mp.end()){
                if(i-mp[runningsum]>1){
                    return true;
                }
            }
            else{
                mp[runningsum]=i;
            }
        }
        return false;
    }
};