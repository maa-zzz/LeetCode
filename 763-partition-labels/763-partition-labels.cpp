class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]=i;
        }
        int length = 0;
        int start = -1;
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            length = max(length, mp[s[i]]);
            if(i==length){
                ans.push_back(length-start);
                start = i;
            }
        }
        return ans;
    }
};