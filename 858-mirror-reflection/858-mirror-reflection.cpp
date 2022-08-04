class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2==0 and q%2==0){
            p/=2;
            q/=2;
        }
        return 1-p%2 +q%2;
    }
};
// Given the corner is on the right-hand side.
// If the number of room extension is even (which means m is odd), it means the corner is 1. Otherwise, the corner is 0.
// m is even & n is odd => return 0.
// m is odd & n is odd => return 1.
// m is odd & n is even => return 2.