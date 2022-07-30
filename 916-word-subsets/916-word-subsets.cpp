class Solution {
public:
    
    vector<int> frequency(string s) {
        vector<int> freq(26,0);
        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']+=1;
        }
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq2(26,0);
        for(auto &x: words2){
            vector<int> freq = frequency(x);
            for(int i=0; i<26; i++){
                freq2[i] = max(freq[i], freq2[i]);
            }
        }
        for(auto &x: words1){
            vector<int> freq = frequency(x);
            bool flag = true;
            for(int i=0; i<26; i++){
                if(freq[i]<freq2[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(x);
        }
        return ans;
    }
};