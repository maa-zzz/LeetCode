class Solution {
public:
        bool rec(vector <char> &s, int st) {
            if (st >= s.size()/2) return true;        
            if (s[st] == s[s.size() - 1 - st]) //beutiful
                return rec(s, st + 1);
            else 
                return false;
        }
    
    public:
        bool isPalindrome(string s) {
            vector <char> str;
            for (auto &i : s) {
                i = tolower(i); 
                if (ispunct(i) or i == ' ') 
                    continue;
                str.push_back(i);
            }
            return rec(str, 0);
    }
};