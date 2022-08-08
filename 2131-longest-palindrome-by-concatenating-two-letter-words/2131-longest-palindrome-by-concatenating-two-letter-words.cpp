class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count = 0;
        map<string,int> m;
        for(auto w:words){
            m[w]+=1;
        }
        bool flag = false;
        for(auto  x: words){
            string w = x;
            reverse(w.begin(), w.end());
            if(w!=x and m[x]>0 and m[w]>0){
                m[x]-=1;
                m[w]-=1;
                count+=4;
            }
            else if(w==x and m[x]>1){
                m[x]-=2;
                count+=4;
            }
            else if(w==x and !flag and m[x]>0){
                m[x]-=1;
                count+=2;
                flag = true;
            }
        }
        return count;
    }
};