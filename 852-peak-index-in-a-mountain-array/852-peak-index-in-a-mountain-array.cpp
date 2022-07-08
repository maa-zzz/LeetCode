class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int h = arr.size();            
        int l = 0;
        while(1){
            int mid = l + (h-l)/2;
            if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1]){
                return mid;
            }
            else{
                if(arr[mid-1]<arr[mid]){
                    l = mid+1;
                }
                else{
                    h = mid;
                }
            }
        }
    }
};