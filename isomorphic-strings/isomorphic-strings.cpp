class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char a[256]={0};
        char b[256]={0};
        for(int i=0; i<s.size(); i++){
            if(a[s[i]]!=b[t[i]]){
                return false;
            }
            a[s[i]]=i+1;
            b[t[i]]=i+1;//case of aa and ab;
        }
        return true;
    }
};