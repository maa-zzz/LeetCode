class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for(auto &a: adjacentPairs){
            mp[a[0]].push_back(a[1]);
            mp[a[1]].push_back(a[0]);      
        }
        vector<int> ans;
        for(auto &a: mp){
            if(a.second.size()==1) {
                ans.push_back(a.first);
                ans.push_back(a.second[0]);
                break; //find head
            }
        }
        while(ans.size()<adjacentPairs.size()+1){
            auto tail = ans.back(), prev = ans[ans.size()-2];
            auto &next = mp[tail];
            if(next[0]!=prev){ //check if the value is on the left or not
                ans.push_back(next[0]);
            }
            else{
                ans.push_back(next[1]);
            }
        }
        return ans;
    }
};