class Solution {
public:
    int numSquares(int n) {
        vector<int> cache(n+1,INT_MAX);
        cache[0]=0;
        int count = 1;
        while(count*count <= n) {
        int sq = count*count;
        for(int i = sq; i < n+1; i++) {
            cache[i] = min(cache[i-sq] + 1,cache[i]);
        }
        count++;
    }
    return cache[n];
    }
};