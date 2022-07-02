class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> hash(60,0);
        int ans = 0;
        for(int i=0; i<time.size(); i++){
            int modu = time[i]%60;;
            if(modu==0){
                ans+=hash[0];
            }
            else{
                ans+=hash[60-modu];
            }
            hash[modu]+=1;
        }
        return ans;
    }
};