class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a']+=1;
            b[t[i]-'a']+=1;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            ans+=abs(a[i]-b[i]);
        }
        return ans/2; // divide coz ans counts twice (2 char replaces at a time)
    }
};