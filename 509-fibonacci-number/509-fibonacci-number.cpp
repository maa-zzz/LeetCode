class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        int c = 0;
        for ( int i=0; i<n; i++){
            c = b;
            b = a+b;
            a = c;
        }
        return a;
    }
};