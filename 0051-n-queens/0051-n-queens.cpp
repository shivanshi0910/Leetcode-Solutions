class Solution {
public:
    bool isValid(int r, int c , vector<string> board , int n) {
        int dr = r;
        int dc = c;
        //upper left diagonal 
        while(dr>=0 && dc>=0) {
            if(board[dr][dc]=='Q') return false;
            dr--;
            dc--;
        }
        dr = r;
        dc = c;
        //left direction
        while(dc >= 0) {
            if(board[dr][dc]=='Q') return false;
            dc--;
        }
        //lower right diagonal
        while(r<n && c>=0) {
            if(board[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans , vector<string>& board , int c , int n) {
        if(c == n) {
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++) {
            if(board[r][c]=='.') {
                if(isValid(r,c,board,n)) {
                    board[r][c]='Q';
                    solve(ans, board , c+1 , n);
                    board[r][c]='.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0 ; i<n ; i++) board[i]=s;
        solve(ans , board , 0 , n);
        return ans;
    }
};