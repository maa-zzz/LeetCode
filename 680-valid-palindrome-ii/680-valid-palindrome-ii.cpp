class Solution {
public:
    
    bool solve(string&s, int l, int r, int ct) {
        if(ct>1){
            return false;
        }
        while(l<r){
            if(s[l]!=s[r]){
                return solve(s,l+1,r,ct+1) or solve(s,l,r-1,ct+1);
            }
            l+=1;
            r-=1;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int l=0, r=s.size()-1;
        return solve(s,l,r,0);
    }
};