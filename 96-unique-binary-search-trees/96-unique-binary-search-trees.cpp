class Solution {
public:
    int numTrees(int n) {
        long long int x = 1;
        for (int i=1; i <=n; i++) {
            x *= (4*i-2);
            x /= (i+1);
        }
        return x;
        
    }
};