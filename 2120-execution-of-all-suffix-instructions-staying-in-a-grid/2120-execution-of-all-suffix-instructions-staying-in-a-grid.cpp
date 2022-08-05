class Solution {
public:
    
    int dfs(int x, int y, string& s, int n, int i) {
        if(x<0 or y<0 or x>=n or y>=n or i>=s.size()) return 0;
        int temp = 0;
        if(y>0 and s[i]=='L') temp += 1+dfs(x,y-1,s,n,i+1);
        else if(x>0 and s[i]=='U') temp += 1+dfs(x-1,y,s,n,i+1);
        else if(x<n-1 and s[i]=='D') temp += 1+dfs(x+1,y,s,n,i+1);
        else if(y<n-1 and s[i]=='R') temp += 1+dfs(x,y+1,s,n,i+1);
        return temp;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans(s.size(),0);
        for(int i=0; i<s.size(); i++){
            ans[i]=dfs(startPos[0], startPos[1],s,n,i);
        }
        return ans;
    }
};