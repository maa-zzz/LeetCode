class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i]; //multiplying by digits behind it
            res[n-1-i]*=fromLast;
            fromLast*=nums[n-1-i]; //multiplying by digits infront of it
        }
        return res;
    }
};
//brilliant thinking whoever thought of this