class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int temp = target-nums[i];
            if(hash.find(temp)!=hash.end()){
                ans.push_back(hash[temp]);
                ans.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return ans;
    }
};