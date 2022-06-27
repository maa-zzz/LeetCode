class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]< b[1];
        });
        int n = intervals.size();
        int ans = 0;
        int temp = intervals[0][1];
        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start>=temp){
                temp = end;
            }
            else{
                ans+=1;
                temp=min(temp, end);
            }
        }
        return ans;
    }
};