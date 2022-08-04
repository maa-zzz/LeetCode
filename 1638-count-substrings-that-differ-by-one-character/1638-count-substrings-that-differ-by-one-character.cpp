class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size();
        int n = t.size();
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(s[i]!=t[j]){
                    int left = 1;
                    int right = 1;
                    while(i-left>=0 and j-left>=0 and s[i-left]==t[j-left]) left+=1;
                    while(i+right<m and j+right<n and s[i+right]==t[j+right]) right+=1;
                    ans += left*right;
                }
            }
        }
        return ans;
    }
};