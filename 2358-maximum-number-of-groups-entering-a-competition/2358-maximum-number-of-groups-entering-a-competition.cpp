class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 0, total = 0, n = grades.size();
        while (total + k + 1 <= n)
            total += ++k;
        return k;
    }
};
// Sort groups by size,
// so the first group has size at least 1
// so the second group has size at least 2
// kth group has size at least k...