class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
            return;
        }
        if(board[i][j] == 'O'){
            board[i][j] = '#';
            dfs(board, i+1, j);
            dfs(board, i, j-1);
            dfs(board, i-1, j);
            dfs(board, i, j+1);
        }
        else{
            return;
        }
        
    } 
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                dfs(board, i, 0);
                dfs(board, i, n-1);
                dfs(board, 0, j);
                dfs(board, m-1, j);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' and i>0 and j>0 and i<m-1 and j<n-1){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};