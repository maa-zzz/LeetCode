class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        bool flag  = false;
        for(auto c:s){
            mp[c]+=1;
        }
        int ans = 0;
        int oddmax = 0;
        for(auto b: mp){
            if(b.second%2==0){
                ans+=b.second;
            }
            else{
                ans+=b.second-1;
                flag = true;
            }
        }
        return flag?ans+1:ans;
    }
};