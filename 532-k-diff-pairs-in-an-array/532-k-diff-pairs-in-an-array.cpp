class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]+=1;
        }
        int ans = 0;
        for(auto m:mp){
            if(k==0){    
                if(m.second>1)
                    ans+=1;
            }
            else if(mp.find(m.first+k)!=mp.end()){
                ans+=1;
            }
        }
        return ans;
    }
};