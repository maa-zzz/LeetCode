class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int size=s.size(),fc=-1,bc=-1,plate=0;
        vector<int>f(size,0),b(size,0),cnt(size,0);
        for(int i=0;i<size;i++){
           if(s[i]=='*')
               plate++;
            cnt[i]=plate;
            if(s[i]=='|')
                fc=i;
            f[i]=fc;
        }
        for(int i=size-1;i>=0;i--){
            if(s[i]=='|')
                bc=i;
            b[i]=bc;
        }
        vector<int>ans;
        for(auto & i:q){
            int p1=b[i[0]],p2=f[i[1]];
            if( (p1!=-1 && p2!=-1) &&  p1>= i[0] && p1<=i[1] &&p2>= i[0] && p2<=i[1] )
                ans.push_back(cnt[p2]-cnt[p1]);
            else
                 ans.push_back(0);
        }
        return ans;
    }
};
// Let's say query is [left,right].
// So in simple words we have to findposition(p1)(left<=p1<=right) of candle which is closest to left and position(p2)(left<=p2<=right) of candle which is closest to right.
// After finding p1 and p2 we have to find number of plates between these two positions.
// So for finding p1 and p2 use forward and backward array and store position of latest candle while iteratig over string in forward and backward direction respectively.
// For number of plates between any two position we can use prefix array.