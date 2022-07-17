class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> counts(26,0);
        for(const auto& c: tiles){
            counts[c-'A']+=1;
        }
        int ans = 0;
        btrack(counts, ans);
        return ans;
    }
    
    void btrack(vector<int>& counts, int& ans){
        for(int i =0; i<26; i++){
            if(counts[i]){
                counts[i]-=1;
                ans+=1;
                btrack(counts, ans);
                counts[i]+=1;
            }
        }
    }
};