class Solution {
public:
    long long integerBreak(long long n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        if(n == 5) return 6;
        if(n == 6) return 9;
        return 3 * integerBreak(n - 3);
    }
};
/*For any integer p strictly greater than 4, it has the property such that 3 * (p - 3) > p, which means breaking it into two integers 3 and p - 3 makes the product larger while keeping the sum unchanged. If p - 3 is still greater than 4, we should break it again into 3 and p - 6, giving 3 * 3 * (p - 6), and so on, until we cannot break it (less than or equal to 4) anymore.

For integer 4, breaking it into 2 * 2 or keeping it as 4 does not change its contribution to the product.
We cannot have more than two 4s, because 2 * 3 * 3 > 4 * 4. We cannot have more than three 2s because 3 * 3 > 2 * 2 * 2.
*/