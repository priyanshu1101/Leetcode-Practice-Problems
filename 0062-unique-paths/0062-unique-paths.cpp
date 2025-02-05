class Solution {
public:
    int ansFinder(vector<vector<int>> &dp, int m, int n) {
        if (dp[m][n] != -1){
            cout<<m<<" "<<n<<" "<<dp[m][n]<<endl;
            return dp[m][n];
        }
        if (m == 1 && n == 1) {
            return 1;
        }
        if (m == 0 || n == 0)
            return 0;
        int value = ansFinder(dp,m - 1, n) + ansFinder(dp,m, n - 1);
        dp[m][n] = value;
        return value;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(100, vector<int>(100, -1));
        return ansFinder(dp, m, n);
    }
};