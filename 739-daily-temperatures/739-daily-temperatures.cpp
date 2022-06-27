class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-2; i>=0; i--){
            int j = i+1;
            while(j<n and temperatures[j]<=temperatures[i]){
                if(ans[j]>0){
                    j = ans[j]+j;
                }
                else{
                    j = n;
                }
            }
            if (j<n){
                ans[i]=j-i;
            }
        }
        return ans;
    }
};