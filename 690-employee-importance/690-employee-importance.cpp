class Solution {
public:
    int ans = 0;
    unordered_map<int, Employee*> map;
    
    void solve(int id) {
        ans += map[id]->importance;
		
        for(int x: map[id]->subordinates) {
            solve(x);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for(auto x: employees){
            map[x->id] = x;
        }
        
        solve(id);
        return ans;
    }
};