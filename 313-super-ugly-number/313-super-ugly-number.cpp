class Solution {
public:
      int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);

        int i = 0;
        long long curr = 1;
        while (i < n) {
          curr = pq.top();
          pq.pop();
          ++i;
          for (int x : primes)
            pq.push(x * curr);

          while (!pq.empty() && pq.top() == curr)
            pq.pop();
        }

        return curr;
      }
};