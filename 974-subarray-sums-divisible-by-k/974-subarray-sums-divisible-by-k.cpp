class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : A) {
            //Now to the main count we are adding the no. of sub arrays 
			// that we have already seen that they have remainder ==  rem
            prefix = (prefix + a % K + K) % K;
            res += count[prefix]++;
        }
        return res;
    }
};
// we find subarray sum from from i to j by 
// SUM[i-1] - SUM[j]
// if it has to be div by K then 
// SUM[i-1] - SUM[j] = K*something
// OR (SUM[i-1] - SUM[j]) %K  = (K*something) %K = 0
// OR SUM[i-1] % k == SUM[j]%k
// So basically for any SUM[i] if its remainder is same as remainder of any other SUM[ some index] then their sum % k == 0