class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {        
        vector<string> ans;
        for(auto& w : words) 
            if(match(w, p)) ans.push_back(w);
        return ans;
    }
    bool match(string& w1, string& w2) {
        unordered_map<char, char> A, B;
        for(int i = 0; i < size(w1); i++) 
            if( (A.count(w1[i]) && A[w1[i]] != w2[i]) || 
                (B.count(w2[i]) && B[w2[i]] != w1[i]) ) 
                return false; 
            else
                A[w1[i]] = w2[i],
                B[w2[i]] = w1[i];
        return true;
    }
    };