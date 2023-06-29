class Solution {
public:
    bool isValid(char ch , int i , int j , vector<vector<char>>& board) {
        for(int p = 0 ; p < 9 ; p++) {
            if(board[i][p] == ch) return false;
            if(board[p][j] == ch) return false;
            if(board[3*(i/3)+p/3][3*(j/3)+p%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 9 ; j++) {
                if(board[i][j] == '.' ) {
                    for(char ch = '1' ; ch <= '9' ; ch++) {
                        if(isValid(ch,i,j,board)) {
                            board[i][j] = ch;
                            if(solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};