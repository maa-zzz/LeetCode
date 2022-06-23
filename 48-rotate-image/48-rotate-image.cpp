class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r=0; r<n/2; r++){
            for(int c=r; c<n-r-1; c++){
                swap(matrix[r][c], matrix[c][n-1-r]);
                swap(matrix[r][c], matrix[n-1-r][n-1-c]);
                swap(matrix[r][c], matrix[n-1-c][r]);
            }
        }
    }
};