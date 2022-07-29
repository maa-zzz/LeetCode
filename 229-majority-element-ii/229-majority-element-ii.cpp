class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> cache;
        for(auto a: nums){
            cache[a]+=1;
        }
        int n = nums.size()/3;
        for(auto it: cache){
            if(it.second>n) ans.push_back(it.first);
        }
        return ans;
    }
};