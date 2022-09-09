class Solution {
public:
    
    static bool cmp(vector<int>&a, vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), cmp);
        int ans = 0;
        int maxi = INT_MIN;
        for(int i=prop.size()-1; i>=0; i--){
            if(prop[i][1]<maxi){
                ans+=1;
            }
            maxi = max(maxi, prop[i][1]);
        }
        return ans;
    }
};