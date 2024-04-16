class Solution {
public:
    bool canIPlaceHere(vector<string> &board,int i,int j){
        for(int k=0;k<board.size();k++) if(board[i][k]=='Q' || board[k][j]=='Q') return false;
        // Left Diagonal
        int k=i,l=j;
        while(k!=-1 && l!=-1)
        {
            if(board[k--][l--]=='Q')
                return false;
        }
        // Right Diagonal
        k=i,l=j;
        while(k!=-1 && l!=board.size())
        {
            if(board[k--][l++]=='Q')
                return false;
        }
        return true;
    }
    bool nQueen(vector<vector<string>> &ans,vector<string> &board,int i){
        if(i==board.size()){
            ans.push_back(board);
            return false;
        };
        for(int j=0;j<board.size();j++){
            if(canIPlaceHere(board,i,j)){
                board[i][j]='Q';
                bool canWePlaceAhead=nQueen(ans,board,i+1);
                if(canWePlaceAhead) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        nQueen(ans,board,0);
        return ans;
    }
};