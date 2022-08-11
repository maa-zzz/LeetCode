class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int start = 1;
        int last = 1;
        vector<int> ans(n,1);
        for(int i=0; i<n; i++){
            ans[i]*=start;
            start*=nums[i];
            ans[n-i-1]*=last;
            last*=nums[n-i-1];
        }
        return ans;
    };
//         int n=nums.size();
//         int fromBegin=1;
//         int fromLast=1;
//         vector<int> res(n,1);
        
//         for(int i=0;i<n;i++){
//             res[i]*=fromBegin;
//             fromBegin*=nums[i]; //multiplying by digits behind it
//             res[n-1-i]*=fromLast;
//             fromLast*=nums[n-1-i]; //multiplying by digits infront of it
//         }
//         return res;
//     }
};
//brilliant thinking whoever thought of this