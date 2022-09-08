class Solution {
public:
    
    vector<vector<int>> ans;
    
    void btrack(vector<int>& temp, int k , int n, int index){
        if(temp.size()==k and !n){
            ans.push_back(temp);
        }
        for(int i=index; i<=9; i++){
            temp.push_back(i);
            btrack(temp, k, n-i, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        btrack(temp, k, n, 1);
        return ans;
    }
};