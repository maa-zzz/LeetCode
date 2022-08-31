class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26,0);
        int n = s.size();
        for(int i=0; i<n; i++){
            freq[s[i]-'a']+=1;
        }
        int odd = 0;
        int even = 0;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                if(freq[i]%2==0){
                    even+=1;
                }
                else{
                    odd+=1;
                }
            }
        }
        return odd<=k and k<=n ? 1:0;
    }
};