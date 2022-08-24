class Solution {
public:
    int n=3;
    
    
    bool win(vector<vector<char>>& board, int row, int col, char play) {
        bool didwin = true;
        for(int i=0; i<n; i++){
            if(board[row][i]!=play){
                didwin = false;
                break;
            }
        }
        if(didwin) return true;
        didwin = true;
        for(int i=0; i<n; i++){
            if(board[i][col]!=play){
                didwin = false;
                break;
            }
        }
        if(didwin) return true;
        
        if(row==col){
            didwin = true;
            for(int i=0; i<n; i++){
                if(board[i][i]!=play){
                    didwin = false;
                }
            }
        }
        if(didwin) return true;
        
        if(col==n-row-1){
            didwin = true;
            for(int i=0; i<n; i++){
                if(board[i][n-i-1]!= play){
                    didwin = false;
                }
            }
            if(didwin) return true;
            
        }
        return false;
        
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3,vector<char>(3));
        for(int i=0; i<moves.size(); i++){
            int row = moves[i][0];
            int col = moves[i][1];
            if(i%2==0){
                board[row][col]='X';
                if(win(board, row, col, 'X')) return "A";
            }
            else{
                board[row][col]='O';
                if(win(board, row, col, 'O')) return "B";
            }
        }
        return moves.size()==n*n?"Draw":"Pending";
    }
};