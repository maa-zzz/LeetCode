class Solution {
public:
    void solve(vector<int>& v, vector<int>& ds, vector<vector<int>>& ans, int idx, int target, int k) {
        if (target == 0 and ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        
        for (int i = idx; i < v.size(); i++) {
            if (i > idx and v[i] == v[i - 1]) continue;
            if (v[i] > target) break;
            ds.push_back(v[i]);
            solve(v, ds, ans, i + 1, target - v[i], k);
            ds.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        for (int i = 1; i <= 9; i++) v.push_back(i);
        vector<vector<int>> ans;
        vector<int> ds;
        solve(v, ds, ans, 0, n, k);
        return ans;
    }
};