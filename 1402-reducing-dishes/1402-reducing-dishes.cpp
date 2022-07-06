class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int temp = 0;
        int ans = 0;
        int curr = 0;
        for(int i=n-1; i>=0; i--){
            curr+=temp+satisfaction[i]; //adds factors
            temp+=satisfaction[i];      //repetative addition
            ans = max(ans, curr);       //katai khooobsurat
        }
        return ans;
    }
};