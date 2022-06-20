class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char,pair<int,int>> map;
        int n = s.size();
        for(int i=0; i<n; i++){
            map[s[i]].first +=1;
            map[s[i]].second = i;
        }
        for(auto [c,p]:map){
            if(p.first==1){
                n = min(n, p.second);
            }
        }
        return n==s.size() ? -1: n;
    }
};

