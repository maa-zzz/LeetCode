class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //track capacity at all points
        map<int,int> mp;
        for(auto a:trips){
            mp[a[1]]+=a[0];
            mp[a[2]]-=a[0];
        }
        for(auto x: mp){
            capacity-=x.second;
            if(capacity<0){
                return false;
            } 
        }
        return true;
    }
};