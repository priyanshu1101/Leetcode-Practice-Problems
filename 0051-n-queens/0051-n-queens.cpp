class Solution {
public:
    bool canIPlaceHere(int i,int j,vector<vector<int>> board)
    {
        for(int k=i;k>=0;k--)
        {
            if(board[k][j]==1)
                return false;
        }
        // Left Diagonal
        int k=i,l=j;
        while(k!=-1 && l!=-1)
        {
            if(board[k--][l--]==1)
                return false;
        }
        // Right Diagonal
        k=i,l=j;
        while(k!=-1 && l!=board.size())
        {
            if(board[k--][l++]==1)
                return false;
        }
        return true;
    }
    void nqueenSolution(int i,vector<vector<int>> board,vector<vector<string>> &ans)
    {
        if(i==board.size())
        {
            vector<string> subans;
            for(int k=0;k<board.size();k++)
            {
                string row="";
                for(int l=0;l<board.size();l++)
                {
                    char ch = (board[k][l]==1)? 'Q':'.';
                    row+=ch;
                }
                subans.push_back(row);
            }
            ans.push_back(subans);
            return;
        }
        for(int j=0;j<board.size();j++)
        {
            if(canIPlaceHere(i,j,board))
            {
                board[i][j]=1;
                nqueenSolution(i+1,board,ans);
                board[i][j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        nqueenSolution(0,board,ans);
        return ans;
    }
};