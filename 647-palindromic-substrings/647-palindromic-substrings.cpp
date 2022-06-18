class Solution {
public:
    
    int palindrome(string s, int l, int h, int n){            
        int ans=0;
        while(l>=0 and h<n and s[l]==s[h]){
            ans+=1;
            l-=1;
            h+=1;
        }
        return ans;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        int l,h;
        int n = s.size();
        for(int i=0; i<n;i++){
            l=h=i;
            ans+=palindrome(s,l,h,n); //counting odd
            l=i;
            h=i+1;
            ans+=palindrome(s,l,h,n);//counting even
        }
        return ans;
    }
};