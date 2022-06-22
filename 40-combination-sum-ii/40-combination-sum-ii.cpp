class Solution {
public:
    
    void combination(vector<int>& candidates, int target, vector<int> currcomb, int currindex, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(currcomb);
            return;
        }
        else{
            for(int i=currindex; i<candidates.size(); i++){
                if(candidates[i]>target){
                    return;
                }
                if(i and candidates[i]==candidates[i-1] and i>currindex){
                    continue;  //for no duplicatesss(initialilly sorted hence)
                }
                currcomb.push_back(candidates[i]);
                combination(candidates, target-candidates[i], currcomb,i+1, ans);
                currcomb.pop_back();
            }          
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int> currcomb;
        sort(candidates.begin(), candidates.end());
        combination(candidates, target, currcomb,0, ans);
        return ans;
    }
};