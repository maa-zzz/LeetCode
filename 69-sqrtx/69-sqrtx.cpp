class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int l = 1, r = INT_MAX;
        while(true){
            int mid = l+ (r-l)/2;
            if(mid>x/mid){
                r = mid -1;
                continue;
            }
            else if(mid +1 > x/(mid+1)){
                return mid;
            }
            l = mid+1;
        }
    }
};