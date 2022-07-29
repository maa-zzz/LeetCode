class Solution {
    public:
    bool isHappy(int n) {
        if (n == 1) return true;
        else if (n == 4) return false;
        else return isHappy(toSumOfSquares(n));
    }
    
    private:
        int toSumOfSquares(int n) {
            int sum = 0;
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            return sum;
    }
};