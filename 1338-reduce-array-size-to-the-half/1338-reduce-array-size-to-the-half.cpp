class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> map;
        priority_queue<int> pq;
        for(auto a: arr) map[a]+=1;
        for(auto a:map) pq.push(a.second);
        int k = n;
        int ans = 0;
        while(k-pq.top()>n/2){
            k-=pq.top();
            pq.pop();
            ans+=1;
        }
        ans += 1; 
        return ans;
    }
};