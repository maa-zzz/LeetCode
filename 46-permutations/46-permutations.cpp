class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }
        for(int x:nums){
            if(find(temp.begin(),temp.end(),x) == temp.end()){
                temp.push_back(x);
                backtrack(ans, temp, nums);
                temp.pop_back();
            }
        }
    }    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;     
        vector<int> temp;
        
        backtrack(ans, temp, nums);
        return ans;
    }
};