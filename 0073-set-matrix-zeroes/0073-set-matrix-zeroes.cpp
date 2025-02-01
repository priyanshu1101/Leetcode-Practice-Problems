class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colsize=matrix[0].size();
        int rowsize=matrix.size();
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<colsize;j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=0;k<rowsize;k++)
                    {
                        if(matrix[k][j]!=0)
                        matrix[k][j]=-1;
                    }
                    for(int k=0;k<colsize;k++)
                    {
                        if(matrix[i][k]!=0)
                        matrix[i][k]=-1;
                    }
                }
            }
        }
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==-1)
                    matrix[i][j]=0;
            }
        }
    }
};