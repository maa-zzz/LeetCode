class Solution {
public:
    vector<int>ans;
    
    // void dfs(long long i, int n, int k, vector<int>&ans){
    //     if(n==0){
    //         ans.push_back(i);
    //     }    
    //     int temp = i%10;
    //     if(temp+k<=9){
    //         dfs(i*10+temp+k, n-1, k, ans);
    //     }
    //     if(k!=0 and temp>=k){
    //         dfs(i*10+temp-k, n-1,k,ans);
    //     }
    // }
    void dfs(int num, int n, int K, vector<int> &res) {
  if (n == 0) 
      res.push_back(num);
  else {
      int dig = num % 10;
      if (dig + K <= 9)
          dfs(num * 10 + dig + K, n - 1, K, res);
      if (K != 0 && dig >= K)
          dfs(num * 10 + dig - K, n - 1, K, res);
    }
}
vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> res;
    for (auto num = 1; num <= 9; ++num) 
        dfs(num, N - 1, K, res);
    return res;
}
        
    // vector<int> numsSameConsecDiff(int n, int k) {
    //     vector<int>ans;
    //     for(int i=1; i<10; i++){
    //         dfs(i,n-1,k, ans);
    //     }
    //     return ans;
    // }
};