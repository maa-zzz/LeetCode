class Solution {
public:
    
    int palindrome(string s, int l, int h){            
        int ans=0;
        while(l>=0 and h<s.size() and s[l]==s[h]){
            ans+=1;
            l-=1;
            h+=1;
        }
        return ans;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        int l,h;
        for(int i=0; i<s.size();i++){
            l=h=i;
            ans+=palindrome(s,l,h); //counting odd
            l=i;
            h=i+1;
            ans+=palindrome(s,l,h);//counting even
        }
        return ans;
    }
};