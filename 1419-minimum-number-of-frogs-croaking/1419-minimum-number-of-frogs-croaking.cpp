class Solution {
 public:
    int minNumberOfFrogs(string s) {
        int c = 0 , r = 0 , o = 0 ,a = 0 ,k = 0,ans  = 0;
        for(int i = 0 ; i  < s.size() ; i++)
        {
            if(s[i] == 'c'){
                if (k == 0) c += 1;
                else c += 1, k -= 1;
            }
            else if(s[i] == 'r'){
                if (c == 0) return -1;
                else c -= 1, r += 1;    
            }
            else if(s[i] == 'o'){
                if (r == 0) return -1;
                else r -= 1, o += 1;
            }
            else if(s[i] == 'a'){
                if (o == 0) return -1;
                else o -= 1, a += 1;
            }
            else if(s[i] == 'k'){
                if (a == 0) return -1;
                else a -= 1, k += 1;
            }
            ans = max(max(max(c, r), o), max(max(ans, a), k));            
        }
        if(c or r or o or a)    return -1;
        return ans;
    }
};