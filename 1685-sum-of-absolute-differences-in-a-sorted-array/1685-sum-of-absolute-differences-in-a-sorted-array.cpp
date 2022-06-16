class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);        
        vector <int> v;
        v.push_back(sum - nums[0]*(n));
        int x,y;
        for(int i=1; i<n;i++){
            x = v[i-1];
            y = nums[i]-nums [i-1];
            if(y==0){
                v.push_back(x);
                continue;
            }
            v.push_back(x+y*i-y*(n-i));
        }
       
        return v;
            
    }
};