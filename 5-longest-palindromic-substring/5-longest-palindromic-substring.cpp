class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int length = 0;
            for(int i=0; i<s.size(); i++){
                //odd length
                int l=i, r=i;
                while(l>=0 and r<=s.size() and s[l]==s[r]){
                    if((r-l+1)>length){
                        string temp;
                        for(int i=l; i<=r; i++){
                            temp+=s[i];   
                        }
                        ans = temp;
                        length=r-l+1;
                    }
                    l-=1;
                    r+=1;
                }
                //even length
                l=i, r=i+1;
               while(l>=0 and r<=s.size() and s[l]==s[r]){
                    if((r-l+1)>length){
                        string temp;
                        for(int i=l; i<=r; i++){
                            temp+=s[i];   
                        }
                        ans=temp;
                        length=r-l+1;
                    }
                    l-=1;
                    r+=1;
                }
            }
        return ans;
    }
};