class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>steps(n,INT_MAX);
        steps[0]=0;
        for(int i=0; i<n; i++){
            for(int j=min(n-1,i+nums[i]); j>i; j--){
                if(steps[j]>steps[i]+1){
                    steps[j]=steps[i]+1;
                }
                else{
                    break;
                }
            }
        }
        return steps[n-1];
    }
};