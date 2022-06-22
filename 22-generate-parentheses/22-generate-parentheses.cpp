class Solution {
public:
    
    void backtrack(string temp, int open, int close, vector<string>&ans)
    {
        if (open==0 && close==0){
            ans.push_back(temp);
            return;
        }
        if (open<close && open!=0){
            backtrack(temp+"(",open-1,close,ans);
            backtrack(temp+")",open,close-1,ans);
        }
        else if (open==0){
            backtrack(temp+")",open,close-1,ans);
        }
        else if(open==close){
            backtrack (temp+"(",open-1,close,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=n-1;
        int close=n;
        string temp="(";
        vector<string>ans;
        backtrack (temp,open,close,ans);
        return ans;
    }
};