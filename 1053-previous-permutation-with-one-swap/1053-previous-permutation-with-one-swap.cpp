class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int index = n-2;
        while(index>=0){
            if(A[index]>A[index+1]){
                break;
            }
            index-=1;
        }
        if(index<0)
            return A;
       //find largest element at right of index which is less than A[index];
        int maxi = INT_MIN, pos;
        for(int i=index+1; i<n; i++){
            if(A[i]<A[index] && A[i]>maxi){
                maxi = A[i];
                pos=i;
            }
        }
        
        swap(A[index], A[pos]);
        
        return A;
    }
};