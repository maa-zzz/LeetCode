class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3,0);
        for (auto &s : triplets){
            if(s[0]<=target[0] and s[1]<=target[1] and s[2]<=target[2]){
                ans[0] = max(ans[0], s[0]);
                ans[1] = max(ans[1], s[1]);
                ans[2] = max(ans[2], s[2]);
            }
        }
        return ans==target;
    }
};