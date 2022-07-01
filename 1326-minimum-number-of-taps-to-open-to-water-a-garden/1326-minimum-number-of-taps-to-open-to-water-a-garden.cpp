class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mini = 0;
        int maxi = 0;
        int ans = 0;
        int index = 0;
        while(maxi<n){
            for(int i=index; i<ranges.size(); i++){
                if(i-ranges[i]<=mini and i+ranges[i]>maxi){ //make it a 2 pointer solution// pretty easy to understand
                    maxi = i+ranges[i];
                    index = i;
                }
            }
            if(mini==maxi){
                return -1;
            }
            ans+=1;
            mini = maxi;
        }
        return ans;
    }
};