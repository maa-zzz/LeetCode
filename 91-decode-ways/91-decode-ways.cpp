class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> ans(n+1,0);
        ans[n]=1;
        for(int i =n-1; i>=0; i--){
            if(s[i]=='0'){
                ans[i]=0;
            }
            else{
                ans[i]=ans[i+1];
                if(i<n-1 and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7'))){ //traverse backwards
                    ans[i]+=ans[i+2];
                }
            }
        }
        return ans[0];
    }
};