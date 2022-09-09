class Solution {
public:
    
    int ans = 0;
    
    void pdrome(string&s, int i, int j){
        if(i<0 or j>=s.size()){
            return;
        }
        if(s[i]==s[j]){
            ans+=1;
            pdrome(s,i-1, j+1);
        }
        else{
            return;
        }
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            pdrome(s,i,i);
            pdrome(s,i,i+1);
        }
        return ans;
    }
};