class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==-1) return false;
        if(!arr[start]) return true;
        int left  = start-arr[start];
        int right = start+arr[start];
        arr[start]=-1; //markin it visited;
        return (left>=0 and canReach(arr,left)) or (right<arr.size() and canReach(arr, right));
    }
};