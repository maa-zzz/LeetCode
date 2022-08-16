class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>> hash;
        int n = s.size();
        for(int i=0; i<n; i++){
            hash[s[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it: hash){
            if(it.second.size()==1) ans = min(ans, it.second[0]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};