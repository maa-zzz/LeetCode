class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        if(tokens.size()==0 or power<tokens[0]){
            return 0;   
        }
        int score = 0;
        int ans = 0;
        int i=0, j=tokens.size()-1;
        while(i<=j){
            if((power-tokens[i])>-1){
                power-=tokens[i];
                score+=1;
                i+=1;
                ans = max(ans,score);
            }
            else{
                power+=tokens[j];
                score-=1;
                j-=1;
            }
        }
        return ans;
    }
};