class Solution {
public:
    int ans = INT_MAX;
    
    void solve(int start, vector<int>& nums, vector<int>& v,int k){
        if(start==nums.size()){
            int maxm = *max_element(v.begin(), v.end());
            ans = min(ans, maxm);
            return;
        }
        for(int i=0; i<k; i++){
            v[i]+=nums[start];
            solve(start+1, nums,v,k);
            v[i]-=nums[start];
        }

    }
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> v(k,0);
        solve(0,cookies,v,k);
        return ans;
    }
};