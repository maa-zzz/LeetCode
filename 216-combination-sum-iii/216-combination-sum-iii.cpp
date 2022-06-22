class Solution {
public:
    void solve(vector<int>& v, vector<int>& temp, vector<vector<int>>& ans, int idx, int target, int k) {
        if (target == 0 and temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = idx; i < v.size(); i++) {
            if (i > idx and v[i] == v[i - 1]) continue;
            if (v[i] > target) break;
            temp.push_back(v[i]);
            solve(v, temp, ans, i+1, target - v[i], k);
            temp.pop_back();
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