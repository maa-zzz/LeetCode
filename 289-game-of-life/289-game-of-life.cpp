class Solution {
public:
    
    //2 - newly alive
    //3- newly dead
    
    int getneigh(vector<vector<int>>& matrix, int i, int j, int m, int n){
        int ans = 0;
        if(i>0){
            if(matrix[i-1][j]==1 or matrix[i-1][j]==3) ans+=1;
        }
        if(j>0){
            if(matrix[i][j-1]==1 or matrix[i][j-1]==3) ans+=1;
        }
        if(i<m-1){
            if(matrix[i+1][j]==1 or matrix[i+1][j]==3) ans+=1;
        }
        if(j<n-1){
            if(matrix[i][j+1]==1 or matrix[i][j+1]==3) ans+=1;
        }
        if(i and j){
            if(matrix[i-1][j-1]==1 or matrix[i-1][j-1]==3) ans+=1;
        }
        if(i<m-1 and j<n-1){
            if(matrix[i+1][j+1]==1 or matrix[i+1][j+1]==3) ans+=1;
        }
        if(i>0 and j<n-1){
            if(matrix[i-1][j+1]==1 or matrix[i-1][j+1]==3) ans+=1;
        }
        if(i<m-1 and j>0){
            if(matrix[i+1][j-1]==1 or matrix[i+1][j-1]==3) ans+=1;
        }
        return ans;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int nbour = getneigh(board, i, j, m, n);
                if(board[i][j]==0 and nbour==3){
                    board[i][j]=2;
                }
                else if(board[i][j]==1){
                    if(nbour<2 or nbour>3){
                        board[i][j]=3;
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==2){
                    board[i][j]=1;
                }
                else if(board[i][j]==3){
                    board[i][j]=0;
                }
            }
        }
    }
};