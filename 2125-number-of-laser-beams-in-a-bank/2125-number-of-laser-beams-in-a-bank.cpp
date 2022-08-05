class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(auto a:bank){
            int cur = count(a.begin(), a.end(), '1');
            if(cur){
                ans+=prev*cur;
                prev = cur;
            }
        }
        return ans;

    }
};